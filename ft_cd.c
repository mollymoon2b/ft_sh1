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

#include "ft_sh1.h"
#include "libft/libft.h"

int		ft_update_old_pwd(t_env **shell)
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

int		ft_update_env_pwd(t_env **shell)
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

int		ft_updat_cdpwd(t_env **shell)
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

char	*ft_rel_pwd(char *path)
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

int		ft_cd(t_env **shell)
{
	char	*path;

	if ((*shell)->av[1])
	{
		path = ((*shell)->av[1][0] && (*shell)->av[1][0] != '/')
			? ft_rel_pwd((*shell)->av[1]) : ft_strdup((*shell)->av[1]);
		if ((*shell)->av[1][0] == '-' && !(*shell)->av[1][1])
		{
			if ((*shell)->oldpwd != NULL)
				path = (*shell)->oldpwd;
			else
			{
				ft_putstr(" cd: << OLDPWD >> undefined\n");
			}
		}
		if (access(path, F_OK) == 0)
		{
			chdir(path);
			ft_update_env_pwd(shell);
			ft_updat_cdpwd(shell);
			return (0);
		}
		else
			ft_error_2char((*shell)->av[0], ": No such file or directory\n");
	}
	return (-1);
}
