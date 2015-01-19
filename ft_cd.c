/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:26:24 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/01/19 13:26:58 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"
#include "libft/libft.h"

int	sh_update_old_pwd(t_env **shell)
{
	int	i;

	i = 0;
	while ((*shell)->env[i])
	{
		if (ft_strncmp("OLDPWD", (*shell)->env[i], 5) == 0)
		{
			(*shell)->env[i] = ft_strdup((*shell)->pwd);
			(*shell)->env[i] = ft_strjoin("OLDPWD=", (*shell)->env[i]);
			return (0);
		}
		++i;
	}
	return (-1);
}

void	sh_update_env_pwd(t_env **shell)
{
	int		i;

	ft_update_old_pwd(&(*shell));
	(*shell)->oldpwd = ft_get_envoldpwd((*shell)->env);
	i = 0;
	while ((*shell)->env[i])
	{
		if (ft_strncmp("PWD", (*shell)->env[i], 2) == 0)
		{
			(*shell)->env[i] = ft_strjoin("PWD=", ft_get_pwd());
			(*shell)->pwd = ft_get_envpwd((*shell)->env);
			return (0);
		}
		++i;
	}
	return (-1);
}

void	sh_updat_cdpwd(t_env **shell)
{
	int		i;

	i = 0;
	while ((*shell)->env[i])
	{
		if (ft_strncmp("CDPATH", (*shell)->env[i], 5) == 0)
		{
			(*shell)->env[i] = ft_strjoin("CDPATH=", ft_get_pwd());
			return (0);
		}
		++i;
	}
	(*shell)->env = ft_char_to_inc((*shell)->env);
	(*shell)->env[i] = ft_strjoin("CDPATH=", ft_get_pwd());
	return (0);
}

void	sh_rel_pwd(char *path)
{
	char	*pwd;

	pwd = NULL;
	pwd = ft_get_pwd();
	if (pwd != NULL)
	{
		pwd = ft_strjoin(pwd, "/");
		pwd = ft_strjoin(pwd, path);
	}
	return (pwd);
}

void	sh_cd()
{
	if ()
}
