#include <stdio.h>

/* Printable Characters Range */
constexpr unsigned char GMIN_CHAR_VALUE = 32;
constexpr unsigned char GMAX_CHAR_VALUE = 127;

/* 0x7FF6780F3000 */
constexpr size_t G0x7FF6780F3000_SIZE = 0x1C;
constexpr unsigned char G0x7FF6780F3000[G0x7FF6780F3000_SIZE] =
{
	0x24, 0x27, 0x13, 0xC6,
	0xC6, 0x13, 0x16, 0xE6,
	0x47, 0xF5, 0x26, 0x96,
	0x47, 0xF5, 0x46, 0x27,
	0x13, 0x26, 0x26, 0xC6,
	0x56, 0xF5, 0xC3, 0xC3,
	0xF5, 0xE3, 0xE3, 0x00
};

int main()
{
	for (size_t Var_0x7FF6780F3000_Idx = 0; Var_0x7FF6780F3000_Idx < G0x7FF6780F3000_SIZE; ++Var_0x7FF6780F3000_Idx)
	{
		for (unsigned char Char = GMIN_CHAR_VALUE; Char < GMAX_CHAR_VALUE; ++Char)
		{
			const unsigned char Eax = Char >> 4;
			const unsigned char Ecx = Char << 4;

			if ((Eax | (Ecx & 0xF0)) == G0x7FF6780F3000[Var_0x7FF6780F3000_Idx])
			{
				printf("%c", Char);

				break;
			}
		}
	}

	return 0;
}

// Output : Br1ll1ant_bit_dr1bble_<<_>>