/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** block
*/

#ifndef BLOCK_H_
#define BLOCK_H_

#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>


#define SIZE_PAGE sysconf(_SC_PAGE_SIZE)

// typedef struct block_t *block;

typedef struct block_t
{
    size_t size;
    struct block_t *next;
    int free;
    void *data;
} block_s;

typedef struct control_t
{
    block_s *head;
    block_s *tmp;
} control_s;

void *create_node(control_s *ctrl, size_t size);
control_s *init_control(void);
void *seekfree(control_s *ctrl, size_t size);
void add_enough_space(control_s *ctrl, size_t size);
block_s *get_last_node(control_s *ctrl);
size_t calc_node_size(size_t size);
block_s *find_data_ptr(control_s *ctrl, void *ptr);

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !BLOCK_H_ */
