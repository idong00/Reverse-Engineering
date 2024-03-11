#include <stdio.h>
#include <assert.h>

/* Printable Characters Range */
constexpr unsigned char GMIN_CHAR_VALUE = 32;
constexpr unsigned char GMAX_CHAR_VALUE = 127;

/* 0x7FF6780F3000 */
constexpr size_t GMAX_LOOP_COUNT = 0x18;
constexpr unsigned char G0x7FF6DAFB3000[GMAX_LOOP_COUNT] =
{
	0xAD, 0xD8, 0xCB, 0xCB,
	0x9D, 0x97, 0xCB, 0xC4,
	0x92, 0xA1, 0xD2, 0xD7,
	0xD2, 0xD6, 0xA8, 0xA5,
	0xDC, 0xC7, 0xAD, 0xA3,
	0xA1, 0x98, 0x4C, 0x00
};

int main()
{
	unsigned char Answer[GMAX_LOOP_COUNT] = { 0, };
	Answer[GMAX_LOOP_COUNT - 1] = '\0';
	Answer[GMAX_LOOP_COUNT - 2] = G0x7FF6DAFB3000[GMAX_LOOP_COUNT - 2];

	for (size_t LoopCount = GMAX_LOOP_COUNT - 3; LoopCount >= 0; --LoopCount)
	{
		for (unsigned char Char = GMIN_CHAR_VALUE; Char <= GMAX_CHAR_VALUE; ++Char)
		{
			if (G0x7FF6DAFB3000[LoopCount] == Char + Answer[LoopCount + 1])
			{
				Answer[LoopCount] = Char;

				break;
			}
		}

		if (!LoopCount)
		{
			break;
		}
	}

	printf("%s", Answer);

	return 0;
}

// Output : All_l1fe_3nds_w1th_NULL