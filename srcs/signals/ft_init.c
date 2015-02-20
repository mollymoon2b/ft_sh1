#include "../../includes/ft_sh1.h"

static void			ft_sig_to_reload(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	// if (shell->cpid)
		// write(0, "^C", 2);
	if (sig_num == SIGINT)
		ft_putstr("\n");
	else if (sig_num == SIGSYS)
		ft_putstr("COUCOU C'EST MOI\n");
	// ft_clean_env(shell);
	// if (shell->str)
	// {
	// 	free(shell->str);
	// 	shell->str = NULL;
	// }
	shell->index = 0;
	shell->max = 0;
	ft_putstr(shell->name);
	// ft_reboot_imput(shell);
	return ;
	(void)sig_num;
}

static void			ft_sigterm(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	ft_putstr("GladOs: Did you really try to kill me ? Hehe, no chance !\n");
	shell->index = 0;
	shell->max = 0;
	ft_putstr(shell->name);
	// ft_clean_env(shell);
	// ft_reboot_imput(shell);
	return ;
	(void)sig_num;
}

static void			ft_sig_to_exit(int sig_num)
{
	t_env			*shell;

	shell = ft_call_env(NULL);
	if (sig_num == SIGABRT)
		ft_putstr("shell: abort shell\n");
	else if (sig_num == SIGALRM)
		ft_putstr("\nshell: timeout\n");
	else if (sig_num == SIGBUS)
		ft_putstr("shell: bus error shell\n");
	else if (sig_num == SIGFPE)
		ft_putstr("shell: floating point exception shell\n");
	else if (sig_num == SIGHUP || sig_num == SIGPIPE)
		ft_putstr("");
	else if (sig_num == SIGKILL)
		ft_putstr("shell: killed shell\n");
	else if (sig_num == SIGILL)
		ft_putstr("shell: illegal hardware instruction shell\n");
	else if (sig_num == SIGSEGV)
		ft_putstr("shell: segmentation fault shell\n");
	exit(0);
}

void		ft_init_signals(void)
{
	signal(SIGABRT, ft_sig_to_exit);
	signal(SIGALRM, ft_sig_to_exit);
	signal(SIGBUS, ft_sig_to_exit);
	// signal(SIGCHLD, ft_sigchld); // Son died
	// signal(SIGCONT, ft_sigcont); // Wake up (fg)
	signal(SIGFPE, ft_sig_to_exit);
	signal(SIGHUP, ft_sig_to_exit);
	signal(SIGILL, ft_sig_to_exit);
	signal(SIGINT, ft_sig_to_reload);
	signal(SIGKILL, ft_sig_to_exit);
	signal(SIGPIPE, ft_sig_to_exit);
	// signal(SIGQUIT, ft_sigquit); // UNKNOWN
	signal(SIGSEGV, ft_sig_to_exit);
	// signal(SIGSTOP, ft_sigstop); // Stop (fg)
	signal(SIGTERM, ft_sigterm);
	// signal(SIGTSTP, ft_sigtstp); // Break (fg)
	// signal(SIGTTIN, ft_sigttin); // Not precise (Input relatif)
	// signal(SIGTTOU, ft_sigttou); // Not precise (Input relatif)
	// signal(SIGUSR1, ft_sigusr1); // UNKNOWN
	// signal(SIGUSR2, ft_sigusr2); // UNKNOWN
	// signal(SIGPOLL, ft_sigpoll); // ...
	// signal(SIGPROF, ft_sigprof);
	signal(SIGSYS, ft_sig_to_reload);
	// signal(SIGTRAP, ft_sigtrap);
	// signal(SIGURG, ft_sigurg);
	// signal(SIGVTALRM, ft_sigvtalrm);
	// signal(SIGXCPU, ft_sigxcpu);
	// signal(SIGXFSZ, ft_sigxfsz);
}