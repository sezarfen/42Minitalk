#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# ifndef SIGUSR1
#  define SIGUSR1 30
# endif

# ifndef SIGUSR2
#  define SIGUSR2 31 // they are defined in macOS probably, but not here
# endif

#endif