#include <iostream>

std::string Base64Decode(const unsigned char* EncodedString, const size_t Length)
{
    auto IsBase64 = [](const unsigned char Char) -> bool
    {
        return (::isalnum(Char) || (Char == '+') || (Char == '/'));
    };

    const std::string Base64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string Result;
    size_t FirstCharArray4Idx = 0;
    unsigned char CharArray3[3] = { 0, };
    unsigned char CharArray4[4] = { 0, };

    for (size_t EncodedStringIdx = 0; EncodedStringIdx < Length && EncodedString[EncodedStringIdx] != '=' && IsBase64(EncodedString[EncodedStringIdx]); ++EncodedStringIdx)
    {
        CharArray4[FirstCharArray4Idx] = EncodedString[EncodedStringIdx];

        ++FirstCharArray4Idx;

        if (FirstCharArray4Idx == 4)
        {
            for (FirstCharArray4Idx = 0; FirstCharArray4Idx < 4; FirstCharArray4Idx++)
            {
                CharArray4[FirstCharArray4Idx] = static_cast<unsigned char>(Base64Chars.find(CharArray4[FirstCharArray4Idx]));
            }

            CharArray3[0] = (CharArray4[0] << 2) + ((CharArray4[1] & 0x30) >> 4);
            CharArray3[1] = ((CharArray4[1] & 0xF) << 4) + ((CharArray4[2] & 0x3C) >> 2);
            CharArray3[2] = ((CharArray4[2] & 0x3) << 6) + CharArray4[3];

            for (FirstCharArray4Idx = 0; (FirstCharArray4Idx < 3); ++FirstCharArray4Idx)
            {
                Result += CharArray3[FirstCharArray4Idx];
            }

            FirstCharArray4Idx = 0;
        }
    }

    size_t SecondCharArray4Idx = 0;

    if (FirstCharArray4Idx)
    {
        for (SecondCharArray4Idx = FirstCharArray4Idx; SecondCharArray4Idx < 4; SecondCharArray4Idx++)
        {
            CharArray4[SecondCharArray4Idx] = 0;
        }

        for (SecondCharArray4Idx = 0; SecondCharArray4Idx < 4; ++SecondCharArray4Idx)
        {
            CharArray4[SecondCharArray4Idx] = static_cast<unsigned char>(Base64Chars.find(CharArray4[SecondCharArray4Idx]));
        }

        CharArray3[0] = (CharArray4[0] << 2) + ((CharArray4[1] & 0x30) >> 4);
        CharArray3[1] = ((CharArray4[1] & 0xF) << 4) + ((CharArray4[2] & 0x3C) >> 2);
        CharArray3[2] = ((CharArray4[2] & 0x3) << 6) + CharArray4[3];

        for (SecondCharArray4Idx = 0; (SecondCharArray4Idx < FirstCharArray4Idx - 1); ++SecondCharArray4Idx)
        {
            Result += CharArray3[SecondCharArray4Idx];
        }
    }

    return Result;
}

int main()
{
    constexpr size_t BASE64_STRING_COUNT = 12;
	constexpr unsigned char BASE64_STRING[BASE64_STRING_COUNT] =
	{
		(74 ^ 16),   (87 ^ 17),   (77 ^ 33),   (70 ^ 51),
		(29 ^ 68),   (49 ^ 102),  (117 ^ 51),  (238 ^ 160),
		(241 ^ 144), (226 ^ 181), (163 ^ 238), (44 ^ 17)
	};

    std::cout << ::Base64Decode(BASE64_STRING, BASE64_STRING_COUNT).c_str();

    return 0;
}