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
	else if (sig_num == SIGVTALRM)
		ft_putstr("shell: virtual time alarm shell\n");
	else if (sig_num == SIGXCPU)
		ft_putstr("shell: cpu limit exceeded shell\n");
	else if (sig_num == SIGXCPU)
		ft_putstr("shell: size limit exceeded shell\n");
	exit(0);
}

static void			ft_sigstop(int sig_num)
{ //To handle for real
	ft_putstr("shell: suspended (signal) shell\n");
	exit(0);
	(void)sig_num;
}

static void			ft_sig_define_user(int sig_num)
{ //To handle for real
	if (sig_num == SIGUSR1)
		ft_putstr("shell: user-defined signal 1 shell\n");
	else if (sig_num == SIGUSR2)
		ft_putstr("shell: user-defined signal 2 shell\n");
	exit(0);
}

static void			ft_sigprof(int sig_num)
{ //To handle for real
	ft_putstr("shell: profile signal shell\n");
	exit(0);
	(void)sig_num;
}

static void			ft_sigtrap(int sig_num)
{ //To handle for real
	ft_putstr("shell: trace trap shell\n");
	exit(0);
	(void)sig_num;
}

void				ft_init_signals(void)
{
	signal(SIGABRT, ft_sig_to_exit);
	signal(SIGALRM, ft_sig_to_exit);
	signal(SIGBUS, ft_sig_to_exit);
	// signal(SIGCHLD, ft_sigchld); // Son died // ZSH PRINT NOTHING WITHOUT EXEC
	// signal(SIGCONT, ft_sigcont); // Wake up (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGFPE, ft_sig_to_exit);
	signal(SIGHUP, ft_sig_to_exit);
	signal(SIGILL, ft_sig_to_exit);
	signal(SIGINT, ft_sig_to_reload);
	signal(SIGKILL, ft_sig_to_exit);
	signal(SIGPIPE, ft_sig_to_exit);
	// signal(SIGQUIT, ft_sigquit); // UNKNOWN // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGSEGV, ft_sig_to_exit);
	signal(SIGSTOP, ft_sigstop); // Stop (fg)
	signal(SIGTERM, ft_sigterm);
	// signal(SIGTSTP, ft_sigtstp); // Break (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	// signal(SIGTTIN, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	// signal(SIGTTOU, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGUSR1, ft_sig_define_user); // UNKNOWN
	signal(SIGUSR2, ft_sig_define_user); // UNKNOWN
	// signal(SIGPOLL, ft_sigpoll); // ... // Can't be used with kill
	signal(SIGPROF, ft_sigprof); // Pthread -> Plus tard
	signal(SIGSYS, ft_sig_to_reload);
	signal(SIGTRAP, ft_sigtrap); // Do not set
	// signal(SIGURG, ft_sigurg); // Server, may not have to be set // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGVTALRM, ft_sig_to_exit); // Time related
	signal(SIGXCPU, ft_sig_to_exit); // Time out
	signal(SIGXFSZ, ft_sig_to_exit); // Max file size
}