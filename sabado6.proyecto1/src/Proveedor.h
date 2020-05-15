#ifndef PROVEEDOR_H_
#define PROVEEDOR_H_

#define NOMBRE_LEN 50
#define LOCALIDAD_LEN 20


typedef struct
{
	char nombre[NOMBRE_LEN];
	char localidades[LOCALIDAD_LEN];
	int isEmpty;
	int idProveedores;
}Proveedores;

int prov_imprimir(Proveedores* auxProducto);
int prov_inicializarArray(Proveedores* array,int limite);
int prov_altaArray(Proveedores* array,int limite, int indice, int* id);
int prov_getEmptyIndex(Proveedores* array,int limite);
int prov_imprimirArray(Proveedores* array,int limite);
int prov_buscarId(Proveedores array[], int limite, int valorBuscado);
int prov_modificarArray(Proveedores* array,int limite, int indice);
int prov_bajaArray(Proveedores* array,int limite, int indice);
int prov_ordenarPorNombre(Proveedores* array,int limite);


#endif /* PROVEEDOR_H_ */
