#include "../../includes/ft_sh1.h"

void				ft_restore_signals(t_env *shell)
{
	signal(SIGABRT, shell->sigabrt);
	signal(SIGALRM, shell->sigalrm);
	signal(SIGBUS, shell->sigbus);
	// shell->sig = // signal(SIGCHLD, ft_sigchld); // Son died // ZSH PRINT NOTHING WITHOUT EXEC
	// shell->sig = // signal(SIGCONT, ft_sigcont); // Wake up (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGFPE, shell->sigfpe);
	signal(SIGHUP, shell->sighup);
	signal(SIGILL, shell->sigill);
	signal(SIGINT, shell->sigint);
	signal(SIGKILL, shell->sigkill);
	signal(SIGPIPE, shell->sigpipe);
	// shell->sig = // signal(SIGQUIT, ft_sigquit); // UNKNOWN // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGSEGV, shell->sigsegv);
	signal(SIGSTOP, shell->sigstop); // Stop (fg)
	signal(SIGTERM, shell->sigterm);
	// shell->sig = // signal(SIGTSTP, ft_sigtstp); // Break (fg) // ZSH PRINT NOTHING WITHOUT EXEC
	// shell->sig = // signal(SIGTTIN, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	// shell->sig = // signal(SIGTTOU, ft_sig_define_user); // Not precise (Input relatif) // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGUSR1, shell->sigusr1); // UNKNOWN
	signal(SIGUSR2, shell->sigusr2); // UNKNOWN
	// shell->sig = // signal(SIGPOLL, ft_sigpoll); // ... // Can't be used with kill
	signal(SIGPROF, shell->sigprof); // Pthread -> Plus tard
	signal(SIGSYS, shell->sigsys);
	signal(SIGTRAP, shell->sigtrap); // Do not set
	// shell->sig = // signal(SIGURG, ft_sigurg); // Server, may not have to be set // ZSH PRINT NOTHING WITHOUT EXEC
	signal(SIGVTALRM, shell->sigvtalrm); // Time related
	signal(SIGXCPU, shell->sigxcpu); // Time out
	signal(SIGXFSZ, shell->sigxfsz); // Max file size
}