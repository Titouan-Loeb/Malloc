/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** init
*/

#include "block.h"

control_s *init_control(void)
{
    static control_s *ctrl_t = NULL;

    if (ctrl_t == NULL) {
        ctrl_t = sbrk(SIZE_PAGE * 2);
        ctrl_t->head = NULL;
        ctrl_t->tmp = NULL;
    }
    return (ctrl_t);
}

void *create_node(control_s *ctrl, size_t size)
{
    block_s *new_node = NULL;

    size = calc_node_size(size);
    ctrl->tmp = get_last_node(ctrl);
    if (ctrl->tmp == NULL) {
        new_node = (void *)ctrl + sizeof(control_s);
        ctrl->head = new_node;
    }
    else {
        new_node = (void *)ctrl->tmp + sizeof(block_s) + ctrl->tmp->size;
        ctrl->tmp->next = new_node;
    }
    new_node->size = size;
    new_node->next = NULL;
    new_node->free = false;
    new_node->data = (void *)new_node + sizeof(block_s);
    return (new_node->data);
}