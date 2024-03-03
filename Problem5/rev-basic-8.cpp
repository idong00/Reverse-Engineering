#include <stdio.h>

/* Printable Characters Range */
constexpr unsigned char MIN_CHAR_VALUE = 32;
constexpr unsigned char MAX_CHAR_VALUE = 127;

/* Array of value to compare */
constexpr size_t GVALUE_TO_COMPARE_ARRAY_SIZE = 21;
constexpr unsigned char GVALUE_TO_COMPARE_ARRAY[GVALUE_TO_COMPARE_ARRAY_SIZE] =
{
	0xAC, 0xF3, 0x0C, 0x25, 0xA3,
	0x10, 0xB7, 0x25, 0x16, 0xC6,
	0xB7, 0xBC, 0x07, 0x25, 0x02,
	0xD5, 0xC6, 0x11, 0x07, 0xC5,
	0x00
};

int main()
{
	for (size_t ArrayIdx = 0; ArrayIdx < GVALUE_TO_COMPARE_ARRAY_SIZE; ++ArrayIdx)
	{
		for (unsigned char Char = MIN_CHAR_VALUE; Char <= MAX_CHAR_VALUE; ++Char)
		{
			const unsigned char MulValue = 0xFB * Char;

			if (GVALUE_TO_COMPARE_ARRAY[ArrayIdx] == (MulValue & 0xFF))
			{
				printf("%c", Char);

				break;
			}
		}
	}

	return 0;
}

// Output : Did_y0u_brute_force?