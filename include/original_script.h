#ifndef FNV_ORIGINAL_SCRIPT_H
#define FNV_ORIGINAL_SCRIPT_H

#include "ScriptFunctionInfo.h"

// Original command lookup and decoding entry points shared by all script units.
ScriptFunctionInfo* ScriptCompiler_GetFunctionDef(SCRIPT_OUTPUT output);
int Warning(const char* format, ...);
bool ExtractArgs(const ScriptParameter* parameters, const char* data, unsigned int* offset, TESObjectREFR* reference,
                 TESObjectREFR* container, Script* script, ScriptLocals* locals, ...);
#endif
