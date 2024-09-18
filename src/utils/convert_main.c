#include "ft_fractal.h"

int main()
{
	const char *test_cases[] = {
		"0.00",
		"34.0",
		"-0.00",
		"0,23",
		"1000000000000000000000000000000"
        "12.0002", 
        "-12.0002", 
        "0.03002333", 
        "12.2", 
        "-12.0002", 
        " 167856782.0002 ",
        " 0.0001",
        "-0.0001",
        "1e5",
        "-1e-5",
        "inf",
        "-inf",
        "NaN",
        "",
        "123abc",
        "abc123",
        "1.0.1",
        "00001.234",
        "-00001.234",
        "+00001.234",
        "1.234e10",
        "-1.234e-10",
		"324908239048.93849389",
        "-1",
        NULL
    };

    const char **test_case = test_cases;

	int count = 0;
    while (*test_case != NULL) {
		if (ft_is_valid_num(*test_case)){
			float handmade = ft_atob(*test_case);
			float origin = atof(*test_case);
			if (handmade != origin) 
			{
				printf("%d: ×\n", count);
				printf("[handmade] before: [%s] after: [%f]\n", *test_case, ft_atob(*test_case));
				printf("[origin] before: [%s] after: [%f]\n", *test_case, atof(*test_case));
			} else 
			{
				printf("%d: ○\n", count);
			}
		}
		else
			printf("invalid: %s\n", *test_case);
		count++;
        test_case++;
    }

    return 0;
}