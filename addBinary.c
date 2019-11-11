#include <stdio.h>
#include <stdlib.h>

void reverseBinary(char *bin, int len)
{
		char temp;
		int i = 0, j = len - 1; 
		for (i= 0, j = len - 1; i < j; i++, j--) {
				temp = bin[i];
				bin[i] = bin[j];
				bin[j] = temp;
		}
}

char * addBinary(char * a, char * b)
{
		char *ap, *bp, *ret, *result;
		ap = a;
		bp = b;
		char carry = '0', sum;
		int a_len = 0, b_len = 0, ret_len = 0;
		char a_bit, b_bit;
		while (*ap++)
				a_len++;

		reverseBinary(a, a_len);
		while (*bp++)
				b_len++;

		reverseBinary(b, b_len);


		if (a_len > b_len)
				ret_len = a_len + 2;
		else
				ret_len = b_len + 2;

		ret = (char *)malloc(ret_len*sizeof(char));
		result = ret;


		
		a_bit = *a++;
		b_bit = *b++;
		while (a_bit != '\0' && b_bit != '\0')
		{

				if (a_bit == '1'&& b_bit == '1')
				{
						if (carry == '1')
						{
								carry = '1';
								sum = '1';
						}
						else
						{
								carry = '1';
								sum = '0';
						}
				}
				else if (a_bit == '1' || b_bit == '1')
				{
						if (carry == '1')
						{
								carry = '1';
								sum = '0';
						}
						else
						{
								carry = '0';
								sum = '1';
						}
				}

				else
				{

						if (carry == '1')
						{
								carry = '0';
								sum = '1';
						}
						else
						{
								carry = '0';
								sum = '0';
						}
				}
				*ret = sum;
				ret = ret + 1;
				a_bit = *a++;
				b_bit = *b++;
		}
		a--;
		b--;

		if (a_len != b_len) {

				while (1) {
						if (a_len > b_len)
								a_bit = *a++;
						else
								a_bit = *b++;

						if (a_bit != '\0') {

								if (a_bit == '1' && carry == '1') {
										sum = '0';
										carry = '1';
								}
								else if ( a_bit == '1' || carry == '1') {
										sum = '1';
										carry = '0';
								}
								else
								{
										sum = '0';
										carry = '0';
								}
								*ret = sum;
								ret++;
						}
						else 
						{
								if (carry == '1') {
										*ret = carry;
										ret++;
								}
								break;
						}
				}
		}

		else {
				if (carry == '1') {
						*ret = carry;
						ret++;
				}
		}

		*ret = '\0';

		ret = result;
		ret_len = 0;
		while (*ret++)
				ret_len++;
		reverseBinary(result, ret_len);
		return result;



}


//char * addBinary(char * a, char * b)
int main() 
{
		char a[] = "11";
		char b[] = "1";
		printf("%s\n", addBinary(a, b));
}
