/*
** EPITECH PROJECT, 2021
** Malloc
** File description:
** reallocarray
*/

#include "block.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    control_s *ctrl = init_control();

    if (ptr == NULL || size * nmemb <= 0)
        return (malloc(size * nmemb));
    ctrl->tmp = find_data_ptr(ctrl, ptr);
    if (ctrl->tmp == NULL)
        return (NULL);
    if (ctrl->tmp->size >= size * nmemb) {
        ctrl->tmp->free = false;
        return (ctrl->tmp->data);
    }
    ctrl->tmp->free = true;
    return (malloc(size * nmemb));
}