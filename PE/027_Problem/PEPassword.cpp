#include <iostream>
#include <limits>
#include <assert.h>

#define TEMP 0

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
#if TEMP
	const char* InputString = "abcdefg";

	unsigned int EAX = 0x00;
	unsigned int ECX = 0x00234000;
	unsigned int EDX = 0x00;

	do
	{
		EAX = (EAX & 0xFFFF00FF) | ((EAX & 0xFF00) ^ (*InputString << 8));

		do
		{
			EAX = (EAX & 0xFFFFFF00) | ((EAX & 0xFF) ^ (EDX & 0xFF));
			EAX += 0x434F4445;
			ECX = (ECX & 0xFFFFFF00) | (EAX & 0xFF);
			EAX = ::ROR<unsigned int>(EAX, ECX & 0xFF);
			EAX ^= 0x55AA5A5A;
			EDX = ((EDX & 0x0000FFFF) - 1) & 0x0000FFFF;
		} while (EDX);
	} while (*InputString++ != '\0');

	assert(EAX == 0xFFA2E4AA);
#else
	constexpr unsigned int ORIGIN_EAX = 0x014CEC81 ^ 0xB6E62E17;
	constexpr unsigned int ORIGIN_NEXT_OFFSET_DATA = 0x57560000;
	constexpr unsigned int PACKED_NEXT_OFFSET_DATA = 0x0D0C7E05;

	std::cout << std::hex << "EAX: 0x" << ORIGIN_EAX << '\n';

	for (unsigned int EBX = 0; EBX < std::numeric_limits<unsigned int>::max(); ++EBX)
	{
		unsigned int EAX = ORIGIN_EAX;
		unsigned int ECX = 0x1000;
		unsigned int TempEBX = ::ROL<unsigned int>(EBX, EAX & 0xFF);

		EAX ^= TempEBX;
		EAX = ::ROR<unsigned int>(EAX, (TempEBX & 0x0000FF00) >> 0x08);

		if ((EAX ^ PACKED_NEXT_OFFSET_DATA) == ORIGIN_NEXT_OFFSET_DATA)
		{
			std::cout << std::hex << "EBX: 0x" << EBX << '\n';
		}
	}
#endif

	return 0;
}