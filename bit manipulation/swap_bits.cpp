//two swap 2 bit:
//Extract the bits at p1 and p2 by using bitwise operations.
//If the bits are different, flip them by toggling the bits at p1 and p2 using XOR (^).
//(num ^= (1 << p1))

void swap_bit(int num, int src_pos, int dest_pos, int no_of_bit)
{
	//initialization
	int src_num = dest_num = 0;
	for(int index = 0; index < 32; index++)
	{
		for(int in_index = 0; in_index < no_of_bit; in_index++)
		{
			// separate numbers bit by bit
			src_num = num & (1 << src_pos++); // src bit check starting
			dst_num = num & (1 << dest_num++); // dst bit check starting		
		}
	}
}

