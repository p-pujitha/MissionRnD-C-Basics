int no_of_digits(int);
/*
OVERVIEW: Write a function which takes two numbers as input and returns sum of two numbers.
		E.g.: sum(2, 3) returns 5.

INPUTS: Two numbers a, b;

OUTPUT: sum of the numbers a, b.

ERROR CASES:

NOTES:
*/
int sum(int a, int b)						/*adder of 2 numbers*/
	{
		int n1[10], n2[10], i = 0, j = 0, l = 0, n3[10], rem;
		while (a != 0)
		{
			rem = a % 10;
			n1[i] = rem;
			i++;
			a = a / 10;
		}
		while (b != 0)
		{
			rem = b % 10;
			n2[j] = rem;
			j++;
			b = b / 10;
		}
		int carry = 0;
		int k;
		if (i >= j)
		{
			for (k = 0; k<j; k++)
			{
				n3[l] = n1[k] + n2[k] + carry;
				int length = no_of_digits(n3[l]);
				if (length == 2)
				{
					n3[l] = n3[k] % 10;
					carry = n3[k] / 10;
					l++;
				}
				else
				{
					l++;
					carry = 0;
				}
			}

			for (int m = k; m<i; m++)
			{
				n3[l] = n1[m] + carry;
				int length = no_of_digits(n3[l]);
				if (length == 2)
				{
					n3[l] = n3[m] % 10;
					carry = n3[m] / 10;
					if (carry != 0)
					{
						n3[l++] = carry;
					}
				}
				else
					l++;

			}
		}
		int count = 0;
		for (int i = 0; i<l; i++)
		{
			
			count++;
		}

		int res = 0;
		for (int i = l - 1; i >= 0; i--)
		{
			res = 10 * res + n3[i];
		}

		return res;
	}

	int no_of_digits(int a)
	{
		int count = 0, rem;
		while (a != 0)
		{
			rem = a % 10;
			count++;
			a = a / 10;
		}
		return count;
	}
