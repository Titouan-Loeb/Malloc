/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** free
*/

#include "block.h"

void free(void *ptr)
{
    control_s *ctrl = init_control();

    if (ptr == NULL)
        return;
    ctrl->tmp = find_data_ptr(ctrl, ptr);
    if (ctrl->tmp != NULL)
        ctrl->tmp->free = true;
}