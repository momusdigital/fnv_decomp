#!/bin/bash
# Fetch the two commits the check compares into a fresh clone, as data: nothing in them is run.
#
# usage: fetch.sh resolve WORK   decide the commits from the event (GitHub's environment), print base=/head= lines
#        fetch.sh get WORK BASE HEAD
# A pull request is checked as GitHub's test merge with main (refs/pull/N/merge) against its first parent, so the
# difference is exactly what merging would bring. A push to main is checked against the commit before it.
set -euo pipefail
mode=$1; work=$2
git init -q "$work"
git -C "$work" remote add origin "https://github.com/$GITHUB_REPOSITORY.git"
fetch() { git -C "$work" fetch -q --no-tags --depth="$1" origin "${@:2}"; }
if [ "$mode" = get ]; then
  fetch 1 "$3" "$4"
  exit
fi
case $GITHUB_EVENT_NAME in
  pull_request_target)
    for try in $(seq 1 12); do
      # asking for the pull request makes GitHub (re)compute its test merge
      mergeable=$(gh api "repos/$GITHUB_REPOSITORY/pulls/$PR_NUMBER" --jq .mergeable 2>/dev/null || echo null)
      if [ "$mergeable" = false ]; then
        echo "::error::This pull request conflicts with main: update it from main first."; exit 1
      fi
      if fetch 2 "+refs/pull/$PR_NUMBER/merge:refs/check/merge" 2>/dev/null &&
         [ "$(git -C "$work" rev-parse refs/check/merge^2)" = "$PR_HEAD" ]; then
        head=$(git -C "$work" rev-parse refs/check/merge); base=$(git -C "$work" rev-parse refs/check/merge^1)
        break
      fi
      sleep 10
    done
    [ -n "${head:-}" ] || { echo "::error::GitHub has not produced the test merge of this pull request yet."; exit 1; };;
  push)
    head=$GITHUB_SHA; base=$PUSH_BEFORE
    if [ -z "$base" ] || [ "$base" = 0000000000000000000000000000000000000000 ]; then
      fetch 2 "$head"; base=$(git -C "$work" rev-parse "$head^1")
    fi;;
  workflow_dispatch)
    head=${INPUT_HEAD:-$GITHUB_SHA}; base=${INPUT_BASE:-}
    fetch 2 "$head"; head=$(git -C "$work" rev-parse FETCH_HEAD)
    if [ -n "$base" ]; then fetch 1 "$base"; base=$(git -C "$work" rev-parse FETCH_HEAD)
    else base=$(git -C "$work" rev-parse "$head^1"); fi;;
  *) echo "::error::unexpected event $GITHUB_EVENT_NAME"; exit 1;;
esac
fetch 1 "$base" "$head"
echo "base=$(git -C "$work" rev-parse "$base^{commit}")"
echo "head=$(git -C "$work" rev-parse "$head^{commit}")"
