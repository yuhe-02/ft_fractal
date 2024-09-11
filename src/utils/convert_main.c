#include "ft_fractal.h"

int main()
{
	const char *test_cases[] = {
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
        NULL
    };

    const char **test_case = test_cases;

    while (*test_case != NULL) {
		if (ft_is_valid_num(*test_case)){
        	printf("before: [%s] after: [%f]\n", *test_case, ft_atob(*test_case));
			printf("before: [%s] after: [%f]\n", *test_case, atof(*test_case));
		}
		else
			printf("invalid: %s\n", *test_case);
        test_case++;
    }

    return 0;
}