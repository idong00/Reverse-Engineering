#include <stdio.h>
#include <assert.h>
#include <type_traits>

#define TEST 0

template<typename T>
T ROR(const T Number, const size_t ShiftCount)
{
	static_assert(!std::is_class<T>::value, "Type is class type.");

	return (Number >> ShiftCount) | (Number << (sizeof(T) * 0x08 - ShiftCount));
}

template<typename T>
T ROL(const T Number, const size_t ShiftCount)
{
	static_assert(!std::is_class<T>::value, "Type is class type.");
	
	return (Number << ShiftCount) | (Number >> (sizeof(T) * 0x08 - ShiftCount));
}

int main()
{
	/* Input String Count */
	constexpr size_t INPUT_STRING_COUNT = 24;

	/* Goal Data Count */
	constexpr size_t GOAL_DATA_COUNT = sizeof(unsigned char) * INPUT_STRING_COUNT * 4;

	/* neko_hat */
	constexpr size_t NEKO_HAT_COUNT = 8;
	constexpr unsigned char NEKO_HAT[NEKO_HAT_COUNT] = { 0x6E, 0x65, 0x6B, 0x6F, 0x5F, 0x68, 0x61, 0x74 };

#if TEST
	constexpr unsigned char TEST_INPUT_STRING[INPUT_STRING_COUNT + 1] = "DH{aaaaaaaaaaaaaaaaaaaa}";
	constexpr unsigned char TEST_DATA[GOAL_DATA_COUNT] =
	{
		0x08, 0x76, 0x00, 0x40, 0xF6, 0x75, 0x00, 0x80, 0x07, 0x76, 0x00, 0xB0, 0x08, 0x76, 0x00, 0x10,
		0xF7, 0x75, 0x00, 0x10, 0x03, 0x76, 0x00, 0x10, 0x02, 0x76, 0x00, 0x10, 0x11, 0x76, 0x00, 0x10,
		0x06, 0x76, 0x00, 0x10, 0xF8, 0x75, 0x00, 0x10, 0x08, 0x76, 0x00, 0x10, 0x08, 0x76, 0x00, 0x10,
		0xF7, 0x75, 0x00, 0x10, 0x03, 0x76, 0x00, 0x10, 0x02, 0x76, 0x00, 0x10, 0x11, 0x76, 0x00, 0x10,
		0x06, 0x76, 0x00, 0x10, 0xF8, 0x75, 0x00, 0x10, 0x08, 0x76, 0x00, 0x10, 0x08, 0x76, 0x00, 0x10,
		0xF7, 0x75, 0x00, 0x10, 0x03, 0x76, 0x00, 0x10, 0x02, 0x76, 0x00, 0x10, 0x12, 0x76, 0x00, 0xD0,
	};

	unsigned char Destination[GOAL_DATA_COUNT] = { '\0', };

	for (size_t InputStringIdx = 0; InputStringIdx < INPUT_STRING_COUNT; ++InputStringIdx)
	{
		const unsigned int FirstCalc = ::ROR(static_cast<unsigned int>(TEST_INPUT_STRING[InputStringIdx]), 4);
		const unsigned int SecondCalc = FirstCalc ^ NEKO_HAT[InputStringIdx & 0x80000007];
		const unsigned int ThirdCalc = SecondCalc + NEKO_HAT[InputStringIdx & 0x80000003];
		const unsigned int ForthCalc = ThirdCalc + 0x7530;

		*(unsigned int*)(Destination + (4 * InputStringIdx)) = ForthCalc;
	}

	for (size_t TestIdx = 0; TestIdx < sizeof(unsigned char) * INPUT_STRING_COUNT * 4; ++TestIdx)
	{
		assert(Destination[TestIdx] == TEST_DATA[TestIdx]);
	}
#else
	/* Goal Data */
	constexpr unsigned char GOAL_DATA[GOAL_DATA_COUNT] =
	{
		0x08, 0x76, 0x00, 0x40, 0xF6, 0x75, 0x00, 0x80, 0x07, 0x76, 0x00, 0xB0, 0x07, 0x76, 0x00, 0x90,
		0xFA, 0x75, 0x00, 0x00, 0x04, 0x76, 0x00, 0x50, 0xFF, 0x75, 0x00, 0xF0, 0x16, 0x76, 0x00, 0x40,
		0x07, 0x76, 0x00, 0x20, 0xFB, 0x75, 0x00, 0x30, 0x09, 0x76, 0x00, 0xF0, 0x08, 0x76, 0x00, 0x30,
		0xF7, 0x75, 0x00, 0xD0, 0x04, 0x76, 0x00, 0x00, 0xFF, 0x75, 0x00, 0xF0, 0x10, 0x76, 0x00, 0xF0,
		0x06, 0x76, 0x00, 0xD0, 0xF8, 0x75, 0x00, 0x10, 0x03, 0x76, 0x00, 0x50, 0x07, 0x76, 0x00, 0x40,
		0xFA, 0x75, 0x00, 0x30, 0x04, 0x76, 0x00, 0x20, 0xFE, 0x75, 0x00, 0x10, 0x12, 0x76, 0x00, 0xD0
	};

	for (size_t InputStringIdx = 0; InputStringIdx < INPUT_STRING_COUNT; ++InputStringIdx)
	{
		const unsigned int FirstCalc = *(unsigned int*)(GOAL_DATA + (4 * InputStringIdx)) - 0x7530;
		const unsigned int SecondCalc = FirstCalc - NEKO_HAT[InputStringIdx & 0x80000003];
		const unsigned int ThirdCalc = SecondCalc ^ NEKO_HAT[InputStringIdx & 0x80000007];
		const unsigned int ForthCalc = ::ROL(ThirdCalc, 4);

		printf("%c", static_cast<unsigned char>(ForthCalc));
	}
#endif
	return 0;
}