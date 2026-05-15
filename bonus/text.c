/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** dump
*/

#include "../include/header.h"
#include "../bonus/bonus.h"

sfText *create_text(sfFont *font, const sfColor *color)
{
    sfText *t = sfText_create();

    sfText_setFont(t, font);
    sfText_setCharacterSize(t, 20);
    sfText_setFillColor(t, *color);
    return t;
}

void draw_text(sfRenderWindow *win, sfText *t, char *str, float y)
{
    sfText_setString(t, str);
    sfText_setPosition(t, (sfVector2f){1420 + 10, y});
    sfRenderWindow_drawText(win, t, NULL);
}

void draw_line(sfRenderWindow *win, float y)
{
    sfVertex line[2] = {{{1420, y}, {80, 80, 80, 255}, {0, 0}},
        {{1920, y}, {80, 80, 80, 255}, {0, 0}}};

    sfRenderWindow_drawPrimitives(win, line, 2, sfLines, NULL);
}

void draw_cycle(sfRenderWindow *win, sfFont *font, corewar_t *war)
{
    char buf[64];
    sfText *text = create_text(font, &(sfColor){220, 220, 220, 255});

    draw_line(win, 980);
    snprintf(buf, sizeof(buf), "Cycle       %d", war->current_cycle);
    draw_text(win, text, buf, 990);
    snprintf(buf, sizeof(buf), "Cycle to die  %d", war->cycle_to_die);
    draw_text(win, text, buf, 1020);
    sfText_destroy(text);
}
