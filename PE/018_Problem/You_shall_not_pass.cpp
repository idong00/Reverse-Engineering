#include <stdio.h>
#include <assert.h>

#define TEST 0

int main()
{
	constexpr size_t INPUT_STRING_COUNT = 32;

#if TEST
	constexpr int TEST_ARRAY[INPUT_STRING_COUNT] =
	{
		0x99, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x1A, 0x4D, 0x3F, 0x89,
	};

	char TestInputString[] = "DH{aaaaaaaaaaaaaaaaaaaaaaaaaaaa}";
	int TestConvertedArray[INPUT_STRING_COUNT] = { 0, };

	for (size_t InputStringIdx = 0; InputStringIdx < INPUT_STRING_COUNT - 1; ++InputStringIdx)
	{
		TestInputString[InputStringIdx] ^= TestInputString[InputStringIdx + 1];
	}

	for (int InputStringIdx = static_cast<int>(INPUT_STRING_COUNT) - 1; InputStringIdx >= 0; --InputStringIdx)
	{
		TestConvertedArray[INPUT_STRING_COUNT - InputStringIdx - 1 & 31] = static_cast<int>(TestInputString[InputStringIdx] + TestInputString[InputStringIdx - 1 & 31]);
	}

	for (size_t InputStringIdx = 0; InputStringIdx < INPUT_STRING_COUNT; ++InputStringIdx)
	{
		assert(TEST_ARRAY[InputStringIdx] == TestConvertedArray[InputStringIdx]);
	}
#else
	constexpr int GOAL_ARRAY[INPUT_STRING_COUNT] =
	{
		148, 27, 14, 27, 34, 25, 10, 30,
		48,  33, 23, 15, 19, 43, 46, 30,
		23,  15, 19, 43, 33, 34, 60, 54,
		49,  47, 42, 42, 51, 80, 63, 137
	};

	char InputString[INPUT_STRING_COUNT + 1] = { '\0', };
	InputString[0] = 'D';
	InputString[1] = 'H';
	InputString[2] = '{';
	InputString[INPUT_STRING_COUNT - 1] = '}';
	
	for (size_t InputStringIdx = 0; InputStringIdx < INPUT_STRING_COUNT; ++InputStringIdx)
	{	
		InputString[InputStringIdx] = static_cast<char>(GOAL_ARRAY[INPUT_STRING_COUNT - InputStringIdx - 1 & 31] - InputString[InputStringIdx - 1 & 31]);
	}

	for (int InputStringIdx = static_cast<int>(INPUT_STRING_COUNT) - 2; InputStringIdx >= 0; --InputStringIdx)
	{
		InputString[InputStringIdx] ^= InputString[InputStringIdx + 1];
	}

	printf("%s", InputString);

#endif
	return 0;
}