/*
** EPITECH PROJECT, 2026
** corewar_pub
** File description:
** dump
*/

#include "../include/header.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>

void handle_events(sfRenderWindow *win, sfEvent event)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(win);
}

void run_window(sfRenderWindow *win, sfEvent event, corewar_t *war)
{
    sfFont *font = sfFont_createFromFile("/bonus/font.tff");

    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        while (sfRenderWindow_pollEvent(win, &event))
            handle_events(win, event);
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
