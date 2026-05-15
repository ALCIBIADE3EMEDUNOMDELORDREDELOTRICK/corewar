/*
** EPITECH PROJECT, 2026
** robot_factory
** File description:
** header
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../include/header.h"


#ifndef BONUS_H
    #define BONUS_H

    #define COLS 96
    #define ROWS 64
    #define CELL_W (1420 / COLS)
    #define CELL_H (1080 / ROWS)
sfText *create_text(sfFont *font, const sfColor *color);
void draw_arena(sfRenderWindow *win, corewar_t *war);
void draw_cycle(sfRenderWindow *win, sfFont *font, corewar_t *war);
void draw_line(sfRenderWindow *win, float y);
void draw_text(sfRenderWindow *win, sfText *t, char *str, float y);
const sfColor *get_color(int i);
void draw_robots(sfRenderWindow *win, sfFont *font, corewar_t *war,
    int selected);
void draw_robot_detail(sfRenderWindow *win, sfFont *font,
    robot_t *r, int idx);

#endif
