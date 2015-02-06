/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_envoldpwd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 10:46:42 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/06 15:45:11 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_sh1.h"

char	*ft_get_envhome(char **env)
{
	char	*home_line;
	int		i;

	home_line = NULL;
	i = 0;
	while (env[i] && home_line == NULL)
	{
		if (ft_strncmp("HOME", env[i], 3) == 0)
			home_line = ft_strsub(ft_strdup(env[i]),
				5, ft_strlen(env[i]) - 5);
		++i;
	}
	return (home_line);
}

char	*ft_get_envoldpwd(char **env)
{
	char	*oldpwd_line;
	int		i;

	oldpwd_line = NULL;
	i = 0;
	while (env[i] && oldpwd_line == NULL)
	{
		if (ft_strncmp("OLDPWD", env[i], 5) == 0)
		{
			oldpwd_line = ft_strsub(ft_strdup(env[i]),
				7, ft_strlen(env[i]) - 7);
		}
		++i;
	}
	return (oldpwd_line);
}

char	**ft_get_envpath(char **env)
{
	char	*path_line;
	char	**path;
	int		i;

	path_line = NULL;
	path = NULL;
	i = 0;
	while (env[i] && path_line == NULL)
	{
		if (ft_strncmp("PATH", env[i], 3) == 0)
			path_line = ft_strsub(ft_strdup(env[i]),
				5, ft_strlen(env[i]) - 5);
		++i;
	}
	if (path_line != NULL)
		path = ft_strsplit(path_line, ':');
	return (path);
}

char	*ft_get_envpwd(char **env)
{
	char	*get_pwd_line;
	int		i;

	get_pwd_line = NULL;
	i = 0;
	while (env[i] && get_pwd_line == NULL)
	{
		if (ft_strncmp("PWD", env[i], 2) == 0)
			get_pwd_line = ft_strsub(ft_strdup(env[i]),
				4, ft_strlen(env[i]) - 4);
		++i;
	}
	return (get_pwd_line);
}

char	*ft_get_pwd(void)
{
	char	*pwd;

	pwd = NULL;
	if (!(pwd = (char *)malloc((MAXPATHLEN + 1) * sizeof(char))))
	{
		ft_bzero(pwd, 0);
		pwd = getcwd(pwd, MAXPATHLEN);
	}
	return (pwd);
}
