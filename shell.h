#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

#define HISTORY_COUNT 20
#define MAX_CMD_LEN 128
#define STAT_BUFF_SIZE 1024

/******* Function Prototypes *******/
void file(char **av);
int cd(char **av);
void free_dp(char **ptr);
char *_strtok(char *str, const char *delim);
char *_getpath(char *cmd);
char **str2arr(char *str, char *delim);
void cmd_exec(char **av, char *file_name, size_t count);
int chck_cmd(char *cmd);
void getfunc(char **av, char *f_name, size_t count);
extern char **environ;
char **str2arr(char *str, char *delim);
void err(char *error_type);
void __exit(int stat);
void print_env(void);
void non_interactive(char **env, char *f_name, int count);
char *d2s(char *dynamic_str);
void exec_cmd(char **av, char *file_name, size_t count);
void ngetfunc(char **av, char *f_name, size_t count);
void comment(char **arr);
int check_betty(void);
int main(int ac, char **av, char **env);
void interactive_mode(char **env, char *f_name);
void handle_input(char **av, char *f_name, size_t count);

/**
 * struct list - environmental variables linked list
 * @env: environmental variable
 * @next: next node
 */
typedef struct list
{
	char *env;
	struct list *next;

} list_t;

/***** helper codes *****/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, int n);
char *_strchr(const char *s, char c);
int _strcmp(char *s1, char *s2);

#endif
