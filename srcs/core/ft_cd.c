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

// if ((shell->av[1][0] == '-' && shell->av[1][1] == 'P')
// 	|| (shell->av[1][0] == '-' && shell->av[1][1] == 'L' && shell->av[1][2] == 'P')
// 	|| (shell->av[1][0] == '-' && shell->av[1][1] == 'P' && shell->av[1][2] == 'L')) ///Volumes/Data/nfs/zfs-student-2/users/2014/ade-bonn
// {
// 	if (shell->home != NULL)
// 		path = shell->home;
// 	else
// 		ft_putstr(" cd: << HOME P>> undefined \n");
// 	return (0);
// }
// if (shell->av[1][0] == '-' && shell->av[1][1] == 'L' && !shell->av[1][2]) //nfs/zfs-student-2/users/2014/ade-bonn mais aussi cd tout court
// {
// 	if (shell->home != NULL)
// 		path = shell->home;
// 	else
// 		ft_putstr(" cd: << HOME >> undefined \n");
// 	return (0);
// }

#include "../../includes/ft_sh1.h"

static char	*ft_update(t_env *shell, char *elem, char *str, char *error)
{
	char *path;

	if ((path = ft_get_env_value(shell, elem)) && access(path, F_OK) == 0)
		return (path);
	free(path);
	if ((path = ft_strdup(str)) && access(path, F_OK) == 0)
	{
		ft_set_env_value(shell, elem, path);
		return (path);
	}
	ft_putstr(error);
	free(path);
	return (NULL);
}

// static void	ft_update_env_pwd(t_env *shell)
// {
// 	char	*tmp;

// 	ft_copy_env_value(shell, "PWD", "OLDPWD");
// 	tmp = getcwd(NULL, 0);
// 	ft_set_env_value(shell, "PWD", tmp);
// 	free(tmp);
// }

/*static int	ft_update_cdpwd(t_env *shell)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = getcwd(NULL, 0);
	while (shell->env[i])
	{
		if (ft_namematch("CDPATH", shell->env[i]))
		{
			free(shell->env[i]);
			shell->env[i] = ft_strjoin("CDPATH=", tmp);
			free(tmp);
			return (0);
		}
		++i;
	}
	free(shell->env[i]);
	shell->env = ft_char_to_inc(shell->env);
	shell->env[i] = ft_strjoin("CDPATH=", tmp);
	free(tmp);
	return (0);
}*/


char	*ft_rel_pwd(t_env *shell, char *path)
{
	char	*pwd;
	char	*tmp;

	if (!(pwd = ft_get_env_value(shell, "PWD")))
		pwd = getcwd(NULL, 0);
	if (pwd)
	{
		if (!(tmp = (char *)malloc(sizeof(char) *
			(ft_strlen(pwd) + ft_strlen(path) + 2))))
			return (NULL);
		ft_strcpy(tmp, pwd);
		*(tmp + ft_strlen(pwd)) = '/';
		ft_strcpy(tmp + ft_strlen(pwd) + 1, path);
		free(pwd);
		pwd = tmp;
	}
	return (pwd);
}

int		ft_cd_less(t_env *shell)
{
	char *pwd;
	char *old;
	
	if (!(pwd = ft_get_env_value(shell, "PWD")))
	{
		if (!(pwd = shell->pwd))
			pwd = getcwd(NULL, 0);
	}
	if (!(old = ft_get_env_value(shell, "OLDPWD")))
		old = shell->oldpwd;
	if (old && !access(old, F_OK))
	{
		ft_set_env_value(shell, "PWD", old);
		ft_set_env_value(shell, "OLDPWD", pwd);
		chdir(old);
	}
	else
		ft_putstr(" cd: << OLDPWD >> undefined\n");
	free(pwd);
	free(old);
	return (0);
}

int			ft_cd_home(t_env *shell)
{
	char	*path;

	if ((path = ft_update(shell, "HOME", shell->home, 
							" cd: << HOME >> undefined\n\n")))
	{
		ft_set_env_value(shell, "PWD", path);
		chdir(path);
		free(path);
	}
	return (1);
}

char		*ft_remove_last(char *path)
{
	char	*ptr;

	if ((ptr = ft_strrchr(path, '/')))
		*path = '\0';
	return (ft_strdup(ptr));
}

int			ft_cd_normal(t_env *shell, char *path)
{
	char	*tmp;

	if (access(path, F_OK) == 0)
	{
		chdir(path);
		ft_copy_env_value(shell, "PWD", "OLDPWD");
		tmp = getcwd(NULL, 0);
		ft_set_env_value(shell, "PWD", tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

int		ft_cd(t_env *shell)
{
	char	*path;
	int i;

	i = 0;
	if (shell->av[1] && !(shell->av[1][0] == '~' && !shell->av[1][1]))
	{
		if (shell->av[1][0] == '.' && !shell->av[1][1])
			return (0);
		if (shell->av[1][0] == '-' && !shell->av[1][1])
			return (ft_cd_less(shell));
		path = (shell->av[1][0] && shell->av[1][0] != '/')
			? ft_rel_pwd(shell, shell->av[1]) : ft_strdup(shell->av[1]);
		if (!ft_cd_normal(shell, path))
			ft_error_2char(shell->av[1], ": No such file or directory\n");
		free(path);
	}
	else
		return (ft_cd_home(shell));
	return (-1);
}
