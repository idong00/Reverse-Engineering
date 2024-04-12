#include <iostream>
#include <Windows.h>
#include <assert.h>
#include <string>

#include <openssl/aes.h>

int main()
{
    constexpr const char* const FILE_PATH = "C:\\ReversingStudy\\Problem23\\out.txt";
    constexpr const char* const FILE_MODE = "rb";

    // Read file
    FILE* FilePtr = nullptr;

    assert(0 == ::fopen_s(&FilePtr, FILE_PATH, FILE_MODE));
    assert(0 == ::fseek(FilePtr, 0, SEEK_END));

    const long FileSize = ::ftell(FilePtr);

    assert(0 == ::fseek(FilePtr, 0, SEEK_SET));
    
    unsigned char* EncriptionData = new unsigned char[FileSize];
    ::memset(EncriptionData, 0, FileSize);

    assert(FileSize == ::fread_s(EncriptionData, FileSize, sizeof(unsigned char), FileSize, FilePtr));

    // Printable Ascii
    std::string DecriptionData;
    DecriptionData.resize(AES_BLOCK_SIZE * AES_BLOCK_SIZE);

    // IV
    unsigned char IV[AES_BLOCK_SIZE] = { 0, };

    // Decription Brute Force
    for (int Number = 0; Number < 32768; ++Number)
    {
        // Generate Key
        constexpr size_t KEY_COUNT = 0x10;
        unsigned char KEY[KEY_COUNT] =
        {
            0x41, 0x28, 0x19, 0x4E,
            0xA5, 0x7C, 0xA1, 0x41,
            0x13, 0xCF, 0x88, 0xAC,
            0x2A, 0xF0, 0xB7, 0xDA
        };

        for (size_t Idx = 0; Idx < KEY_COUNT - 1; ++Idx)
        {
            KEY[Idx + 1] += KEY[Idx];
            KEY[Idx] ^= Number;
        }

        KEY[KEY_COUNT - 1] ^= Number;

        AES_KEY AesKey;
        ::memset(&AesKey, 0, sizeof(AES_KEY));
        assert(0 == ::AES_set_decrypt_key(KEY, sizeof(KEY) * 8, &AesKey));

        // Decription
        ::AES_cbc_encrypt(EncriptionData, (unsigned char*)&DecriptionData[0], DecriptionData.size(), &AesKey, IV, AES_DECRYPT);

        if (DecriptionData[0] == 'D' && DecriptionData[1] == 'H' && DecriptionData[2] == '{')
        {
            printf("%s\n", DecriptionData.c_str());
        }

        std::memset(IV, 0, AES_BLOCK_SIZE);
        std::fill(DecriptionData.begin(), DecriptionData.end(), 0);
    }

    delete[] EncriptionData;

    ::fclose(FilePtr);

    return 0;
}