#include "ft_fractal.h"

static int check_decimal(const char *str, int minus_flg)
{
	int i;
	int num_flg;

	i = 0;
	num_flg = FT_FALSE;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (FT_FALSE);
		if (str[i] != '0')
			num_flg = FT_TRUE;
		i++;
	}
	if (minus_flg)
		return (num_flg);
	return (FT_TRUE);
}

static int ft_check_validity(int c, int stil_flg, int *num_flg, int minus_flg)
{
	if (c != '0')
		*num_flg = FT_TRUE;
	if ((!(*num_flg)) && stil_flg)
		return (FT_FALSE);
	if ((!(*num_flg)) && !(stil_flg) && minus_flg)
		return (FT_FALSE);
	return (FT_TRUE);
}
static int check_integer(const char *str, int len)
{
	int num_flg;
	int	i;
	int minus_flg;
	
	num_flg = 0;
	minus_flg = 0;
	i = 0;
	if (str[i] == '-')
		minus_flg = 1;
	while (i + minus_flg < len)
	{
		if (ft_is_num(str[i + minus_flg]))
		{
			if (!ft_check_validity(str[i + minus_flg], len - i - minus_flg - 1 , &num_flg, minus_flg))
				return (FT_FALSE);
		} 
		else
			return (FT_FALSE);
		i++;
	}
	return (FT_TRUE);
}


int	ft_is_valid_num(const char *str)
{
	char	*decimal_place;
	char	*str2;
	int		ans;

	str2 = ft_delete_space(str);
	decimal_place = ft_strchr(str2, '.');
	ans = FT_TRUE;
	if (!*str2)
		ans = FT_FALSE;
	else if (decimal_place == 0)
		ans = check_integer(str2, ft_strlen(str2));
	else if (ft_strncmp(str2, "-0.", 3) == 0 && str2[3])
		ans = check_decimal(decimal_place + 1, FT_TRUE);
	else if (decimal_place && !(*(decimal_place + 1)))
		ans = FT_FALSE;
	else if (decimal_place != ft_strrchr(str2, '.'))
		ans = FT_FALSE;
	else if (!check_integer(str2, decimal_place - str2))
		ans = FT_FALSE;
	else if (!check_decimal(decimal_place + 1, FT_FALSE))
		ans = FT_FALSE;
	free(str2);
	return (ans);
}

// void check(char *str, int expected)
// {
// 	int ans = ft_is_valid_num(str);
// 	char *res = "OK";
// 	if (ans != expected)
// 		res = "KO";
// 	printf("test case: %s result: %s ans: %d\n", str, res, ans);
		
// }

// #include <stdio.h>
// int main()
// {
// 	check("10.000", FT_TRUE);
// 	check("100.000", FT_TRUE);
// 	check("0.000", FT_TRUE);
// 	check("90.000", FT_TRUE);
// 	check("909.000", FT_TRUE);
// 	check("10", FT_TRUE);
// 	check("0", FT_TRUE);
// 	check("90", FT_TRUE);
// 	check("909", FT_TRUE);
// 	check("-10.000", FT_TRUE);
// 	check("-90.000", FT_TRUE);
// 	check("-909.000", FT_TRUE);
// 	check(" 0.000 ", FT_TRUE);
// 	check(" 0.99  ", FT_TRUE);
// 	check(" 99  ", FT_TRUE);
// 	check(" 0.09  ", FT_TRUE);
// 	check(" -0.0001  ", FT_TRUE);

// 	check("010.000", FT_FALSE);
// 	check("-0.000", FT_FALSE);
// 	check("000.000", FT_FALSE);
// 	check("-010.000", FT_FALSE);
// 	check("-0010.000", FT_FALSE);
// 	check("-0000.000", FT_FALSE);
// 	check("0000.000", FT_FALSE);
// 	check("00a0.000", FT_FALSE);
// 	check("a.000", FT_FALSE);
// 	check("0a.000 ", FT_FALSE);
// 	check("-0 a.000", FT_FALSE);
// 	check("  -0   ", FT_FALSE);	
// 	check("  -0.   ", FT_FALSE);	
// 	check("  0.   ", FT_FALSE);	
// 	check("  0.a   ", FT_FALSE);
// 	check("  -0.000   ", FT_FALSE);
// }