#include "push_swap.h"

int	num_check_wq(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 9 && str[i] <= 13) || str[i] == 34 || str[i] == '+' || str[i] == '-'))
		{	
			write (1, "input error", 10);
			return (0);
		}
		i++;
	}
	return (1);	
}

int	*parse_wq(char *str)
{
	char	**carr;
	int		*iarr;
	int		count;
	int		i;
	int		j;
	
	if (!(num_check_wq(str)))
		return (NULL);
	carr = ft_split(str, ' ');
	count = 0;
	while (carr[count])
		count++;
	iarr = malloc(sizeof(int) * count + 1);
	if (!iarr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		iarr[i] = ft_atoi(carr[i]);
		i++;
	}	
return (iarr);
}

int	has_doubles(int	*arr)
{
	int	i;
	int j;

	i = 0;
	while (arr[i])
	{
		while (arr[j])
		{
			if (arr[i] = arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
