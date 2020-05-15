#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#define NOMBRE_LEN 50

typedef struct
{
	char nombre[NOMBRE_LEN];
	float precio;
	int isEmpty;
	int id;
	int stock;
}Producto;

int prod_imprimir(Producto* auxProducto);
int prod_inicializarArray(Producto* array,int limite);
int prod_altaArray(Producto* array,int limite, int indice, int* id);
int prod_getEmptyIndex(Producto* array,int limite);
int prod_imprimirArray(Producto* array,int limite);
int prod_buscarId(Producto array[], int limite, int valorBuscado);
int prod_modificarArray(Producto* array,int limite, int indice);
int prod_bajaArray(Producto* array,int limite, int indice);
int prod_ordenarPorNombre(Producto* array,int limite);


#endif /* PRODUCTO_H_ */
