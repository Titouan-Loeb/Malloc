/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** malloc
*/

#include "block.h"
#include <stdbool.h>

void *seekfree(control_s *ctrl, size_t size)
{
    int smallest_size = -1;
    block_s *node = NULL;

    ctrl->tmp = ctrl->head;
    for (; ctrl->tmp != NULL; ctrl->tmp = ctrl->tmp->next)
        if (ctrl->tmp->free == true && ctrl->tmp->size >= size &&
        (smallest_size == -1 || ctrl->tmp->size < smallest_size)) {
            smallest_size = ctrl->tmp->size;
            node = ctrl->tmp;
        }
    if (node != NULL) {
        node->free = false;
        return (node->data);
    }
    return (NULL);
}

void add_enough_space(control_s *ctrl, size_t size)
{
    void *end_of_alloc = NULL;
    void *end_of_page = sbrk(0);
    int size_needed = 0;

    ctrl->tmp = get_last_node(ctrl);
    if (ctrl->head == NULL)
        end_of_alloc = (void *)ctrl + sizeof(control_s);
    else
        end_of_alloc = (void *)ctrl->tmp + ctrl->tmp->size;
    while (size_needed + (int)(end_of_page - end_of_alloc) <
    size + sizeof(block_s))
        size_needed += SIZE_PAGE * 2;
    if (size_needed > 0)
        sbrk(size_needed);
}

void *malloc(size_t size)
{
    control_s *ctrl = init_control();
    void *alloc = NULL;

    if (size <= 0)
        return (NULL);
    alloc = seekfree(ctrl, size);
    if (alloc != NULL)
        return (alloc);
    add_enough_space(ctrl, calc_node_size(size));
    return (create_node(ctrl, size));
}