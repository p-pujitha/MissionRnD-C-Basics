int fun(int[], int[], int);
/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *str1, char *str2) {

	int  flag = 0, length = 0, k = 0;
	for (int i = 0; str1[i] != '\0'; i++)    /*Finding the length of the 1st string*/
	{
		length++;
	}
	for (int m = 0; str2[m] != '\0';)
	{
		if (str2[m] == '0')
		{
			flag = 1;
			m++;
		}
		else
			break;
	}
	if (flag == 1)
		return -1;
	flag = 0;
	for (int k = 0; str1[k] != '\0';)  /*comparing whether 2 strings are equal or not*/
	{
		if (str1[k] == str2[k])
		{

			k++;
		}
		else
			break;
	}
	if (k == length)
		return 0;
	else
	{                                             /* if 2 strings are not equal then divide them into date , month and the year */

		int sum = 0, n1[3], j = 0, n2[3], k = 0;

		for (int i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] == '-')
			{
				j++;
				sum = 0;
			}									/* 1st persons details -> month, year and date */
			else
			{

				int num = str1[i] - '0';
				sum = 10 * sum + num;
				n1[j] = sum;
			}
		}

		sum = 0;
		for (int i = 0; str2[i] != '\0'; i++)
		{
			if (str2[i] == '-')
			{
				k++;
				sum = 0;						/* 2nd persons details-> date, month, year */
			}
			else
			{
				int num = str2[i] - '0';
				sum = 10 * sum + num;
				n2[k] = sum;
			}
		}

		int result = fun(n1, n2, 2);
		if (result == 0)
			return -1;
		else
		{
			for (int i = 2; i >= 0;)
			{
				if (n1[i]>n2[i])
					return 2;						/*checking which person is greatest or equal*/
				else
					if (n2[i]>n1[i])
						return 1;
					else
					{
						i--;
						if (n1[i]>n2[i])
							return 2;
						else
							if (n2[i]>n1[i])
								return 1;
							else
							{
								i--;
								if (n1[i]>n2[i])
									return 2;
								else
									if (n2[i]>n1[i])
										return 1;
									else
										return 0;
							}
					}
			}

		}
	}
}
int fun(int a[], int b[], int i)   /* checking whether given input is invalid or not*/
{
	int c[2], k = 0;
	for (int j = i - 1; j >= 0; j--)
	{
		if (j == 1)
		{
			if (a[j]>12 || b[j]>12)
				return 0;
			else
			{
				c[0] = a[j];
				c[1] = b[j];
			}
		}
		else if (j == 0)
		{
			for (i = 0; i <= 1; i++)
			{
				int mon = c[i];

				if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
				{
					if (a[j] >31 || b[j]>31)
						return 0;
					else
						return 1;
				}
				else
				{
					if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
					{
						if (a[j]>30 || b[j]>30)
							return 0;
						else
							return 1;
					}
					else
						if (mon == 2)
						{
							if (a[j + 2] % 4 == 0)
							{
								if (a[j]>29 || b[j]>29)
									return 0;
								else
									return 1;
							}
							else
							{
								if (a[j]>28 || b[j]>28)
									return 0;
								else
									return 1;
							}
						}
				}
			}
		}
	}
}










