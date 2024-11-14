#include "piersADT.h"
#include <assert.h>

int main(void)
{
    piersADT piersAdt = newPiers();
    assert(addPier(piersAdt, 5) == 1);        
    // Agrega el puerto 5
    assert(addPierDock(piersAdt, 5, 4) == 1); 
    // Agrega el muelle 4 del puerto 5 
    assert(addPierDock(piersAdt, 5, 7) == 1);
    assert(addPier(piersAdt, 10) == 1);
    assert(addPierDock(piersAdt, 10, 1) == 1);
    assert(addPierDock(piersAdt, 10, 7) == 1);
    // No hay una embarcación amarrada en el muelle 4 del puerto 5 
    assert(shipInDock(piersAdt, 5, 4) == 0); 
    assert(shipInDock(piersAdt, 5, 7) == 0); 
    assert(pierShips(piersAdt, 5) == 0); 
    assert(shipInDock(piersAdt, 10, 1) == 0); 
    assert(shipInDock(piersAdt, 10, 7) == 0); 
    assert(pierShips(piersAdt, 10) == 0);
    // Se amarra una embaración en el muelle 
    assert(dockShip(piersAdt, 5, 4) == 1); 
    assert(shipInDock(piersAdt, 5, 4) == 1); 
    assert(shipInDock(piersAdt, 5, 7) == 0); 
    assert(pierShips(piersAdt, 5) == 1); 
    assert(dockShip(piersAdt, 5, 7) == 1); 
    assert(shipInDock(piersAdt, 5, 4) == 1); 
    assert(shipInDock(piersAdt, 5, 7) == 1); 
    assert(pierShips(piersAdt, 5) == 2);
    // Se desamarra la embaración del muelle 
    assert(undockShip(piersAdt, 5, 7) == 1); 
    assert(shipInDock(piersAdt, 5, 4) == 1); 
    assert(shipInDock(piersAdt, 5, 7) == 0); 
    assert(pierShips(piersAdt, 5) == 1);
    freePiers(piersAdt);
    return 0;
}