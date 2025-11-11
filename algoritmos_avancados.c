#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

typedef enum {
    MAIN_HALL,
    BEDROOM,
    LIVING_ROOM,
    DINING_ROOM,
    KITCHEN,
    BATHROOM,
    LAUDRY_ROOM,
    OFFICE,
    GARAGE,
    ATTIC,
    BASEMENT 
} room;

const char *room_to_str(room r) {
    switch (r) {
    case MAIN_HALL:     return "Hall de Entrada";
    case BEDROOM:       return "Quarto";
    case LIVING_ROOM:   return "Sala de estar";
    case DINING_ROOM:   return "Sala de jantar";
    case KITCHEN:       return "Cozinha";
    case BATHROOM:      return "Banheiro";
    case LAUDRY_ROOM:   return "Lavanderia";
    case OFFICE:        return "Escritório";
    case GARAGE:        return "Garagem";
    case ATTIC:         return "Sótão";
    case BASEMENT:      return "Porão"; 
    default:            return "Indefinido";
    }
}

typedef struct {
    room r;
    node *left;
    node *right;
} node;

void clean_buffer(void);
void show_menu(void);
void create_room(node *n, char name);
void explore_room(void);

int main(void) {
    setlocale(LC_ALL, "pt-BR.UTF-8");

    int ok, option;
    bool run_game = true; // flag to control game flow
    while (run_game) {
        do {
            show_menu();
            ok = scanf("%d", &option);

            if (ok != 1) {
                clean_buffer();
                printf("Entrada inválida!. Tente novamente.\n");
            }

            if (option < 0 || option > 1) {
                clean_buffer();
                printf("Opção inválida!. Tente novamente.\n");
                ok = 0;
            }

        } while (ok != 1);

        switch (option) {
        case 0:
            run_game = false;
            break;
        
        case 1:
            explore_room();
            break;
        
        default:
            break;
        }
        
    }
    


    return 0;
}

void clean_buffer(void) {
    int c; while ((c = getchar()) != '\n' && c != EOF) {};        
}

void show_menu(void) {
    printf("----------------------\n");
    printf("         MENU         \n");
    printf("----------------------\n");
    printf("0 - Sair\n");
    printf("1 - Explorar sala\n");
    printf("----------------------\n");
}
