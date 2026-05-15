/*
** EPITECH PROJECT, 2026
** corewar
** File description:
** arena draw
*/

#include "../include/header.h"
#include "../bonus/bonus.h"

static void build_owner(corewar_t *war, int owner[MEM_SIZE])
{
    int idx = 0;
    robot_t *r;

    for (int i = 0; i < MEM_SIZE; i++)
        owner[i] = -1;
    for (nodes_t *n = war->robot; n && idx < 8; n = n->next) {
        r = (robot_t *)n->data;
        my_printf("robot %s load=%d size=%d\n", r->name, r->load, r->size);
        for (int j = 0; j < r->size; j++)
            owner[(r->load + j) % MEM_SIZE] = idx;
        idx++;
    }
}

static sfColor get_cell_color(int byte, int owner_id)
{
    sfColor c;
    const sfColor *tmp;
    float brightness;

    if (owner_id < 0)
        return (sfColor){30, 30, 28, 255};
    tmp = get_color(owner_id % 8);
    c = *tmp;
    brightness = (float)byte / 255.0f * 0.8f + 0.2f;
    c.r = (sfUint8)(c.r * brightness);
    c.g = (sfUint8)(c.g * brightness);
    c.b = (sfUint8)(c.b * brightness);
    return c;
}

static void fill_vertices(sfVertex *verts, corewar_t *war, int owner[MEM_SIZE])
{
    int x;
    int y;
    sfColor color;

    for (int i = 0; i < MEM_SIZE; i++) {
        x = (i % COLS) * CELL_W;
        y = (i / COLS) * CELL_H;
        color = get_cell_color(war->arena[i], owner[i]);
        verts[i * 4 + 0] = (sfVertex){{x, y}, color, {0, 0}};
        verts[i * 4 + 1] = (sfVertex){{x + CELL_W, y}, color, {0, 0}};
        verts[i * 4 + 2] = (sfVertex){{x + CELL_W, y + CELL_H}, color, {0, 0}};
        verts[i * 4 + 3] = (sfVertex){{x, y + CELL_H}, color, {0, 0}};
    }
}

static void draw_pc(sfRenderWindow *win, processus_t *proc)
{
    sfCircleShape *dot = sfCircleShape_create();

    if (!dot || !proc)
        return;
    sfCircleShape_setRadius(dot, CELL_W / 2);
    sfCircleShape_setFillColor(dot, sfWhite);
    sfCircleShape_setPosition(dot, (sfVector2f){
            (proc->pc % COLS) * CELL_W,
            (proc->pc / COLS) * CELL_H});
    sfRenderWindow_drawCircleShape(win, dot, NULL);
    sfCircleShape_destroy(dot);
}

void draw_arena(sfRenderWindow *win, corewar_t *war)
{
    int owner[MEM_SIZE];
    sfVertex verts[MEM_SIZE * 4];
    robot_t *r;

    build_owner(war, owner);
    fill_vertices(verts, war, owner);
    sfRenderWindow_drawPrimitives(win, verts, MEM_SIZE * 4, sfQuads, NULL);
    for (nodes_t *n = war->robot; n; n = n->next) {
        r = (robot_t *)n->data;
        if (r->life)
            draw_pc(win, r->processus);
    }
}
