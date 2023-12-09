#define COMMANDS_H
#ifndef  COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

#include "general.h"
#include "memory.h"
#include "error.h"
#include "builtins.h"
#include "text.h"

extern char **environ;

/* commands.c */
void analyze(char **arguments, general_t *info, char *buff);

/* permissions.c */
int is_executable(char *filename);
int is_file(char *command);

/* environment.c */
char *_getenv(const char *name);
char *which(char *filename, general_t *info);
void is_current_path(char *path, general_t *info);
void get_full_env(void);

/* execute.c */
void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_directory(char *cmd, char **arguments, char *buff,
		general_t *info);

#endif /* COMMANDS_H */
