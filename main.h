#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct s_cmd_elem - linked list element for commands
 * @path: path to command
 * @args: arguments to command
 * @next: pointer to next element
 * @prev: pointer to previous element
 */
typedef struct s_cmd_elem
{
	char *path;
	char **args;

	struct s_cmd_elem *next;
	struct s_cmd_elem *prev;
} cmd_elem_t;

/**
 * struct s_cmd - linked list for commands
 * @head: pointer to head of list
 * @tail: pointer to tail of list
 * @size: number of elements in list
 */
typedef struct s_cmd
{
	cmd_elem_t *head;
	cmd_elem_t *tail;
	int	size;
} cmd_t;

/**
 * struct s_env_elem - linked list element for environment variables
 * @name: name of environment variable
 * @value: value of environment variable
 * @next: pointer to next element
 * @prev: pointer to previous element
 */
typedef struct s_env_elem
{
	char *name;
	char *value;

	struct s_env *next;
	struct s_env *prev;
} env_elem_t;

/**
 * struct s_env - linked list for environment variables
 * @head: pointer to head of list
 * @tail: pointer to tail of list
 * @size: number of elements in list
 */
typedef struct s_env
{
	env_elem_t *head;
	env_elem_t *tail;
	int	size;
} env_t;

/**
 * struct builtin to builtin command
 * @name: name of the builtin
 * @func: function to execute builtin
 */
typedef struct builtin
{
	char *name;
	int (*func)(char **, int);
} builtin_t;

int h_env(char **env);
void h_exit(int status);
int _setenv(char **env, int args);
int _unsetenv(char **env, int args);
/*int _cd(char **env, int args);*/

void *_realloc(void *ptr, size_t size);
char **strtow(char *str, char delim);

int error(char *msg, char *arg, int status);

/* string manipulation */
char *ft_strcat(char *dest, char *src);
char *ft_strchr(char *s, char c);
int ft_strcmp(char *s1, char *s2);
char *ft_strcpy(char *dest, char *src);
int ft_strncmp(char *s1, char *s2, int n);
char *ft_strncpy(char *dest, char *src, int n);
char *ft_strdup(char *str);
int ft_strlen(char *s);
void ft_memset(char *s, char b, unsigned int n);


int	ft_atoi(const char *str);
char *ft_itoa(ssize_t value, char *base);

ssize_t _abs(ssize_t n);
void free_resources(char **line, char ***tokens);

void cmd_error(char *bin, char *cmd, char *msg, int line);

int is_buildin(char *cmd);
void execute_buildin(char **tokens, char **env,
					 char *bin, int line_nbr);

char **get_paths(char **env);
char *in_path(char *cmd, char **paths);
void free_path(char **path);
void free_line(char **line);

#endif /* MAIN_H */
