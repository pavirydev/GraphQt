#include "nodo.h"

// Métodos del Nodo

Nodo::Nodo()
{
    pSig = nullptr;
    pAnt = nullptr;
}

void Nodo::insertar_adelante(const Ciudad &d)
{
    Nodo *npointer = new Nodo();
    npointer->Dato = d;
    npointer->pSig = this->pSig;
    npointer->pAnt = this;
    this->pSig->pAnt = npointer;
    this->pSig = npointer;
}

Ciudad Nodo::eliminar_adelante()
{
    Ciudad retrieve;
    this->pSig = this->pSig->pSig;
    this->pSig->pAnt->pAnt = nullptr;
    this->pSig->pAnt->pSig = nullptr;

    retrieve = this->pSig->pAnt->Dato;
    delete this->pSig->pAnt;
    this->pSig->pAnt = this;
    return retrieve;

}
