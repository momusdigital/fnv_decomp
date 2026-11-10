#pragma once

#include <string>

class BxString;

class FutBinaryFileC
{
public:
    virtual ~FutBinaryFileC();
    virtual bool vf01(std::string name);
    virtual bool vf02(std::string path);
    virtual void vf03(int a, int b, int c);
    virtual void vf04(int a, int b, int c);

    FutBinaryFileC(std::string signature);
    template <class String>
    FutBinaryFileC(String signature);

    char CheckSignature(const std::string& path);
    bool CheckSignature(const BxString& path);
    template <class String>
    char CheckSignature(const String& path);

    char isCorrectFileId(const std::string& path);
    bool isCorrectFileId(const BxString& path);
    bool isCorrectFileId(const char* name);
    template <class String>
    char isCorrectFileId(const String& path);

    std::string signature;
    std::string path;
    unsigned int unk3c;
};
