#include <stdio.h>

/* Printable Characters Range */
constexpr unsigned char GMIN_CHAR_VALUE = 32;
constexpr unsigned char GMAX_CHAR_VALUE = 127;

/* 0x7FF6780F3000 */
constexpr size_t G0x7FF6D8DF3000_SIZE = 0x18;
constexpr unsigned char G0x7FF6D8DF3000[G0x7FF6D8DF3000_SIZE] =
{
	0x49, 0x60, 0x67, 0x74,
	0x63, 0x67, 0x42, 0x66,
	0x80, 0x78, 0x69, 0x69,
	0x7B, 0x99, 0x6D, 0x88,
	0x68, 0x94, 0x9F, 0x8D,
	0x4D, 0xA5, 0x9D, 0x45
};

int main()
{
	for (size_t Var_0x7FF6D8DF3000_Idx = 0; Var_0x7FF6D8DF3000_Idx < G0x7FF6D8DF3000_SIZE; ++Var_0x7FF6D8DF3000_Idx)
	{
		const unsigned char Eax = G0x7FF6D8DF3000[Var_0x7FF6D8DF3000_Idx];

		for (unsigned char Char = GMIN_CHAR_VALUE; Char <= GMAX_CHAR_VALUE; ++Char)
		{
			const unsigned char Ecx = (Char ^ Var_0x7FF6D8DF3000_Idx);

			if (Eax == Ecx + (Var_0x7FF6D8DF3000_Idx << 1))
			{
				printf("%c", Char);

				break;
			}
		}
	}

	return 0;
}

// Output : I_am_X0_xo_Xor_eXcit1ng