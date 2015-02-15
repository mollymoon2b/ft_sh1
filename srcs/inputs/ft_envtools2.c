#include "../../includes/ft_sh1.h"

// arthur

void		ft_set_env_value(t_env *shell, char *name, char *value)
{
	char	**ptr;
	int		len;

	len = ft_strlen(name);
	ptr = ft_get_env_addr(shell, name);
	if (ptr)
		free(*ptr);
	if (!(*ptr = (char *)malloc(sizeof(char) * len + ft_strlen(value) + 2)))
		return ;
	ft_strcpy(*ptr, name);
	ft_strcpy(*ptr + len++, "=");
	ft_strcpy(*ptr + len++, value);
	*(*ptr + len + ft_strlen(value)) = '\0';
}

void		ft_copy_env_value(t_env *shell, char *src, char *dst)
{
	char	*tmp;

	if (!(tmp = ft_get_env_value(shell, src)))
		return ;
	ft_set_env_value(shell, dst, tmp);
	free(tmp);
}

void		ft_swap_env_value(t_env *shell, char *src, char *dst)
{
	char	*srccpy;
	char	*dstcpy;

	if (!(srccpy = ft_get_env_value(shell, src)))
		return ;
	if (!(dstcpy = ft_get_env_value(shell, dst)))
	{
		free(srccpy);
		return ;
	}
	ft_set_env_value(shell, dst, srccpy);
	ft_set_env_value(shell, src, dstcpy);
	free(srccpy);
	free(dstcpy);
}