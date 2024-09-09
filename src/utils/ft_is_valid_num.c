#include "ft_fractal.h"

// static int check_decimal(const char *str)
// {

// }

static int check_integer(const char *str, int len)
{
	int i;
	int num_flg;
	
	i = 0;
	num_flg = 0;
	while (i < len)
	{
		if (i == 0 && str[i] == '-')
		{
			//
		} else if (str[i] >= '0' && str[i] <= '9')
		{
			if (str[i] != '0')
				num_flg = 1;
			if (!num_flg && i + 1 != len)
				return (0);
		} else 
			return (0);
		i++;
	}
	return (1);
}


// int	ft_is_valid_num(const char* str)
// {
// 	char *decimal_place;

// 	decimal_place = ft_strchr(str, '.');
// 	if (decimal_place == 0)
// 		return (check_integer(str, ft_strlen(str)), 1);
// 	if (decimal_place != ft_strrchr(str, '.'));
// 		return (0);
// 	if (check_integer(str, decimal_place - str), 0)
// 		return (0);
// 	if (check_decimal(str))
// 		return (0);
// 	return (1);
// }

void check(char *str, int expected, int len)
{
	int ans = check_integer(str, len);
	char *res = "OK";
	if (ans != expected)
		res = "KO";
	printf("test case: %s result: %s\n", str, res);
		
}

#include <stdio.h>
int main()
{
	check("10.000", 1, 2);
	check("100.000", 1, 3);
	check("0.000", 1, 1);
	check("90.000", 1, 2);
	check("909.000", 1, 3);
	check("10", 1, 2);
	check("0", 1, 1);
	check("90", 1, 2);
	check("909", 1, 3);
	check("-10.000", 1, 3);
	check("-0.000", 1, 2);
	check("-90.000", 1, 3);
	check("-909.000", 1, 4);
	check("010.000", 0, 3);
	check("0.000", 1, 1);
	check("000.000", 0, 3);
	check("-010.000", 0, 4);
	check("-0010.000", 0, 5);
	check("-0000.000", 0, 5);
	check("0000.000", 0, 5);
}