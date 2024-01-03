#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

#define DELIM " \n\t\r"

/*********string functions**********/
char *_strcat(char *dest, char *src);
char *_strdup(char *input);
int _strlen(char *input);
int _strcmp(const char *str1, const char *str2);
char *_strcpy(char *dest, char *src);

/********error functions**********/
void err_mess(int execution_count, char **argv, char *program_name);
int _putchar(char c);
char *int_to_arg(int number);

/*******user input functions*****/
void print_prompt(char *prompt);
char *get_command(void);
char **parse_input(char *buffer);
void free_argv(char **argv);

void execusioner(char **argv, char *pro_name, int execution_count, int *exit_code);
int compare(char *command, char *str);
char *in_env_path(char *command, char **env);
void *print_env_var(char **env);
char *getpath(char **env);

#endif
