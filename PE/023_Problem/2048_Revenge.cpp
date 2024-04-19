#include <iostream>
#include <assert.h>
#include <cmath>
#include <math.h>

#define TEST 0

enum EFunction : size_t
{
    F_Function01,
    F_Function02,
    F_Function03,
    F_Function04,
    F_Function05,
    F_Function06,
    F_Function07,
    F_Function08,
    F_Function09,
    End
};

#if TEST
#include <vector>

std::vector<unsigned char> GValidationInputString[EFunction::End];

void __fastcall Function01(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function02(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function03(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function04(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function05(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function06(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function07(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function08(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall Function09(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);

bool CheckGameClear();
#endif

void __fastcall ReverseFunction01(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction02(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction03(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction04(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction05(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction06(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction07(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction08(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);
void __fastcall ReverseFunction09(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString);

constexpr size_t GINPUT_STRING_COUNT = 36;

constexpr size_t GVAR_0X7FF666EF4140_COUNT = 256;
constexpr int GVAR_0X7FF666EF4140[GVAR_0X7FF666EF4140_COUNT] =
{
    0xF4, 0x4A, 0x43, 0xC6, 0x95, 0x7F, 0xAA, 0x6C,
    0x32, 0xAB, 0xE6, 0x9B, 0xCC, 0xA3, 0xE4, 0x96,
    0x00, 0x4E, 0xC8, 0x04, 0x69, 0xFB, 0xC4, 0x90,
    0xB1, 0xC7, 0xD5, 0x2E, 0x0D, 0xCF, 0x3B, 0xD6,
    0x54, 0x22, 0xD4, 0xF7, 0x56, 0xFD, 0x27, 0x67,
    0xA2, 0xE9, 0xA4, 0x47, 0x01, 0x6D, 0xDE, 0x3C,
    0xBF, 0x74, 0xB5, 0x48, 0x9C, 0xB6, 0x7A, 0x4D,
    0xB8, 0x25, 0x4F, 0xD3, 0x8F, 0x58, 0x78, 0x62,
    0x39, 0xAE, 0x07, 0xFA, 0x7C, 0x7E, 0x71, 0x30,
    0xF9, 0xBA, 0xFC, 0xF8, 0x9A, 0xA7, 0x2C, 0xF0,
    0x0E, 0xDC, 0x28, 0x0B, 0xD7, 0xCD, 0x8B, 0x36,
    0x85, 0xC3, 0x7D, 0x75, 0x68, 0x14, 0xEA, 0x1B,
    0x12, 0x41, 0x4B, 0x9E, 0xA5, 0xD0, 0xCE, 0x35,
    0x44, 0x0F, 0x11, 0x42, 0xD2, 0xDA, 0x0C, 0xB3,
    0x49, 0x1D, 0x89, 0xD9, 0xEC, 0x61, 0x45, 0xB9,
    0xE0, 0x6E, 0xBE, 0x26, 0xAC, 0x73, 0x72, 0xC0,
    0x40, 0xBC, 0xA9, 0x77, 0xB4, 0x88, 0x46, 0x06,
    0x08, 0x86, 0x5D, 0x23, 0x09, 0xF2, 0xDF, 0x9F,
    0x20, 0xD8, 0x3D, 0xF3, 0x1E, 0x1C, 0xD1, 0x50,
    0x6B, 0xE3, 0xE1, 0xE8, 0x15, 0x0A, 0xDD, 0x2A,
    0xE2, 0x2D, 0xED, 0xCA, 0x76, 0x2F, 0xC9, 0x24,
    0x81, 0x59, 0x8A, 0x82, 0x95, 0x65, 0x5C, 0x1F,
    0x93, 0x64, 0x5F, 0x5E, 0xF1, 0xC2, 0xB2, 0x87,
    0xBB, 0x4C, 0x21, 0x6F, 0x13, 0xEB, 0x8D, 0x2B,
    0xA1, 0x99, 0xBD, 0xF5, 0x33, 0x19, 0x1A, 0x8E,
    0x17, 0x97, 0x29, 0xE7, 0xB0, 0x98, 0xEF, 0x34,
    0xE5, 0x91, 0x38, 0x94, 0x55, 0xA6, 0xEE, 0x79,
    0x51, 0xFF, 0x03, 0x66, 0xA8, 0x92, 0x3A, 0x57,
    0x83, 0xA0, 0x18, 0xB7, 0x02, 0x63, 0x7B, 0x5B,
    0x70, 0x31, 0x10, 0x5A, 0x37, 0x8C, 0x16, 0x3F,
    0x53, 0xF6, 0xDB, 0xAD, 0xC5, 0x60, 0xCB, 0x84,
    0xC1, 0x3E, 0xAF, 0x52, 0x9D, 0x80, 0xFE, 0x6A
};

constexpr size_t GVAR_0X7FF666EF4540_COUNT = GINPUT_STRING_COUNT;
int GVAR_0X7FF666EF4540[GVAR_0X7FF666EF4540_COUNT] =
{
    0x02, 0x06, 0x02, 0x00, 0x00, 0x01, 0x09, 0x04, 0x02, 0x01,
    0x00, 0x00, 0x03, 0x05, 0x03, 0x02, 0x09, 0x06, 0x06, 0x03,
    0x04, 0x02, 0x07, 0x08, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07,
    0x00, 0x01, 0x09, 0x08, 0x03, 0x01, 
};

constexpr size_t GVAR_0X7FF666EF9CE0_COUNT = GINPUT_STRING_COUNT;
int GVAR_0X7FF666EF9CE0[GVAR_0X7FF666EF9CE0_COUNT] = { 0, };

const size_t GMAX_ROW = static_cast<size_t>(std::sqrt(GINPUT_STRING_COUNT));
const size_t GMAX_CUL = GMAX_ROW;

int main()
{
    using FunctionType = void(__fastcall*)(const char*, __int64, __int64, unsigned char*);

    constexpr const char* UnknownPtr = "";
    constexpr __int64 UnknownValue = 0x2F;

    unsigned char InputString[GINPUT_STRING_COUNT + 1] = { '\0', };

#if TEST
    for (size_t ValidationInputStringIdx = 0; ValidationInputStringIdx < EFunction::End; ++ValidationInputStringIdx)
    {
        GValidationInputString[ValidationInputStringIdx].resize(GINPUT_STRING_COUNT + 1);
    }

    constexpr FunctionType FUNCTION_ARRAY[EFunction::End] =
    {
        Function01, Function02, Function03,
        Function04, Function05, Function06,
        Function07, Function08, Function09
    };

    ::memset(InputString, 'a', GINPUT_STRING_COUNT);

    for (size_t FunctionArrayIdx = 0; FunctionArrayIdx < EFunction::End; ++FunctionArrayIdx)
    {
        FUNCTION_ARRAY[FunctionArrayIdx](UnknownPtr, UnknownValue, NULL, InputString);
    }
#endif

    constexpr FunctionType REVERSE_FUNCTION_ARRAY[EFunction::End] =
    {
        ReverseFunction01, ReverseFunction02, ReverseFunction03,
        ReverseFunction04, ReverseFunction05, ReverseFunction06,
        ReverseFunction07, ReverseFunction08, ReverseFunction09
    };

    for (int FunctionArrayIdx = static_cast<int>(EFunction::End) - 1; FunctionArrayIdx >= 0; --FunctionArrayIdx)
    {
        REVERSE_FUNCTION_ARRAY[FunctionArrayIdx](UnknownPtr, UnknownValue, NULL, InputString);
    }

    std::cout << InputString << '\n';

    return 0;
}

#if TEST
void __fastcall Function01(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    const size_t InputStringPtrLength = ::strlen((const char*)InputString);

    for (size_t InputStringIdx = 0; InputStringIdx < InputStringPtrLength; ++InputStringIdx)
    {
        InputString[InputStringIdx] = InputString[InputStringIdx];
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function01][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function02(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        InputString[InputStringIdx] = (InputString[InputStringIdx] << 1) & 0xAA | (InputString[InputStringIdx] >> 1) & 0x55;
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function02][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function03(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        InputString[InputStringIdx] = GVAR_0X7FF666EF4140[InputString[InputStringIdx]];
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function03][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function04(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            InputString[GMAX_ROW * Row + Cul] ^= (GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul] & 0xFF);
        }
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function04][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function05(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t Count = 0; Count < GINPUT_STRING_COUNT; ++Count)
    {
        const char ShiftCount = ((char)(Count + 1) % GINPUT_STRING_COUNT);

        if (((int)(InputString[Count % GINPUT_STRING_COUNT] >> ShiftCount) & 1) != ((int)(InputString[(Count + 2) % GINPUT_STRING_COUNT] >> ShiftCount) & 1))
        {
            InputString[Count % GINPUT_STRING_COUNT] ^= 1 << ((char)(Count + 1) % GINPUT_STRING_COUNT);
            InputString[(Count + 2) % GINPUT_STRING_COUNT] ^= 1 << ShiftCount;
        }
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function05][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function06(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = Row + 1; Cul < GMAX_CUL; ++Cul)
        {
            std::swap(InputString[GMAX_ROW * Row + Cul], InputString[GMAX_ROW * Cul + Row]);
        }
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function06][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function07(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul] *= GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul];
        }
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function07][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function08(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            if (Row == Cul)
            {
                for (size_t K = 0; K < Row; ++K)
                {
                    std::swap(GVAR_0X7FF666EF4540[GMAX_ROW * Row + K], GVAR_0X7FF666EF4540[GMAX_ROW * Row + (GMAX_ROW - 1) - K]);
                }
            }
        }
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function08][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

void __fastcall Function09(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            for (size_t K = 0; K < GMAX_ROW; ++K)
            {
                GVAR_0X7FF666EF9CE0[GMAX_ROW * Row + Cul] += GVAR_0X7FF666EF4540[GMAX_ROW * Row + K] * InputString[GMAX_ROW * K + Cul];
            }
        }
    }

    ::memcpy_s((char*)&GValidationInputString[EFunction::F_Function09][0], GINPUT_STRING_COUNT, (const char*)InputString, GINPUT_STRING_COUNT);
}

bool CheckGameClear()
{
    constexpr size_t Var_0x7FF666EF45E0_Count = 0x120;
    constexpr unsigned char Var_0x7FF666EF45E0[Var_0x7FF666EF45E0_Count] =
    {
        0x4A, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x06,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x1D, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xC3, 0x1F, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xF8, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xA0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x3E,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x1B, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x24, 0x36, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x93, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D, 0x3A,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x21, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x15, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xCD, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE4, 0x42,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF1, 0x62, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0B, 0x68, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xE2, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xAD, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAB, 0x75,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x35, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x29, 0x60, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x98, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xF1, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDD, 0x33,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x4D, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1E, 0x2A, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xDC, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0E, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x63,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x5F, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x8B, 0x32, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x43, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x37, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    constexpr size_t TARGET_ARRAY_COUNT = 37;
    __int64 TargetValueArray[TARGET_ARRAY_COUNT] = { 0, };

    ::memcpy_s(TargetValueArray, TARGET_ARRAY_COUNT, Var_0x7FF666EF45E0, Var_0x7FF666EF45E0_Count);

    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            if (GVAR_0X7FF666EF9CE0[GMAX_ROW * Row + Cul] != TargetValueArray[GMAX_ROW * Row + Cul])
            {
                return false;
            }
        }
    }

    return true;
}

#endif

void __fastcall ReverseFunction01(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function01][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    const size_t UnknownPtrLength = ::strlen(UnknownPtr);

    for (size_t InputStringIdx = 0; InputStringIdx < UnknownPtrLength; ++InputStringIdx)
    {
        InputString[InputStringIdx] = InputString[InputStringIdx];
    }
}

void __fastcall ReverseFunction02(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function02][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        InputString[InputStringIdx] = (InputString[InputStringIdx] & 0xAA) >> 0x01 | (InputString[InputStringIdx] & 0x55) << 0x01;
    }
}

void __fastcall ReverseFunction03(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function03][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        bool bIsSame = false;

        for (size_t Var_0x7FF666EF4140_Idx = 0; Var_0x7FF666EF4140_Idx < GVAR_0X7FF666EF4140_COUNT; ++Var_0x7FF666EF4140_Idx)
        {
            if (GVAR_0X7FF666EF4140[Var_0x7FF666EF4140_Idx] == InputString[InputStringIdx])
            {
                InputString[InputStringIdx] = static_cast<unsigned char>(Var_0x7FF666EF4140_Idx);

                bIsSame = true;

                break;
            }
        }

        assert(bIsSame);
    }
}

void __fastcall ReverseFunction04(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function04][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            InputString[GMAX_ROW * Row + Cul] ^= (GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul] & 0xFF);
        }
    }
}

void __fastcall ReverseFunction05(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function05][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (int Count = static_cast<int>(GINPUT_STRING_COUNT) - 1; Count >= 0; --Count)
    {
        const char ShiftCount = ((char)(Count + 1) % GINPUT_STRING_COUNT);
        const char PrevValue1 = InputString[(Count + 2) % GINPUT_STRING_COUNT];
        const char PrevValue2 = InputString[Count % GINPUT_STRING_COUNT];

        InputString[(Count + 2) % GINPUT_STRING_COUNT] ^= 1 << ShiftCount;
        InputString[Count % GINPUT_STRING_COUNT] ^= 1 << ShiftCount;

        if (((InputString[Count % GINPUT_STRING_COUNT] >> ShiftCount) & 0x01) == ((InputString[(Count + 2) % GINPUT_STRING_COUNT] >> ShiftCount) & 0x01))
        {
            InputString[(Count + 2) % GINPUT_STRING_COUNT] = PrevValue1;
            InputString[Count % GINPUT_STRING_COUNT] = PrevValue2;
        }
    }
}

void __fastcall ReverseFunction06(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function06][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (int Row = static_cast<int>(GMAX_ROW) - 1; Row >= 0; --Row)
    {
        for (int Cul = static_cast<int>(GMAX_CUL) - 1; Cul >= Row + 1; --Cul)
        {
            std::swap(InputString[GMAX_ROW * Cul + Row], InputString[GMAX_ROW * Row + Cul]);
        }
    }
}

void __fastcall ReverseFunction07(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function07][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul] = static_cast<int>(::sqrt(GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul]));
        }
    }
}

void __fastcall ReverseFunction08(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function08][InputStringIdx] == InputString[InputStringIdx]);
    }
#endif

    for (int Row = static_cast<int>(GMAX_ROW) - 1; Row >= 0; --Row)
    {
        for (int Cul = static_cast<int>(GMAX_CUL) - 1; Cul >= 0; --Cul)
        {
            if (Row == Cul)
            {
                for (int K = Row - 1; K >= 0; --K)
                {
                    std::swap(GVAR_0X7FF666EF4540[GMAX_ROW * Row + K], GVAR_0X7FF666EF4540[GMAX_ROW * Row + (GMAX_ROW - 1) - K]);
                }
            }
        }
    }
}

void __fastcall ReverseFunction09(const char* UnknownPtr, __int64 UnknownValue_0x2F, __int64 CurrentFunctionPtr, unsigned char* InputString)
{
    auto InverseMatrix = [] <typename T, size_t N> (T* OutMatrix) -> void
    {
        static_assert(std::is_same<T, float>::value || std::is_same<T, double>::value, "Type should be float or double.");

        T AugmentedMatrix[N * (N * 2)] = { 0.0, };

        for (size_t Row = 0; Row < N; ++Row)
        {
            AugmentedMatrix[(N * 2 * Row) + N + Row] = 1.0;

            for (size_t Cul = 0; Cul < N; ++Cul)
            {
                AugmentedMatrix[(Row * 2 * N) + Cul] = OutMatrix[(Row * N) + Cul];
            }
        }

        for (size_t Row = 0; Row < N; ++Row)
        {
            const T Pivot = AugmentedMatrix[(Row * 2 * N) + Row];

            for (size_t Cul = 0; Cul < 2 * N; ++Cul)
            {
                AugmentedMatrix[(Row * 2 * N) + Cul] /= Pivot;
            }

            for (size_t K = 0; K < N; ++K)
            {
                if (K != Row)
                {
                    const float Factor = AugmentedMatrix[(K * 2 * N) + Row];

                    for (size_t Cul = 0; Cul < 2 * N; ++Cul)
                    {
                        AugmentedMatrix[(K * 2 * N) + Cul] -= Factor * AugmentedMatrix[(Row * 2 * N) + Cul];
                    }
                }
            }
        }

        for (size_t Row = 0; Row < N; ++Row)
        {
            for (size_t Cul = 0; Cul < N; ++Cul)
            {
                OutMatrix[(Row * N) + Cul] = AugmentedMatrix[(Row * 2 * N) + Cul + N];
            }
        }
    };

#if TEST
    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        assert(GValidationInputString[EFunction::F_Function09][InputStringIdx] == InputString[InputStringIdx]);
    }

    float GFloat_Var_0x7FF666EF4540[GVAR_0X7FF666EF4540_COUNT] = { 0.f, };

    for (size_t Idx = 0; Idx < GVAR_0X7FF666EF4540_COUNT; ++Idx)
    {
        GFloat_Var_0x7FF666EF4540[Idx] = static_cast<float>(GVAR_0X7FF666EF4540[Idx]);
    }

    InverseMatrix.template operator()<float, 6>(GFloat_Var_0x7FF666EF4540);

    float FloatInputString[GINPUT_STRING_COUNT + 1] = { '\0', };

    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            for (size_t K = 0; K < GMAX_ROW; ++K)
            {
                FloatInputString[GMAX_ROW * Row + Cul] += GFloat_Var_0x7FF666EF4540[GMAX_ROW * Row + K] * static_cast<float>(GVAR_0X7FF666EF9CE0[GMAX_ROW * K + Cul]);
            }
        }
    }

    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        InputString[InputStringIdx] = static_cast<unsigned char>(std::round(FloatInputString[InputStringIdx]));
    }  
#else
    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul] *= GVAR_0X7FF666EF4540[GMAX_ROW * Row + Cul];
        }
    }

    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            if (Row == Cul)
            {
                for (size_t K = 0; K < Row; ++K)
                {
                    std::swap(GVAR_0X7FF666EF4540[GMAX_ROW * Row + K], GVAR_0X7FF666EF4540[GMAX_ROW * Row + (GMAX_ROW - 1) - K]);
                }
            }
        }
    }

    constexpr size_t Var_0x7FF666EF45E0_Count = 0x120;
    constexpr unsigned char Var_0x7FF666EF45E0[Var_0x7FF666EF45E0_Count] =
    {
        0x4A, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD8, 0x06,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x1D, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xC3, 0x1F, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xF8, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xA0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE8, 0x3E,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x1B, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x24, 0x36, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x3C, 0x46, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x93, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1D, 0x3A,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x50, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x03, 0x21, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x15, 0x4D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xCD, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE4, 0x42,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF1, 0x62, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x0B, 0x68, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xE2, 0x27, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xAD, 0x47, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAB, 0x75,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0x35, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x29, 0x60, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x98, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0xF1, 0x16, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDD, 0x33,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x4D, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x1E, 0x2A, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xDC, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x0E, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x63,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x5F, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x8B, 0x32, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x43, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x37, 0x59, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    constexpr size_t TARGET_ARRAY_COUNT = 37;
    __int64 TargetValueArray[TARGET_ARRAY_COUNT] = { 0, };

    ::memcpy_s(TargetValueArray, sizeof(TargetValueArray), Var_0x7FF666EF45E0, Var_0x7FF666EF45E0_Count);

    float GFloat_Var_0x7FF666EF4540[GVAR_0X7FF666EF4540_COUNT] = { 0.f, };

    for (size_t Idx = 0; Idx < GVAR_0X7FF666EF4540_COUNT; ++Idx)
    {
        GFloat_Var_0x7FF666EF4540[Idx] = static_cast<float>(GVAR_0X7FF666EF4540[Idx]);
    }

    InverseMatrix.template operator()<float, 6>(GFloat_Var_0x7FF666EF4540);

    float FloatInputString[GINPUT_STRING_COUNT + 1] = { '\0', };

    for (size_t Row = 0; Row < GMAX_ROW; ++Row)
    {
        for (size_t Cul = 0; Cul < GMAX_CUL; ++Cul)
        {
            for (size_t K = 0; K < GMAX_ROW; ++K)
            {
                FloatInputString[GMAX_ROW * Row + Cul] += GFloat_Var_0x7FF666EF4540[GMAX_ROW * Row + K] * static_cast<float>(TargetValueArray[GMAX_ROW * K + Cul]);
            }
        }
    }

    for (size_t InputStringIdx = 0; InputStringIdx < GINPUT_STRING_COUNT; ++InputStringIdx)
    {
        InputString[InputStringIdx] = static_cast<unsigned char>(std::round(FloatInputString[InputStringIdx]));
    }
#endif
}