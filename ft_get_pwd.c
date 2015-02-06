
#include <stdlib.h>
#include <sys/param.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_minishell.h"

char	*ft_get_pwd(void)
{

	// pwd = NULL;
	// printf("1\n");
	// if (!(pwd = (char *)ft_memalloc((MAXPATHLEN + 1) * sizeof(char))))
	// 	return (NULL);
	// printf("2\n");
	// pwd = getcwd(pwd, MAXPATHLEN);
	// printf("CD = '%s'\n", pwd);
	return (getcwd(NULL, 0));
}
