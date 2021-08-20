// Código que muestra el funcionamiento básico de una pila dinámica con el uso de memoria dinámica en lenguaje C.
#include <stdio.h>   
#include <stdlib.h>  
#include <stdbool.h> 

//Creación de una estructura nodo.
struct nodo {
  int numero;
  struct nodo *siguiente;
};

//Declaración de los prototipos de función
void agregar(int numero);  
void pop(void); 
void imprimir(void);
int TAM(void); 
bool IsEmpty(void);  
int ultimo(void);  

//Estructura tipo Nodo apuntando a NULL | Estructura de nodos
struct nodo *superior = NULL;

int main() {
  int eleccion;
  int numero;
  //Esto nos imprime un menú de manera constante para realizar la demostración una vez compilado.
  while (eleccion != -1) {
    printf("\n--Pila Dinamica--\n1.- Agregar\n2.- Eliminar\n3.- Imprimir "
           "pila\n4.- Imprimir size\n5.- Comprobar si esta vacia\n6.- "
           "Mostrar ultimo elemento\n-1.- Salir\n\n Elige: > ");
    scanf("%d", &eleccion);
    switch (eleccion) {
    case 1:
      printf("Ingresa el numero que agregemos a la pila:\n");
      scanf("%d", &numero);
      push(numero);
      break;
    case 2:
      pop();
      break;
    case 3:
      imprimir();
      getch();
      break;
    case 4:
      printf("La pila mide %d\n", TAM());
      getch();
      break;
    case 5:
      if (IsEmpty()) {
        printf("La pila esta vacia\n");
      } else {
        printf("La pila NO esta vacia\n");
      }
      getch();
      break;
    case 6:
      printf("El ultimo elemento es: %d\n", ultimo());
      getch();
      break;
    }
    system("cls");
  }
}

/*
Esta función nos retorna un valor entero con el tamaño de nuestra pila.
Se declara una variable contador para saber el numero de iteraciones que realiza, en este caso nos determinará el tamaño. 
El funcionamiento:
Se declara un Nodo apuntador temporal que apunta a nuestra estructura de nodos llamada superior.
Posteriormente se realiza un recorrido por los nodos de esa estructura:
    while (temp != NULL) {     una vez que temp sea Null, sale del while, quiere decir que ya no hay mas elementos
      contador++;
      temp = temp->siguiente;
    }
Si el nodo es igual a NULL desde un inicio, quiere decir que esta vacia:
    if (superior == NULL)
      return contador;
*/
int TAM(void) {
  int contador = 0;
  if (superior == NULL)
    return contador;
  struct nodo *temp = superior;
  while (temp != NULL) {
    contador++;
    temp = temp->siguiente;
  }
  return contador;
}

bool IsEmpty(void) { return superior == NULL; }

/*
Esta función retorna un valor entero del ultimo entero de la pila
Al estar apuntando siempre al ultimo elemento, unicamente extraemos el dato de la estructura usando -> dato
*/
int ultimo() {
  if (superior == NULL)
    return -1;
  return superior->numero;
}

/*
La función push permite añadir a la pila un elemento.
Trayendo el dato del main, se crea un nodo de manera dinamica:
    struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
Y posteriormente se le insertan los datos:
    nuevoNodo->numero = numero;
    nuevoNodo->siguiente = superior;  Aquí apuntamos el dato "siguiente" al nodo superior.
Y superior que es nuestra colección de nodos, apuntamos al nuevo nodo para que este sea nuestro último nodo.
    superior = nuevoNodo;
*/
void push(int numero) {
  printf("Agregando %d\n", numero);
  struct nodo *nuevoNodo = malloc(sizeof(struct nodo));
  nuevoNodo->numero = numero;
  nuevoNodo->siguiente = superior;
  superior = nuevoNodo;
}

/*
Función que nos imprime la pila, basandonos en el uso del recorrido de la pila que usamos en TAM
*/
void imprimir(void) {
  printf("Imprimiendo...\n");
  struct nodo *temp = superior;
  while (temp != NULL) {
    printf("%d\n", temp->numero);
    temp = temp->siguiente;
  }
}

/*
Función que elimina el ultimo elemento de la pila.
Primero verifica que no este vacía la pila:
    if (superior != NULL)
Para eliminar un elemento, se crea una estructura temporal a nuestra estructura de nodos "superior", y superior apunte a nuestro dato siguiente.
    struct nodo *temp = superior;
    superior = superior->siguiente;
Para una eliminación satisfactoria, liberamos la memoria:
    free(temp);
*/
void pop(void) {
  printf("Eliminando el ultimo\n");
  if (superior != NULL) {
    struct nodo *temp = superior;
    superior = superior->siguiente;
    free(temp);
  }
}
