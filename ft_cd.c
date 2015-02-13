/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-bonn <ade-bonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 13:26:24 by ade-bonn          #+#    #+#             */
/*   Updated: 2015/02/13 17:18:09 by ade-bonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "libft/libft.h"

size_t	ft_strfcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

void	ft_add_env(char *str, char *elem, t_env *e)
{
	size_t size;
	char **ptr;
	char **ne;
	char **nptr;
	char *tmp;

	size = 0;
	ptr = e->env;
    while (*ptr++)
		size++;
	if (!(ne = (char **)ft_memalloc(sizeof(char *) * size + 1)))
		return ;
	nptr = ne;
	ptr = e->env;
	while (*ptr)
		*nptr++ = *ptr++;
	tmp = ft_strjoin(str, "=");
	*nptr = ft_strjoin(tmp, elem);
	free(tmp);
	free(e->env);
	e->env = ne;
}

void	ft_set_env(char *str, char *elem, t_env *e)
{
	char **ptr;
	size_t len;
	char *tmp;
	char *p;

	len = ft_strlen(str);
    ptr = e->env;
    while (*ptr)
    {
		if (!ft_strfcmp(str, *ptr) && *(*ptr + len) == '=')
		{
			p = ft_strchr(*ptr, '=');
			*p = '\0';
			tmp = ft_strjoin(*ptr, "=");
			free(*ptr);
			*ptr = ft_strjoin(tmp, elem);
//			*ptr = ft_strdup(elem);
			free(tmp);
		}
        ptr++;
    }
    ft_add_env(str, elem, e);
}

char	*ft_get_env2(char *str, t_env *e)
{
	char **ptr;
	size_t len;

	len = ft_strlen(str);
	ptr = e->env;
	while (*ptr)
	{
		if (!ft_strfcmp(str, *ptr) && *(*ptr + len) == '=')
			return (*ptr + len + 1);
		ptr++;
	}
	return (NULL);
}

int 	ft_home(t_env *shell)
{
	int i;

	i = 0;
	while (shell->av[i])
	{
		if (ft_strncmp("HOME", shell->env[i], 3) == 0)
		{
			shell->env[i] = ft_strjoin("HOME=", shell->env[i]);
			shell->env[i] = ft_get_envhome(shell->env);
			return (0);
		}
		i++;
	}
	return (-1);
}

int		ft_update_old_pwd(t_env *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp("OLDPWD", shell->env[i], 5) == 0)
		{
			printf("\e[53mshell->pwd = %s\e[0m", shell->pwd);
			shell->env[i] = ft_strdup(shell->pwd);
			shell->env[i] = ft_strjoin("OLDPWD=", shell->env[i]); //shell->env[i] == NULL
			return (0);
		}
		++i;
	}
	return (-1);
}

int		ft_update_env_pwd(t_env *shell)
{
	int		i;

	ft_update_old_pwd(shell);
	shell->oldpwd = ft_get_envoldpwd(shell->env);
	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp("PWD", shell->env[i], 2) == 0)
		{
			shell->env[i] = ft_strjoin("PWD=", getcwd(NULL, 0));
			shell->pwd = ft_get_envpwd(shell->env);
			printf("shell->pwd alice = %s", shell->pwd);
			return (0);
		}
		++i;
	}
	return (-1);
}

int		ft_updat_cdpwd(t_env *shell)
{
	int		i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strncmp("CDPATH", shell->env[i], 5) == 0)
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
	return (pwd);
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
		{
			ft_putstr("OLDPWD was : ");
			ft_putstr(ft_get_env2("OLDPWD", shell));
			ft_putstr(" and PWD was : ");
			ft_putstr(ft_get_env2("PWD", shell));
			ft_putchar('\n');
			ft_set_env("PWD", ft_get_env2("OLDPWD", shell), shell);
			ft_set_env("OLDPWD", path, shell);
			ft_putstr("OLDPWD is : ");
			ft_putstr(ft_get_env2("OLDPWD", shell));
			ft_putstr(" and PWD is : ");
			ft_putstr(ft_get_env2("PWD", shell));
			ft_putchar('\n');
			// ft_putchar('\n');
			return (0);
			/* if (shell->oldpwd != NULL)
				path = shell->oldpwd;
			else
				ft_putstr(" cd: << OLDPWD >> undefined\n");
			return (0); */
		}
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
			chdir(path);
			ft_update_env_pwd(shell);
			ft_updat_cdpwd(shell);
			return (0);
		}
		else
			ft_error_2char(shell->av[1], ": No such file or directory\n");
	}
	return (-1);
}
