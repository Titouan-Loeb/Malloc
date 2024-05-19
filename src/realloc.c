/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** realloc
*/

#include "block.h"

void *realloc(void *ptr, size_t size)
{
    control_s *ctrl = init_control();

    if (ptr == NULL || size <= 0)
        return (malloc(size));
    ctrl->tmp = find_data_ptr(ctrl, ptr);
    if (ctrl->tmp == NULL)
        return (NULL);
    if (ctrl->tmp->size >= size) {
        ctrl->tmp->free = false;
        return (ctrl->tmp->data);
    }
    ctrl->tmp->free = true;
    return (malloc(size));
}