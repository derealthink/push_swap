#include "push_swap.h"

void	num_check_wq(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9' || mtr[i] == 39 && str[i] == 34))
		{	
			perror; //write input error func.
			exit(1);
		}
		i++;
	}	
}
int	*parse_wq(char *str, int argc)
{
	char	**carr;
	int		*iarr;
	int		i;
	
	carr = ft_split(str, ' ');
	iarr = malloc(sizeof(int) * argc + 1)

}