#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    node *left;
    node *right;
} node;

void show_menu(void);
void create_room(node *n, char name);
void explore_room(void);

int main(void) {
    setlocale(LC_ALL, "pt-BR.UTF-8");


    return 0;
}
