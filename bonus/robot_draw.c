/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** dump
*/

#include "../include/header.h"
#include "../bonus/bonus.h"

static int count_processes(robot_t *r)
{
    int count = 0;

    for (processus_t *p = r->processus; p; p = p->next)
        count++;
    return count;
}

void draw_card_info(sfRenderWindow *win, sfFont *font,
    robot_t *r, float y)
{
    char buf[64];
    sfText *text = create_text(font, &(sfColor){200, 200, 200, 255});

    snprintf(buf, sizeof(buf), "ID         %d", r->id);
    draw_text(win, text, buf, y + 30);
    snprintf(buf, sizeof(buf), "Processus  %d", count_processes(r));
    draw_text(win, text, buf, y + 55);
    sfText_setFillColor(text, r->life ?
        (sfColor){29, 158, 117, 255} : (sfColor){226, 75, 74, 255});
    snprintf(buf, sizeof(buf), "Live       %s", r->life ? "alive" : "dead");
    draw_text(win, text, buf, y + 80);
    sfText_destroy(text);
}

static void draw_slot(sfRenderWindow *win, sfFont *font,
    robot_t *r, int idx)
{
    float y = idx * 160;
    const sfColor *color = get_color(idx);
    sfText *text = create_text(font, color);

    draw_text(win, text, r->name, y + 10);
    sfText_destroy(text);
    draw_card_info(win, font, r, y);
    draw_line(win, y + 160);
}

void draw_robots(sfRenderWindow *win, sfFont *font, corewar_t *war)
{
    int idx = 0;

    for (nodes_t *n = war->robot; n; n = n->next) {
        if (idx >= 6)
            return;
        draw_slot(win, font, (robot_t *)n->data, idx);
        idx++;
    }
}
