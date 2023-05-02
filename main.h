ifndef MAIN
define MAIN



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

/**
 * struct globals - global structure
 * @lifo: is stack or queue
 * @curr: current line
 * @arg: second CLI argument
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 */
typedef struct globals
{
	int lifo;
	unsigned int curr;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t glov;

/* opcode */
void _push(stack_t **, unsigned int);
void _pall(stack_t **, unsigned int);
void _pint(stack_t **, unsigned int);
void _pop(stack_t **, unsigned int);
void _swap(stack_t **, unsigned int);
void _queue(stack_t **, unsigned int);
void _stack(stack_t **, unsigned int);
void _add(stack_t **, unsigned int);
void _nop(stack_t **, unsigned int);
void _sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void _mul(stack_t **, unsigned int);
void _mod(stack_t **, unsigned int);
void _pchar(stack_t **, unsigned int);
void _pstr(stack_t **, unsigned int);
void _rotl(stack_t **, unsigned int);
void _rotr(stack_t **, unsigned int);

/* get */
void (*get_opcodes(char *))(stack_t **, unsigned int);

/* imported */
int _sch(char *, char);
char *_strtoky(char *, char *);
void *_realloc(void *, unsigned int, unsigned int);
void *_calloc(unsigned int, unsigned int);
int _strcmp(char *, char *);

/* doubly linked list */
stack_t *add_dnodeint_end(stack_t **, const int);
stack_t *add_dnodeint(stack_t **, const int);
void free_dlistint(stack_t *);

/* main */
void free_glov(void);

#endif
