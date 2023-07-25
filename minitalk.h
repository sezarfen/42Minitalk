#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

#define SIGUSER1 30
#define SIGUSER2 31 // they are defined in macOS probably, but not here

int	ft_atoi(const char *str);

#endif