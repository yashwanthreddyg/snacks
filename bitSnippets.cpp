#include <stdio.h>
int getBitCount(int num)
{
	int count = 0;
	int i;
	for (i = 0; i < 32; i++)
	{
		if (num % 2 == 1)
			count++;
		num = num >> 1;
	}
	return count;
}

char* getBinStr(unsigned int num,char* numstr)
{
	if (num == 0)
	{
		numstr[0] = '0';
		numstr[1] = '\0';
		return numstr;
	}
	int i = 0;
	while (num > 0)
	{
		numstr[i++] = '0' + num % 2;
		num = num >> 1;
	}
	numstr[i] = '\0';
	int lastcharind = i-1;
	int first,last;
	for (first = 0, last = lastcharind; last > first; last--, first++)
	{
		numstr[first] ^= numstr[last];
		numstr[last] ^= numstr[first];
		numstr[first] ^= numstr[last];
	}
	return numstr;
}

int isBitSet(int num, int bitPos)
{
	return (num >> bitPos) & 1;
}

int setBit(int num, int bitPos)
{
	return num | (1<<bitPos);
}

int unsetBit(int num, int bitPos)
{
	return num&(~(1 << bitPos));
}

int setRangeOfBitsIncl(int num, int i, int j)
{
	int temp1 = (1 << (j - i + 1)) - 1;
	temp1 = temp1 << i;
	return num | temp1;
}

int setRangeOfBitsExcl(int num, int i, int j)
{
	int temp1 = 1;
	temp1 = (temp1 << (j - i-1)) - 1;
	temp1 = temp1 << (i+1);
	return num | temp1;
}

int unSetRangeOfBitsIncl(int num, int i, int j)
{
	int temp1 = 1;
	temp1 = (temp1 << (j - i + 1)) - 1;
	temp1 = temp1 << i;
	temp1 = ~temp1;
	return num & temp1;
}

int unSetRangeOfBitsExcl(int num, int i, int j)
{
	int temp1 = 1;
	temp1 = (temp1 << (j - i - 1)) - 1;
	temp1 = temp1 << (i + 1);
	temp1 = ~temp1;
	return num & temp1;
}

int main()
{
	char str[32];
	getBinStr(setRangeOfBitsIncl(0b1000000000, 2, 5), str);
	printf("%s\n", str);
	getBinStr(setRangeOfBitsExcl(0b1000000000, 2, 5), str);
	printf("%s\n", str);
	getBinStr(unSetRangeOfBitsIncl(0b1111111111, 2, 5), str);
	printf("%s\n", str);
	getBinStr(unSetRangeOfBitsExcl(0b1111111111, 2, 5), str);
	printf("%s\n", str);
	scanf("%d");
}