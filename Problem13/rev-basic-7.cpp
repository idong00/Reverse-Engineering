#include <stdio.h>

/* Printable Characters Range */
constexpr unsigned char GMIN_CHAR_VALUE = 32;
constexpr unsigned char GMAX_CHAR_VALUE = 127;

/* 0x7FF6780F3000 */
constexpr size_t GMAX_LOOP_COUNT = 0x1F;
constexpr unsigned char G0x7FF62AC33000[GMAX_LOOP_COUNT] =
{
	0x52, 0xDF, 0xB3, 0x60,
	0xF1, 0x8B, 0x1C, 0xB5,
	0x57, 0xD1, 0x9F, 0x38,
	0x4B, 0x29, 0xD9, 0x26,
	0x7F, 0xC9, 0xA3, 0xE9,
	0x53, 0x18, 0x4F, 0xB8,
	0x6A, 0xCB, 0x87, 0x58,
	0x5B, 0x39, 0x1E
};

unsigned char ROL(const unsigned char Number, const unsigned char ShiftCount)
{
	return (Number << ShiftCount) | (Number >> (0x08 - ShiftCount));
}

int main()
{
	for (size_t LoopCount = 0; LoopCount < GMAX_LOOP_COUNT; ++LoopCount)
	{
		for (unsigned char Char = GMIN_CHAR_VALUE; Char < GMAX_CHAR_VALUE; ++Char)
		{
			if (G0x7FF62AC33000[LoopCount] == (ROL(Char, ((LoopCount & 0x07) & 0xFF)) ^ LoopCount))
			{
				printf("%c", Char);

				break;
			}
		}
	}

	return 0;
}

// Output : Roll_the_left!_Roll_the_right!