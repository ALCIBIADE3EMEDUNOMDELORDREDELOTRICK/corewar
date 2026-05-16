/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** sort
*/

#include "../../include/header.h"

void split_list(nodes_t *source, nodes_t **front, nodes_t **back)
{
    nodes_t *fast = source->next;
    nodes_t *slow = source;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

static nodes_t *merge_sorted_id_r(nodes_t *a, nodes_t *b)
{
    nodes_t *result = NULL;

    if (!a)
        return b;
    if (!b)
        return a;
    if (((robot_t *)a->data)->id <= ((robot_t *)b->data)->id) {
        result = a;
        result->next = merge_sorted_id_r(a->next, b);
    } else {
        result = b;
        result->next = merge_sorted_id_r(a, b->next);
    }
    return result;
}

nodes_t *my_sort_id_r(nodes_t *head)
{
    nodes_t *a;
    nodes_t *b;

    if (!head || !head->next)
        return head;
    split_list(head, &a, &b);
    a = my_sort_id_r(a);
    b = my_sort_id_r(b);
    return merge_sorted_id_r(a, b);
}
