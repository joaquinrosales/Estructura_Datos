//Programa para el funcionamiento básico de una cola dinámica.
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//Creamos una estructura nodo, con nuestras variables y un apuntador a una estructura nodo llamada Next.
struct node{ 
    int data;
    struct node *next; 
};

//Una cola esta conformada por 2 apuntadores, uno que apunte al inicio y otro al final.
struct queue{
    struct node *front;
    struct node *rear;
}queue; 

//Prototipos de función.
void create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete_element(struct queue *);
struct queue *display(struct queue *);
int front(struct queue *);
int rear(struct queue *);
void invertircola(struct queue *);

int main(){
    int opcion, item;

//Creación de la cola y asignación de memoria.
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));;
    create_queue(q);

//Impresión de un menu para el funcionamiento de la cola.
    do{
        system("cls");
        printf( "\n   Seleccione una opcion: ");
        printf( "\n   1. Insertar elemento." );
        printf( "\n   2. Eliminar elemento.");
        printf( "\n   3. Imprimir cola.");
        printf( "\n   4. Mostrar el valor que se encuentra en front.");
        printf( "\n   5. Mostrar el valor que se encuentra en rear.");
        printf( "\n   0. Salir\n\n");

        scanf( "%d", &opcion );

        switch ( opcion ){
            		case 1: system("cls");
		 			printf("1. Insertar elemento.\n");
					printf("\n Ingresa un numero entero: ");
					scanf("%d", &item);
					q=insert(q, item);
					getch();
				break;
			case 2: system("cls");
					printf("2. Borrar elemento.\n");
					q=delete_element(q);
					getch();
				break;
			case 3: system("cls");
					printf("3. Imprimir cola.\n");
					q=display(q);
					getch();
				break;
			case 4: system("cls");
					printf("4. Mostrar el valor que se encuentra en front.\n");
					front(q);
                    			getch();
				break;
            		case 5: system("cls");
					printf("5. Mostrar el valor que se encuentra en rear.\n");
					rear(q);
					getch();
					break;
            		case 0: system("cls");
                    			puts("\n Salir.");
                    		break;
            		default: system("cls");
                   		 puts("\n Error: Introducir una opcion correcta.");
                     getch();
         }
    } while ( opcion != 0 );
    getch();
    return 0;
}

//Esta funcion nos permite realizar el proceso de apuntado a null de nuestra cola.
void create_queue(struct queue *q){ 
    q -> rear = NULL;
    q -> front = NULL;
}

/*
Para insertar datos en la cola, nuestra función trae 2 datos del main, nuestra cola 'q' y los datos 'val'.
Creamos un nodo para agregarlo a la cola:
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
Después asignamos el dato:
    ptr -> data = val;
Proceso para insertar en la cola:
    if(q -> front == NULL){    Si el frente es nulo, quiere decir que la cola está vacía, por lo que será nuestra primer inserción
        q -> front = ptr;      Front y rear los apuntamos a ptr o nuestro nodo.
        q -> rear = ptr;
        q -> front -> next = q -> rear -> next = NULL;      Y sus respectivos next serán nulos ya que es el primer nodo de la cola.
    }
    else{                                                   De lo contrario, si ya hay nodos en la cola...
        q -> rear -> next = ptr;                            Ahora haremos que la cola apunte al nuevo nodo como nodo trasero o final.
        q -> rear = ptr;                                    Hacemos que el rear de la cola sea nuestro nodo nuevo y su siguiente nodo sea nulo.
        q -> rear -> next = NULL;                           Nuestro nuevo next sea Null.
    }
    return q;                                               Retornamos la cola.
*/
struct queue * insert(struct queue *q,int val){ 
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = val;

    if(q -> front == NULL){
        q -> front = ptr;
        q -> rear = ptr;
        q -> front -> next = q -> rear -> next = NULL;
    }else{
        q -> rear -> next = ptr;
        q -> rear = ptr;
        q -> rear -> next = NULL;
    }
    return q;
}

/*
Función que nos permite desplegar la cola.
Creamos un nodo que nos servira para irnos desplazando:
        struct node *ptr;
        ptr = q -> front;      
Ahora si nuestro frente esta vacío, quiere decir que la cola está vacia:
        if(ptr == NULL){
        printf("\n La cola esta vacia.\n");
        }
De lo contrario...
        else{
            printf("\n Los elementos son:\n");
                while(ptr!=q -> rear){                  Hacemos un recorrido por la cola mientras ptr sea diferente de nuestro rear.
                    printf("\t %d\n", ptr -> data);
                    ptr = ptr -> next;                  Aquí nos vamos desplazando por la cola.
        }
        printf("\t %d\n", ptr -> data);                 Impresión de datos.
    }
*/
struct queue * display(struct queue *q){
    struct node *ptr;
    ptr = q -> front;

    if(ptr == NULL){
        printf("\n La cola esta vacia.\n");
    }else{
        printf("\n Los elementos son:\n");
        while(ptr!=q -> rear){
            printf("\t %d\n", ptr -> data);
            ptr = ptr -> next;
        }
        printf("\t %d\n", ptr -> data);
    }
    return q;
}

/*
Para eliminar un elemento o desencolar (dequeue).
Creamos un nodo auxiliar que se iguale a nuestro frente:
        struct node *ptr;
        ptr = q -> front;
Revisamos que nuestro frente no sea nulo, de lo contrario estaria vacia la cola:
        if(q -> front == NULL){
            printf("\n La cola esta vacia.\n");
        }
De no ser asi...
        else{                                                                   
            q -> front = q -> front -> next;                                El valor del front de nuestra cola lo sobreescribimos con el next del front.
            printf("\n El valor que fue borrado es: %d\n", ptr -> data);
            free(ptr);                                                      Liberamos la memoria.
        }
        return q;                                                           Retornamos la cola con la modificación.
*/
struct queue * delete_element(struct queue *q){
    struct node *ptr;
    ptr = q -> front;

    if(q -> front == NULL){
        printf("\n La cola esta vacia.\n");
    }
	else{
        q -> front = q -> front -> next;
        printf("\n El valor que fue borrado es: %d\n", ptr -> data);
        free(ptr);
    }
    return q;
}


//Función que retorna el valor del front.
int front(struct queue *q){
    if(q->front==NULL){
        printf("\n La cola esta vacia.\n");
        return -1;
    }
    else{
        printf("\n El valor que se encuentra en front es %d.\n", q->front->data);
        return q->front->data;
    }
}

//Función que retorna el valor del rear.
int rear(struct queue *q){
    if(q->front==NULL){
        printf("\n La cola esta vacia.\n");
        return -1;
    }
    else{
        printf("\n El valor que se encuentra en rear es %d.\n", q->rear->data);
        return q->rear->data;
    }
}

/*
Función que nos retorna el tamaño de nuestra cola.
Creamos un nodo auxiliar que apunte al frente y un contador:
        struct node *ptr;
        ptr = q -> front;
        int x=0;
Hacemos un recorrido por la cola:
        while(ptr!=q -> rear){
            x++;                    Aumenta en cada desplazamiento.
            ptr = ptr -> next;      Desplazamiento de apuntador.
        }
    return x;                       Una vez terminado el recorrido retornamos el valor del contador.
*/
int num_elem(struct queue *q){
	struct node *ptr;
    ptr = q -> front;
    int x=0;
	while(ptr!=q -> rear){
            x++;
            ptr = ptr -> next;
        }
    return x;
}
