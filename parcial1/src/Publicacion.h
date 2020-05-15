#ifndef PUBLICACION_H_
#define PUBLICACION_H_

#define CUIT_LEN 20
#define TEXTO_LEN 65

#define ESTADO_ACTIVO 0
#define ESTADO_PAUSADO 1

typedef struct
{
	char texto[TEXTO_LEN];
	int estado;
	int rubro;
	int idCliente;
	int isEmpty;
	int id;
}Publicacion;

int pub_imprimir(Publicacion* auxProducto);
int pub_inicializarArray(Publicacion* array,int limite);
int pub_altaArray(Publicacion* array,int limite, int indice, int* idContratacion, int idPantalla);
int pub_getEmptyIndex(Publicacion* array,int limite);
int pub_imprimirArray(Publicacion* array,int limite);
int pub_buscarId(Publicacion array[], int limite, int valorBuscado);
int pub_modificarArray(Publicacion* array,int limite, int indice);
int pub_bajaArray(Publicacion* array,int limite, int indice);
int pub_ordenarPorNombre(Publicacion* array,int limite);
int pub_imprimirPublicacionesPorIdCliente(Publicacion* arrayPublicaciones, int limitePub, int auxIdCliente);
int pub_bajaPublicacion(Publicacion* arrayPublicacion, int limitePub, int auxIdCliente);
int pub_pausarPublicacion(Publicacion* arrayPublicaciones, int lenPub, int auxiliarIdPub);
int pub_reanudarPublicacion(Publicacion* arrayPublicaciones, int lenPub, int auxiliarIdPub);
int pub_contadorPublicacionesActivas(Publicacion* arrayPublicaciones, int lenPub, int auxIdCliente);
int pub_contadorPublicacionesPausadas(Publicacion* arrayPublicaciones, int lenPub, int auxIdCliente);
int pub_imprimirPubActivasPorRubro(Publicacion* arrayPublicaciones, int lenPub, int* rubro);
int pub_imprimirRubros(Publicacion* arrayPublicaciones, int lenPub);
int pub_imprimirRubroConMasPubActivas(Publicacion* arrayPublicaciones, int lenPub);
int pub_contadorPubActivasPorRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro);
int pub_imprimirRubroConMenosPubActivas(Publicacion* arrayPublicaciones, int lenPub);
int pub_contadorPubPausadasPorRubro(Publicacion* arrayPublicacion, int limitePublicaciones,int* rubro);

int pub_altaForzadaArray(Publicacion* array,int limite, int indice, int* idPublicacion, int idCliente,char* texto, int estado, int rubro);

#endif /* PUBLICACION_H_ */
