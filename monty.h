#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Functionality */
void add(stack_t **sp, unsigned int line_pointer);
void clean_ops(instruction_t *ops[], size_t size_ops);
void create_ops(instruction_t **ops);
void free_stack(stack_t *head);
void nop(stack_t **sp, unsigned int line_pointer);
void pall(stack_t **sp, unsigned int line_pointer);
void pint(stack_t **sp, unsigned int line_pointer);
void pop(stack_t **sp, unsigned int line_pointer);
void push(stack_t **sp, unsigned int line_number);
void run_monty(stack_t **sp, FILE *fp, unsigned int line_number);
size_t stack_len(stack_t *h);
void swap(stack_t **sp, unsigned int line_pointer);

/* Error Handlers */
void cant_pint(unsigned int line_number);
void cant_pop(unsigned int line_number);
int cant_push(unsigned int line_number);
void cant_swap_add(unsigned int line_number, char *opcode);
int file_openerror(char *filename, FILE *file_pointer);
int invalid_instruction(unsigned int line_number, char *opcode);
void memory_error(stack_t *node);
int _noargs(int number_ofargs);

/* Utilities */
void concat_withsep(char *dest, char *s1, char *s2, char sep);
void del_twspace(char *s);
void free_args(char **args);
/* int free_null(char *dstr); */
int _isdigit(int c);
int _isnum(char *str);
int _len_args(char **args);
void normalize_wspace(char *_str);
char *read_line(FILE *fp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strlen(char *s);
char *_strncpy(char *dest, char *src, size_t n);
char *_strstr(char *haystack, char *needle);
char **_strtok(char *_str, const char *_delim);

extern char **arguments;

#endif
