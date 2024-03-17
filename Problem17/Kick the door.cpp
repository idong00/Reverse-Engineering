#include <stdio.h>

#define TEST 0

void Encryption(unsigned char* OutString, const size_t StringCount);
void Decryption(unsigned char* OutString, const size_t StringCount);

int main()
{
	constexpr size_t GSTRING_COUNT = 0x1A;

#if TEST
	unsigned char InputString[GSTRING_COUNT + 1] = "abcdefghijk12345678901234";

	::printf("Input String : %s\n", InputString);

	::Encryption(InputString, GSTRING_COUNT);

	::printf("Encryption : %s\n", InputString);

	::Decryption(InputString, GSTRING_COUNT);

	::printf("Decryption : %s\n", InputString);

#else
	/* 0x7FFC5E187000 */
	unsigned char G0x7FFC5E187000[GSTRING_COUNT + 1] =
	{
		0x2B, 0x44, 0x1B, 0x52,
		0x2B, 0x5E, 0x1B, 0x05,
		0x01, 0x6E, 0x19, 0x5E,
		0x0F, 0x63, 0x01, 0x01,
		0x2B, 0x74, 0x20, 0x4E,
		0x15, 0x46, 0x3C, 0x77,
		0x7C, 0x43, 0x00
	};

	::Decryption(G0x7FFC5E187000, GSTRING_COUNT);

	::printf("Decryption : %s\n", G0x7FFC5E187000);
#endif

	return 0;
}

void Encryption(unsigned char* OutString, const size_t StringCount)
{
	for (size_t LoopCount = 0; LoopCount < StringCount; ++LoopCount)
	{
		OutString[LoopCount] = OutString[LoopCount] ^ OutString[(LoopCount + 1) & 0x19];
	}
}

void Decryption(unsigned char* OutString, const size_t StringCount)
{
	for (int LoopCount = StringCount - 1; LoopCount >= 0; --LoopCount)
	{
		OutString[LoopCount] = OutString[LoopCount] ^ OutString[(LoopCount + 1) & 0x19];
	}
}

