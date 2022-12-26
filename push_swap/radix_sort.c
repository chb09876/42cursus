#include "radix_sort.h"
#include "operation.h"
#include "utils.h"
#include <stdio.h>

#define DEBUG 0

static int check_rotate(t_stack *stack, int level, int radix);
static void chunking(t_stack *a, t_stack *b, int pivot);
static void print_info(t_stack *a, t_stack *b);
static int get_digit(int num, int level, int radix);

int radix_sort_binary_three_chunk(t_stack *a, t_stack *b, int *sorted, int size)
{
	int level = 0;
	int tmp;
	t_node *node;
	int max = 256;
	int mid = 128;

	// printf("[%d]", size);
	// print_info(a, b);
	// small to b
	while (a->size > max)
	{
		if (a->top->data < size - max)
		{
			op_push(a, b, "pb\n");
		}
		else
		{
			op_rotate(a, "ra\n");
		}
	}
	// then make small a index
	node = a->bottom;
	while (node)
	{
		node->data -= size - max;
		// printf("%d ", node->data);
		node = node->next;
	}
	print_info(a, b);

	// // sort a
	while (level < sizeof(int) * 8)
	{
		if (check_rotate(a, level, 2))
		{
			tmp = a->size;
			while (tmp > 0)
			{
				if (get_digit(a->top->data, level, 2) != 1)
				{
					op_push(a, b, "pb\n");
					print_info(a, b);
				}
				else if (a->size > 1)
				{
					op_rotate(a, "ra\n");
					print_info(a, b);
				}
				--tmp;
			}
			// Push b to stack a
			tmp = b->size - (size - max);
			while (tmp > 0)
			{
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
	}
	// printf("sort a is done\n");

	// sort b
	level = 0;
	while (level < sizeof(int) * 8)
	{
		if (check_rotate(b, level, 2))
		{
			tmp = b->size;
			while (tmp > 0)
			{
				if (get_digit(b->top->data, level, 2) == 1)
				{
					op_push(b, a, "pa\n");
					print_info(a, b);
				}
				else if (b->size > 1)
				{
					op_rotate(b, "rb\n");
					print_info(a, b);
				}
				--tmp;
			}
			// Push a to stack b
			tmp = a->size - max;
			while (tmp > 0)
			{
				op_push(a, b, "pb\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
	}

	while (b->size)
	{
		op_push(b, a, "pa\n");
		print_info(a, b);
	}
}

int radix_sort_ternary_two_chunk(t_stack *a, t_stack *b, int *sorted, int size)
{
	int level = 0;
	int tmp = a->size;
	int small_chunk_size = 0;
	int rb_flag = 0;
	int max = 243;
	t_node *node;

	while (a->size > max)
	{
		if (a->top->data < size - max)
		{
			op_push(a, b, "pb\n");
		}
		else
		{
			op_rotate(a, "ra\n");
		}
	}
	// then make small a index
	node = a->bottom;
	while (node)
	{
		node->data -= size - max;
		// printf("%d ", node->data);
		node = node->next;
	}
	print_info(a, b);
	while (level < sizeof(int) * 8)
	{
		if (check_rotate(a, level, 3))
		{
			tmp = a->size;
			small_chunk_size = 0;
			while (tmp > 0)
			{
				if (get_digit(a->top->data, level, 3) < 2)
				{
					if (rb_flag)
					{
						op_rotate(b, "rb\n");
						rb_flag = 0;
					}
					op_push(a, b, "pb\n");
					--tmp;
					print_info(a, b);
					// printf("sig: %d\n", get_digit(b->top->data, level, 3));
					if (get_digit(b->top->data, level, 3) < 1)
					{
						++small_chunk_size;
						if (tmp != 0)
						{
							// printf("rb flag ON!\n");
							rb_flag = 1;
						}
						else
							op_rotate(b, "rb\n");
						// print_info(a, b);
					}
				}
				else
				{
					// printf("[%d %d]\n", a->top->data, (0b1 << level));
					// to prevent idling
					if (rb_flag)
					{
						op_rotate_same(a, b, "rr\n");
						rb_flag = 0;
					}
					else
						op_rotate(a, "ra\n");
					--tmp;
					print_info(a, b);
				}
				// printf("tmp!\n");
			}
			// Push middle chunk to stack a
			tmp = b->size - small_chunk_size;
			while (tmp > 0)
			{
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
			// Push small chunk to stack a
			tmp = b->size;
			while (tmp > 0)
			{
				op_rrotate(b, "rrb\n");
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
		// printf("a size: %d\n", a->size);
		// printf("b size: %d\n", b->size);
	}
}

int radix_sort_binary_two_chunk(t_stack *a, t_stack *b, int *sorted, int size)
{
	int level = 0;
	int tmp;
	t_node *node;
	int max = 256;

	// printf("[%d]", size);
	// print_info(a, b);
	// small to b
	while (a->size != max)
	{
		if (a->top->data < size - max)
		{
			op_push(a, b, "pb\n");
		}
		else
		{
			op_rotate(a, "ra\n");
		}
	}
	// then make small a index
	node = a->bottom;
	while (node)
	{
		node->data -= size - max;
		// printf("%d ", node->data);
		node = node->next;
	}
	print_info(a, b);

	// // sort a
	while (level < sizeof(int) * 8)
	{
		if (check_rotate(a, level, 2))
		{
			tmp = a->size;
			while (tmp > 0)
			{
				if (get_digit(a->top->data, level, 2) != 1)
				{
					op_push(a, b, "pb\n");
					print_info(a, b);
				}
				else if (a->size > 1)
				{
					op_rotate(a, "ra\n");
					print_info(a, b);
				}
				--tmp;
			}
			// Push b to stack a
			tmp = b->size - (size - max);
			while (tmp > 0)
			{
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
	}
	// printf("sort a is done\n");

	// sort b
	level = 0;
	while (level < sizeof(int) * 8)
	{
		if (check_rotate(b, level, 2))
		{
			tmp = b->size;
			while (tmp > 0)
			{
				if (get_digit(b->top->data, level, 2) == 1)
				{
					op_push(b, a, "pa\n");
					print_info(a, b);
				}
				else if (b->size > 1)
				{
					op_rotate(b, "rb\n");
					print_info(a, b);
				}
				--tmp;
			}
			// Push a to stack b
			tmp = a->size - max;
			while (tmp > 0)
			{
				op_push(a, b, "pb\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
	}

	while (b->size)
	{
		op_push(b, a, "pa\n");
		print_info(a, b);
	}
}

int radix_sort_binary(t_stack *a, t_stack *b, int *sorted, int size)
{
	int level = 0;
	int tmp;

	while (level < sizeof(int) * 8)
	{
		if (check_rotate(a, level, 2))
		{
			tmp = a->size;
			while (tmp > 0)
			{
				if (get_digit(a->top->data, level, 2) != 1)
				{
					op_push(a, b, "pb\n");
					print_info(a, b);
				}
				else if (a->size > 1)
				{
					op_rotate(a, "ra\n");
					print_info(a, b);
				}
				// printf("tmp!\n");
				--tmp;
			}

			// Push b to stack a
			tmp = b->size;
			while (tmp > 0)
			{
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
		// printf("a size: %d\n", a->size);
		// printf("b size: %d\n", b->size);
	}
}

int radix_sort_ternary(t_stack *a, t_stack *b, int *sorted, int size)
{
	int level = 0;
	int tmp = a->size;
	int small_chunk_size = 0;
	int rb_flag = 0;

	// printf("start!\n");
	// print_info(a, b);
	// sort stack a
	while (level < sizeof(int) * 8)
	{
		if (check_rotate(a, level, 3))
		{
			tmp = a->size;
			small_chunk_size = 0;
			while (tmp > 0)
			{
				if (get_digit(a->top->data, level, 3) < 2)
				{
					if (rb_flag)
					{
						op_rotate(b, "rb\n");
						rb_flag = 0;
					}
					op_push(a, b, "pb\n");
					--tmp;
					print_info(a, b);
					// printf("sig: %d\n", get_digit(b->top->data, level, 3));
					if (get_digit(b->top->data, level, 3) < 1)
					{
						++small_chunk_size;
						if (tmp != 0)
						{
							// printf("rb flag ON!\n");
							rb_flag = 1;
						}
						else
							op_rotate(b, "rb\n");
						// print_info(a, b);
					}
				}
				else
				{
					// printf("[%d %d]\n", a->top->data, (0b1 << level));
					// to prevent idling
					if (rb_flag)
					{
						op_rotate_same(a, b, "rr\n");
						rb_flag = 0;
					}
					else
						op_rotate(a, "ra\n");
					--tmp;
					print_info(a, b);
				}
				// printf("tmp!\n");
			}

			// Push middle chunk to stack a
			tmp = b->size - small_chunk_size;

			while (tmp > 0)
			{
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
			// Push small chunk to stack a
			tmp = b->size;
			while (tmp > 0)
			{
				op_rrotate(b, "rrb\n");
				op_push(b, a, "pa\n");
				print_info(a, b);
				--tmp;
			}
		}
		++level;
		// printf("a size: %d\n", a->size);
		// printf("b size: %d\n", b->size);
	}
}

static void print_info(t_stack *a, t_stack *b)
{
	if (DEBUG)
	{
		printf("[a]");
		print_stack(a);
		printf("[b]");
		print_stack(b);
	}
}

static int check_rotate(t_stack *stack, int level, int radix)
{
	t_node *node = stack->bottom;
	int flag;

	if (stack->size == 0)
		return (0);
	node = stack->bottom;
	flag = get_digit(node->data, level, radix);
	node = node->next;
	while (node)
	{
		if (flag != get_digit(node->data, level, radix))
			return (1);
		node = node->next;
	}
	return (0);
}

static void chunking(t_stack *a, t_stack *b, int pivot)
{
	int tmp = a->size;

	while (tmp > 0)
	{
		if (a->top->data < pivot)
		{
			op_push(a, b, "pb\n");
		}
		--tmp;
	}
}

static int get_digit(int num, int level, int radix)
{
	// printf("!![%d]", num / ft_pow(radix, level) % radix);
	return (num / ft_pow(radix, level) % radix);
}
