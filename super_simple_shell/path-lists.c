#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 4096

/**
 * struct node_t - a list of the files contained in PATH
 * @data: PATH directories
 * @next: pointer to the next node
 */
typedef struct node_t
{
	char data[MAX_PATH_LENGTH];
	struct node_t *next;
} list;

void freeList(list *head);

/**
 * path_lists - builds a linked list of the PATH directories.
 * in the environment variable PATH one directory per line
 * Return: head of the list
 */
list *path_lists(void)
{
	char *path_env = getenv("PATH");
	char *path_copy, *token;
	list *head = NULL;

	/* Check if PATH environment variable is not found */
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found.\n");
		return (NULL);
	}

	/* Create a copy of PATH to avoid modifying the original */
	path_copy = strdup(path_env);
	token = strtok(path_copy, ":");

	/* Traverse the PATH components and build the linked list */
	while (token != NULL)
	{
		list *newNode = (list *)malloc(sizeof(list));

	/* Check if memory allocation for the new node failed */
		if (newNode == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed.\n");
			freeList(head);
			return (NULL);
		}

		/* Copy the current PATH component to the new node */
		strcpy(newNode->data, token);
		newNode->next = head;
		head = newNode;
		token = strtok(NULL, ":");
	}

	/* Free the memory allocated for the copy of PATH */
	free(path_copy);
	return (head);
}

/**
 * freeList - frees the memory occupied by the linked list.
 * @head: Pointer to the head of the linked list.
 */
void freeList(list *head)
{
	while (head != NULL)
	{
		list *temp = head;

		head = head->next;
		free(temp);
	}
}

/**
 * main - check the code
 *
 * Return: 0 SUCCESS
 */
int main(void)
{
	/*Build the linked list of PATH directories*/
	list *pathList = path_lists();

	/*Print the linked list*/
	list *current = pathList;

	while (current != NULL)
	{
		printf("%s\n", current->data);
		current = current->next;
	}

	/*Free the memory occupied by the linked list*/
	freeList(pathList);

	return (0);
}
