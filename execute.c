#include "commands.h"
#include "memory.h"
#include "general.h"

/**
 * execute - Execute a command in other process
 *
 * @command: Command to execute @command
 * @arguments: Arguments of the @command
 * @info: General info about  shell
 * @buff: Line readed @buff
 **/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, arguments, environ);
		perror("./sh");

		free_memory_pp((void *) arguments);

		if (info->value_path != NULL)
		{
			free(info->value_path);
			info->value_path = NULL;
		}

		free(info);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			info->status_code = WEXITSTATUS(status);
	}
}


/**
 * current_directory - Execute the command in the current directory if required.
 *
 * @cmd: Command to execute @cmd
 * @arguments: Arguments of the @cmd
 * @buff: Line readed @buff
 * @info: General info about the shell@info
 *
 * Return: Status of the operations
 **/
int current_directory(char *cmd, char **arguments, char *buff, general_t *info)
{

	if (info->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(cmd) == PERMISSIONS)
	{
		execute(cmd, arguments, info, buff);
		return (_TRUE);
	}

	return (_FALSE);
}
