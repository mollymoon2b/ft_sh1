

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup_tabtosp(const char *str)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\t')
			dest[i] = ' ';
		else
			dest[i] = str[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
