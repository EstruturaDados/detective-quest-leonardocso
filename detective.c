#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

/*Rooms struct*/
typedef enum {
    HALL,
    LOUNGE,
    STUDY,
    DINING_ROOM,
    LIBRARY,
    BILLIARD_ROOM,
    KITCHEN,
    BALLROOM,
    CONSERVATORY,
    MAX_ROOM
} room;

/*Convert rooms enum to readable names*/
const char *room_to_str(room r) {
    switch (r) {
    case HALL:          return "Hall de Entrada";
    case LOUNGE:        return "Sala de Estar";
    case STUDY:         return "Sala de Estudos";
    case DINING_ROOM:   return "Sala de Jantar";
    case LIBRARY:       return "Biblioteca";
    case BILLIARD_ROOM: return "Sala de Jogos";
    case KITCHEN:       return "Cozinha";
    case BALLROOM:      return "Salão de Festas";
    case CONSERVATORY:  return "Estufa"; 
    default:            return "Indefinido";
    }
}

/*Base tree node*/
typedef struct node {
    room room_name;
    struct node *left;
    struct node *right;
} node;

/*Prototypes*/
void clean_buffer(void);
void show_menu(void);
node *create_room(room r);
void explore_room(node *root);
void destroy_tree(node *root);

/*Main*/
int main(void) {
    setlocale(LC_ALL, "pt-BR.UTF-8");

    /*Create static tree of rooms*/
    node *hall = create_room(HALL);
    node *lounge = create_room(LOUNGE);
    node *study = create_room(STUDY);
    node *dining_room = create_room(DINING_ROOM);
    node *library = create_room(LIBRARY);
    node *billiard_room = create_room(BILLIARD_ROOM);
    node *kitchen = create_room(KITCHEN);
    node *ballroom = create_room(BALLROOM);
    node *conservatory = create_room(CONSERVATORY);

    node *root = hall;
    hall->left = lounge;
    hall->right = study;
    lounge->left = dining_room;
    lounge->right = library;
    study->left = billiard_room;
    study->right = kitchen;
    dining_room->right = ballroom;
    library->right = conservatory;

    int ok, option;
    while (true) {
        do {
            show_menu();
            ok = scanf("%d", &option);
            clean_buffer();

            if (ok != 1) {
                printf("Entrada inválida!. Tente novamente.\n");
            }

            if (option < 0 || option > 1) {
                printf("Opção inválida!. Tente novamente.\n");
                ok = 0;
            }

        } while (ok != 1);

        switch (option) {
        case 0:
            printf("Saindo do jogo...\n");
            destroy_tree(root);
            return 0;
        
        case 1:
            explore_room(root);
            break;
        }
    }
}

/*Clears remaining input from stdin*/
void clean_buffer(void) {
    int c; while ((c = getchar()) != '\n' && c != EOF) {};        
}

/*------ UI ------*/
void show_menu(void) {
    printf("----------------------------------\n");
    printf("               MENU               \n");
    printf("----------------------------------\n");
    printf("0 - Sair\n");
    printf("1 - Explorar sala\n");
    printf("----------------------------------\n");
}

/*Base function to create tree nodes*/
node *create_room(room r) {
    node *root = malloc(sizeof(node));
    if(!root) return NULL;

    root->room_name = r;
    root->left = NULL;
    root->right = NULL;
    
    return root;
}

/*Base function to interact with tree node*/
void explore_room(node *root) {
    char option;

    while (true) {
        printf("\nVocê está em: %s\n", room_to_str(root->room_name));
        printf("Digite (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &option);

        if (option == 'e') {
            if (root->left == NULL) {
                printf("\nVocê chegou ao fim da ala da mansão.\n");
                break;
            }
            root = root->left;
        }
        else if (option == 'd') {
            if (root->right == NULL) {
                printf("\nVocê chegou ao fim da ala da mansão.\n");
                break;
            }
            root = root->right;
        }
        else if (option == 's') {
            break;
        }
        else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

/*Free allocated memory used to create entire tree*/
void destroy_tree(node *root) {
    if (root == NULL) return;

    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}
