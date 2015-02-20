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
	ft_putstr(shell->name_shell);
	if (sig_num == SIGABRT)
		ft_putstr(": abort ");
	else if (sig_num == SIGALRM)
		ft_putstr(": ti");
	else if (sig_num == SIGBUS)
		ft_putstr(": bus error ");
	else if (sig_num == SIGFPE)
		ft_putstr(": floating point exception ");
	else if (sig_num == SIGHUP || sig_num == SIGPIPE)
		exit(0);
	else if (sig_num == SIGKILL)
		ft_putstr(": killed ");
	else if (sig_num == SIGILL)
		ft_putstr(": illegal hardware instruction ");
	else if (sig_num == SIGSEGV)
		ft_putstr(": segmentation fault ");
	else if (sig_num == SIGVTALRM)
		ft_putstr(": virtual time alarm ");
	else if (sig_num == SIGXCPU)
		ft_putstr(": cpu limit exceeded ");
	else if (sig_num == SIGXCPU)
		ft_putstr(": size limit exceeded ");
	ft_putstr(shell->name_process);
	ft_putchar('\n');
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

void				ft_save_signals(t_env *shell)
{
	shell->sigabrt = signal(SIGABRT, ft_sig_to_exit);
	shell->sigalrm = signal(SIGALRM, ft_sig_to_exit);
	shell->sigbus = signal(SIGBUS, ft_sig_to_exit);
	// shell->sig = // signal(SIGCHLD, ft_sigchld); // Son died // ZSH PRINT NOTHING WITHOUT EXEC
	// shell->sig = // signal(SIGCONT, ft_sigcont); // Wake up (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	shell->sigfpe = signal(SIGFPE, ft_sig_to_exit);
	shell->sighup = signal(SIGHUP, ft_sig_to_exit);
	shell->sigill = signal(SIGILL, ft_sig_to_exit);
	shell->sigint = signal(SIGINT, ft_sig_to_reload);
	shell->sigkill = signal(SIGKILL, ft_sig_to_exit);
	shell->sigpipe = signal(SIGPIPE, ft_sig_to_exit);
	// shell->sig = // signal(SIGQUIT, ft_sigquit); // UNKNOWN // ZSH PRINT NOTHING WITHOUT EXEC
	shell->sigsegv = signal(SIGSEGV, ft_sig_to_exit);
	shell->sigstop = signal(SIGSTOP, ft_sigstop); // Stop (fg)
	shell->sigterm = signal(SIGTERM, ft_sigterm);
	// shell->sig = // signal(SIGTSTP, ft_sigtstp); // Break (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	// shell->sig = // signal(SIGTTIN, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	// shell->sig = // signal(SIGTTOU, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	shell->sigusr1 = signal(SIGUSR1, ft_sig_define_user); // UNKNOWN
	shell->sigusr2 = signal(SIGUSR2, ft_sig_define_user); // UNKNOWN
	// shell->sig = // signal(SIGPOLL, ft_sigpoll); // ... // Can't be used with kill
	shell->sigprof = signal(SIGPROF, ft_sigprof); // Pthread -> Plus tard
	shell->sigsys = signal(SIGSYS, ft_sig_to_reload);
	shell->sigtrap = signal(SIGTRAP, ft_sigtrap); // Do not set
	// shell->sig = // signal(SIGURG, ft_sigurg); // Server, may not have to be set // ZSH PRINT NOTHING WITHOUT EXEC
	shell->sigvtalrm = signal(SIGVTALRM, ft_sig_to_exit); // Time related
	shell->sigxcpu = signal(SIGXCPU, ft_sig_to_exit); // Time out
	shell->sigxfsz = signal(SIGXFSZ, ft_sig_to_exit); // Max file size
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