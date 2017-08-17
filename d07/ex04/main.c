#include <stdio.h>

char	**ft_split_whitespaces(char *str);

int main()
{
	char a[] = "\t\tHello World!";

	char **c = ft_split_whitespaces(a);

	int i = 0;
	while (c[i])
	{
		printf("%s\n", c[i]);
		i++;
	}
	
}