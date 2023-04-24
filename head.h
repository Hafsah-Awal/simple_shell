#ifndef HEAD_H
#define HEAD_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int check_builtin(char **command, char *buf);
void print_shell_prompt(void);
void signal_handler(int m);
char **tokenize_input(char *line);
char *check_valid_path(char **path, char *command);
char *get_full_path(char *path, char *command);
int execute_builtin_command(char **command, char *line);
void handle_exit_command(char **command, char *line);

void print_environ(void);

/* string handlers */
int string_compare(char *s1, char *s2);
int string_length(char *s);
int string_compare_2(char *s1, char *s2, int n);
char *duplicate_string(char *s);
char *find_char(char *s, char c);

void execute_command(char *cp, char **command);
char *get_path(void);
int _putchar(char c);
int print_string(char *s);
int main(int ac, char **av, char *envp[]);

/* helper function for efficient free */
void buffer_cleaner(char **buf);

struct builtin
{
	char *env;
	char *exit;
} builtin;

struct info
{
	int final_exit;
	int ln_count;
} info;

struct flags
{
	bool interactive;
} flags;

#endif /* SHELL_H */

