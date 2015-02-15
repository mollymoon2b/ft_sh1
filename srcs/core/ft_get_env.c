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

#include "../../includes/ft_sh1.h"

// kind of done

char	*ft_get_envhome(char **env)
{
	char	*home_line;
	int		i;

	home_line = NULL;
	i = 0;
	while (env[i] && home_line == NULL)
	{
		if (ft_namematch("HOME", env[i]))
			home_line = ft_strdup(env[i] + 5);/*ft_strsub(ft_strdup(env[i]),
				5, ft_strlen(env[i]) - 5);*/
		++i;
	}
	return (home_line);
}

// char	*ft_get_envoldpwd(char **env)
// {
// 	char	*oldpwd_line;
// 	int		i;

// 	oldpwd_line = NULL;
// 	i = 0;
// 	while (env[i] && oldpwd_line == NULL)
// 	{
// 		if (ft_namematch("OLDPWD", env[i]))
// 		{
// 			oldpwd_line = ft_strdup(env[i] + 7);/*ft_strsub(ft_strdup(env[i]),
// 				7, ft_strlen(env[i]) - 7);*/
// 		}
// 		++i;
// 	}
// 	return (oldpwd_line);
// }

char	**ft_get_envpath(t_env *shell)
{
	char	*path_line;
	char	**path;

	path_line = ft_get_env_value(shell, "PATH");
	path = NULL;
	if (path_line != NULL)
	{
		path = ft_strsplit(path_line, ':');
		free(path_line);
	}
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
		if (ft_namematch("PWD", env[i]))
			get_pwd_line = ft_strdup(env[i] + 4);
			/*ft_strsub(ft_strdup(env[i]), 4, ft_strlen(env[i]) - 4);*/
		++i;
	}
	return (get_pwd_line);
}

char	*ft_get_pwd(void)
{
	return (getcwd(NULL, 0));
}
