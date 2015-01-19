
#include <stdlib.h>
#include <sys/param.h>
#include <unistd.h>
#include "libft/libft.h"
#include "ft_minishell.h"

char	*ft_get_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	pwd = (char *)malloc((MAXPATHLEN + 1) * sizeof(char));
	if (pwd != NULL)
	{
		ft_bzero(pwd, 0);
		pwd = getcwd(pwd, MAXPATHLEN);
	}
	return (pwd);
}
