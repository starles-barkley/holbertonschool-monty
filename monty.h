#ifndef HEADER
#define HEADER

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
		void (*f)(stack_t **stack, unsigned int data);
} instruction_t;

extern unsigned int line_count;

/*function prototypes*/
char *cmdstr(char *);
int cmdval(char *, unsigned int);
void (*get_command(char *op, unsigned int))(stack_t **, unsigned int);
void free_stack(stack_t *head);
void null_file(char *);
void null_int(unsigned int);
void count_error(void);
void null_command(char *, unsigned int);
void pint_err(unsigned int);
void pop_err(unsigned int);
void swap_err(unsigned int);
void add_err(unsigned int);
void push_m(stack_t **, unsigned int);
void pall_m(stack_t **, unsigned int);
void pint_m(stack_t **, unsigned int);
void pop_m(stack_t **, unsigned int);
void swap_m(stack_t **, unsigned int);
void add_m(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
#endif
