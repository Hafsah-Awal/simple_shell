#include "head.h"

/**
 * print_history - prints the command history list,
 * one command per line,  with line numbers starting at 0.
 * @info: pointer to a struct containing potential arguments.
 * Return: Always returns 0.
 */

int print_history(info_t *info)
{
	print_list_t(info->history);
	return (0);
}

/**
 * alias_unset - removes an alias from the alias list
 * @info: parameter struct
 * @str: string to assign as an alias
 * Return: Always 0 on success, 1 on error
 */

int alias_unset(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * alias_set - assigns an alias to a string
 * @info: pointer to parameter struct
 * @str: string to assign as an alias
 * Return: 0 on success, 1 on error
 */

int alias_set(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (alias_unset(info, str));

	alias_unset(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * alias_print - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */

int alias_print(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * handle_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int handle_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			alias_print(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			alias_set(info, info->argv[i]);
		else
	alias_print(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

