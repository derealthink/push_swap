#include "push_swap.h"

int main(void)
{
	char *str1;
	char *str2;

	str1 = "01 -2 9 89 123 4 -8765";
	str2 = "08s chf 98a 78 0-090";

	printf ("num_check_wq :\n");
	printf("%d\n", num_check_wq(str1));
	printf("%d\n", num_check_wq(str2));

	printf ("arg_count :\n");
	printf("%d\n", arg_count(str1));
	printf("%d\n", arg_count(str2));

	return (0);
}