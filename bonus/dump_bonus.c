/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** dump
*/

#include "../include/header.h"
#include "../bonus/bonus.h"

void handle_events(sfRenderWindow *win, sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
}

static const sfColor *get_color(int i)
{
    static const sfColor champ_color[] = {
        {56, 152, 219, 255},
        {29, 158, 117, 255},
        {226, 75, 74, 255},
        {186, 117, 23, 255},
        {163, 73, 183, 255},
        {83, 180, 180, 255},
        {212, 83, 126, 255},
        {130, 130, 130, 255},
        {220, 200, 60, 255},
    };

    return &champ_color[i];
}

void run_window(sfRenderWindow *win, sfEvent event, corewar_t *war)
{
    sfFont *font = sfFont_createFromFile("bonus/font.ttf");

    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        while (sfRenderWindow_pollEvent(win, &event))
            handle_events(win, event);
        draw_cycle(win, font, war);
        sfRenderWindow_display(win);
    }
    sfFont_destroy(font);
}

int dump(corewar_t *war)
{
    sfRenderWindow *win = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Corewar", sfClose, NULL);

    run_window(win, (sfEvent){0}, war);
    return SUCCESS_EXIT;
}
