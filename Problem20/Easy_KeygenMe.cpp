#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TEST 0

int main()
{
	constexpr size_t MAX_INPUT_NAME_COUNT = 8;
	constexpr size_t CONVERTED_ARRAY_COUNT = MAX_INPUT_NAME_COUNT << 1;
	constexpr char CALC_NUMBER_ARRAY[3] = { 0x10, 0x20, 0x30 };
	
#if TEST
	constexpr const char* const TEST_INPUT_NAME = "12345678";
	constexpr char TEST_CONVERTED_ARRAY[CONVERTED_ARRAY_COUNT] =
	{
		0x32, 0x31, 0x31, 0x32,
		0x30, 0x33, 0x32, 0x34,
		0x31, 0x35, 0x30, 0x36,
		0x32, 0x37, 0x31, 0x38
	};

	char ConvertedArray[CONVERTED_ARRAY_COUNT + 1] = { 0, };

	for (size_t InputNameIdx = 0; InputNameIdx < MAX_INPUT_NAME_COUNT; ++InputNameIdx)
	{
		sprintf_s(ConvertedArray, CONVERTED_ARRAY_COUNT + 1, "%s%02X", ConvertedArray, TEST_INPUT_NAME[InputNameIdx] ^ CALC_NUMBER_ARRAY[InputNameIdx % 0x03]);
	}

	for (size_t ConvertedArrayIdx = 0; ConvertedArrayIdx < CONVERTED_ARRAY_COUNT; ++ConvertedArrayIdx)
	{
		assert(ConvertedArray[ConvertedArrayIdx] == TEST_CONVERTED_ARRAY[ConvertedArrayIdx]);
	}
#else
	constexpr const char* const SERIAL = "5B134977135E7D13";

	size_t CalcArrayIdx = 0;
	size_t InputNameIdx = 0;
	size_t SerialIdx = 0;
	char Current16DigitsString[3] = { '\0', };
	char InputName[MAX_INPUT_NAME_COUNT + 1] = { '\0', };

	while (SerialIdx < CONVERTED_ARRAY_COUNT)
	{
		Current16DigitsString[0] = SERIAL[SerialIdx];
		Current16DigitsString[1] = SERIAL[SerialIdx + 1];

		InputName[InputNameIdx++] = strtol(Current16DigitsString, NULL, 16) ^ CALC_NUMBER_ARRAY[CalcArrayIdx++ % 0x03];

		SerialIdx += 2;
	}

	printf("%s", InputName);
#endif
	return 0;
}

// Output : K3yg3nm3