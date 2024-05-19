/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** size_tool
*/

#include "block.h"
#include <math.h>

size_t calc_node_size(size_t size)
{
    size_t power = 1;

    for (power = 1; size > power; power = power << 1);
    return (power);
}

block_s *get_last_node(control_s *ctrl)
{
    ctrl->tmp = ctrl->head;
    if (ctrl->tmp == NULL)
        return (NULL);
    while (ctrl->tmp->next != NULL)
        ctrl->tmp = ctrl->tmp->next;
    return (ctrl->tmp);
}

block_s *find_data_ptr(control_s *ctrl, void *ptr)
{
    ctrl->tmp = ctrl->head;
    for (; ctrl->tmp != NULL; ctrl->tmp = ctrl->tmp->next)
        if (ctrl->tmp->data == ptr)
            return (ctrl->tmp);
    return (NULL);
}