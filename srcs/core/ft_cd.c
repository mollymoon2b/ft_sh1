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

#include "../../includes/ft_sh1.h"

// int 	ft_home(t_env *shell)
// {
// 	int i;

// 	i = 0;
// 	while (shell->av[i])
// 	{
// 		if (ft_namematch("HOME", shell->env[i])
// 		{
// 			shell->env[i] = ft_strjoin("HOME=", shell->env[i]);
// 			shell->env[i] = ft_get_envhome(shell->env);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (-1);
// }

static void	ft_update_env_pwd(t_env *shell)
{
	char	*tmp;

	ft_copy_env_value(shell, "PWD", "OLDPWD");
	tmp = getcwd(NULL, 0);
	ft_set_env_value(shell, "PWD", tmp);
	free(tmp);
}

static int	ft_update_cdpwd(t_env *shell)
{
	int		i;

	i = 0;
	printf("Added pwd2 = %s\n", getcwd(NULL, 0));
	while (shell->env[i])
	{
		if (ft_namematch("CDPATH", shell->env[i]))
		{
			shell->env[i] = ft_strjoin("CDPATH=", getcwd(NULL, 0));
			return (0);
		}
		++i;
	}
	shell->env = ft_char_to_inc(shell->env);
	shell->env[i] = ft_strjoin("CDPATH=", getcwd(NULL, 0));
	return (0);
}

char	*ft_rel_pwd(char *path)
{
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(NULL, 0);
	if (pwd != NULL)
	{
		pwd = ft_strjoin(pwd, "/");
		pwd = ft_strjoin(pwd, path);
	}
	printf("Returned path = '%s'\n", pwd);
	return (pwd);
}

int		ft_cd_less(t_env *shell)
{
	char *tmp;
	
	if (ft_value_exist(shell, "OLDPWD"))
	{
		ft_swap_env_value(shell, "PWD", "OLDPWD");//path = shell->oldpwd;
		tmp = ft_get_env_value(shell, "PWD");
		chdir(tmp);
		free(tmp);
	}
	else
		ft_putstr(" cd: << OLDPWD >> undefined\n");
	return (0);
}

int		ft_cd(t_env *shell)
{
	char	*path;
	int i;

	i = 0;
	if (shell->av[1])
	{
		path = (shell->av[1][0] && shell->av[1][0] != '/')
			? ft_rel_pwd(shell->av[1]) : ft_strdup(shell->av[1]);
		if (shell->av[1][0] == '-' && !shell->av[1][1])
			return (ft_cd_less(shell));
		if ((shell->av[1][0] == '-' && shell->av[1][1] == 'P')
			|| (shell->av[1][0] == '-' && shell->av[1][1] == 'L' && shell->av[1][2] == 'P')
			|| (shell->av[1][0] == '-' && shell->av[1][1] == 'P' && shell->av[1][2] == 'L')) ///Volumes/Data/nfs/zfs-student-2/users/2014/ade-bonn
		{
			if (shell->home != NULL)
				path = shell->home;
			else
				ft_putstr(" cd: << HOME P>> undefined \n");
			return (0);
		}
		if (shell->av[1][0] == '-' && shell->av[1][1] == 'L' && !shell->av[1][2]) //nfs/zfs-student-2/users/2014/ade-bonn mais aussi cd tout court
		{
			if (shell->home != NULL)
				path = shell->home;
			else
				ft_putstr(" cd: << HOME >> undefined \n");
			return (0);
		}
		if (access(path, F_OK) == 0)
		{
			printf ("Moving the path to '%s'\n", path);
			chdir(path);
			ft_update_env_pwd(shell);
			ft_update_cdpwd(shell);
			return (0);
		}
		else
			ft_error_2char(shell->av[1], ": No such file or directory\n");
	}
	return (-1);
}
