#include "piersADT.h"

typedef enum { vacio = 0, ocupado } Estado;
 
typedef struct {
  Estado estado;
  Estado existe;
} Dock;
 
typedef struct {
  Dock* docks; // Vector donde guardo si los muelles estan ocupados o no
  Estado existente; // 0 si no existe el puerto, 1 si existe
  size_t ocupados;
  size_t reservados_dock;
} Pier;
 
typedef struct piersCDT {
  Pier* vec;
  size_t reservados_pier;
} piersCDT;
 
static int existPier(piersADT piers, size_t pierNumber) {
  return pierNumber < piers->reservados_pier && piers->vec[pierNumber].existente == 1;
}
 
piersADT newPiers(void) {
   return calloc(1, sizeof(piersCDT));
}
 
size_t addPierDock(piersADT piers, size_t pierNumber, size_t dockNumber) {
  if ( !existPier(piers, pierNumber) ) {
    return 0; // Retorno 0 si el puerto no existe
  }
  if(piers->vec[pierNumber].reservados_dock <= dockNumber) {
    piers->vec[pierNumber].docks = realloc(piers->vec[pierNumber].docks, sizeof(Dock) * (dockNumber + 1));
    for (size_t i = piers->vec[pierNumber].reservados_dock; i <= dockNumber; i++)
    {
        piers->vec[pierNumber].docks[i].estado = 0;
        piers->vec[pierNumber].docks[i].existe = 0;
    }

    piers->vec[pierNumber].reservados_dock = dockNumber + 1; 
  }

  if(piers->vec[pierNumber].docks[dockNumber].existe)
    return 0;

  //Ahora el muello existe, cuando se creo se marco como vacio
  //por ende no hace falta hacer eso
  piers->vec[pierNumber].docks[dockNumber].existe = 1;

  return 1;

}
 
size_t dockShip(piersADT piers, size_t pierNumber, size_t dockNumber) {
  if ( !existPier(piers, pierNumber) ) {
    return 0;
  }

  //Si dock number es mayor a la cantidad de muelles reservados, o no existe o esta ocupado
  if(piers->vec[pierNumber].reservados_dock <= dockNumber || !(piers->vec[pierNumber].docks[dockNumber].existe) || piers->vec[pierNumber].docks[dockNumber].estado == ocupado)
    return 0;

  piers->vec[pierNumber].docks[dockNumber].estado = ocupado;
  piers->vec[pierNumber].ocupados++;
  return 1;
}
 
int shipInDock(const piersADT piers, size_t pierNumber, size_t dockNumber) {
  if ( !existPier(piers, pierNumber) || piers->vec[pierNumber].reservados_dock <= dockNumber || piers->vec[pierNumber].docks[dockNumber].existe == 0 ) {
    return -1;
  }
  return piers->vec[pierNumber].docks[dockNumber].estado;
}