#include "main.h"

/**
 * h_env - prints the environment
 * @env: environment variables
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int h_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		/* check if '=' is present */
		if (ft_strchr(env[i], '='))
		{
			/* print the env variable */
			write(STDOUT_FILENO, env[i], ft_strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		i++;
	}

	return (EXIT_SUCCESS);
}

/**
 * in_path - checks if a command is in the PATH
 * @cmd: command to check
 * @paths: paths to check
 * Return: 1 if in PATH, 0 if not
 */
char *in_path(char *cmd, char **paths)
{
	int i = 0;
	char tmp[1024];

	while (paths[i])
	{
		ft_memset(tmp, 0, 1024);
		ft_strcpy(tmp, paths[i]);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, cmd);
		if (access(tmp, F_OK) == 0)
		{
			free(cmd);
			return (ft_strdup(tmp));
		}
		i++;
	}
	return (cmd);
}

/**
 * get_paths - gets the paths from the environment
 * @env: environment variables
 * Return: paths
 */
char **get_paths(char **env)
{
	int i = 0;
	char **paths = NULL;

	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = strtow(env[i] + 5, ':');
			break;
		}
		i++;
	}

	return (paths);
}

/**
 * free_path - free path env
 * @path: pointer to path
 */
void free_path(char **path)
{
	int i;

	for (i = 0; path[i]; i++)
		free(path[i]);
	free(path);
}
