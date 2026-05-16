/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** robot draw
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

static void draw_process_regs(sfRenderWindow *win, sfFont *font,
    processus_t *p, sfVector2f *data)
{
    char buf[128];
    sfText *text = create_text(font, &(sfColor){180, 180, 180, 255});
    int row = 0;

    snprintf(buf, sizeof(buf), "Process %d   PC:%08X  carry:%d",
        (int)data->y, p->pc, p->carry);
    sfText_setFillColor(text, (sfColor){220, 220, 100, 255});
    draw_text(win, text, buf, data->x);
    sfText_setFillColor(text, (sfColor){180, 180, 180, 255});
    for (; row < 4; row++) {
        snprintf(buf, sizeof(buf),
            "r%-2d:%08X  r%-2d:%08X  r%-2d:%08X  r%-2d:%08X",
            row * 4 + 1, p->reg[row * 4], row * 4 + 2, p->reg[row * 4 + 1], row
            * 4 + 3, p->reg[row * 4 + 2], row * 4 + 4, p->reg[row * 4 + 3]);
        draw_text(win, text, buf, data->x + 22 + row * 20);
    }
    snprintf(buf, sizeof(buf), "r%-2d:%08X", 16, p->reg[15]);
    draw_text(win, text, buf, data->x + 22 + row * 20);
    sfText_destroy(text);
    draw_line(win, data->x + 130);
}

void draw_robot_detail(sfRenderWindow *win, sfFont *font,
    robot_t *r, int idx)
{
    const sfColor *color = get_color(idx);
    sfText *header = create_text(font, color);
    char buf[128];
    float y = 0;
    int pidx = 0;

    draw_text(win, header, buf, y + 6);
    sfText_destroy(header);
    draw_line(win, 40);
    y = 46;
    for (processus_t *p = r->processus; p && y + 110 <= 980; p = p->next) {
        pidx++;
        draw_process_regs(win, font, p, &(sfVector2f){y, pidx});
        y += 120;
    }
}

void draw_robots(sfRenderWindow *win, sfFont *font, corewar_t *war,
    int selected)
{
    int idx = 0;
    robot_t *target = NULL;

    for (nodes_t *n = war->robot; n; n = n->next) {
        if (idx == selected)
            target = (robot_t *)n->data;
        if (selected < 0 && idx < 6)
            draw_slot(win, font, (robot_t *)n->data, idx);
        idx++;
    }
    if (selected >= 0 && target)
        draw_robot_detail(win, font, target, selected);
    else if (selected < 0) {
        return;
    }
}
