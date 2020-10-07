#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include <iostream>

template <typename T>

class ListaDobleEnlazada
{

private:

	struct Nodo {

		Nodo* ant;
		T dato;
		Nodo* sig;

		Nodo(int n){

			dato = n;
			sig = nullptr;
			ant = nullptr;
		}
	};

	Nodo* cabeza;
	int cantidadNodos;

	//Metodos de Heap
	int obtenerPosPadre(int i)
	{

		return (i - 1 / 2);
	}

	int obtenerPosHijoD(int i)
	{

		return (i * 2 + 2);
	}

	int obtenerPosHijoI(int i)
	{

		return (i * 2 + 1);
	}

	Nodo getNodoEnPosicion(int n)
	{

		if (n < 0) {

			return nullptr;
		}
		else if (cantidadNodos > n) {

			if (n == 1) {

				return cabeza;
			}
			else {

				Nodo* temp = cabeza;
				int contador = 0;

				while ((contador != n) && temp->sig) {

					temp = temp->sig;
					contador++;
				}

				return temp;
			}
		}
		else {

			return nullptr;
		}
	}

	void intercambiar(Nodo* primero, Nodo* segundo) {

		T aux = primero->dato;
		primero->dato = segundo->dato;
		segundo->dato = aux;
	}

public:

	ListaDobleEnlazada()
	{

		cabeza = nullptr;
		cantidadNodos = 0;
	}

	ListaDobleEnlazada(const ListaDobleEnlazada& obj)
	{

		cabeza = new Nodo(obj.cabeza->dato);

		Nodo* temp = obj.cabeza->sig;

		while (temp) {

			this->insertar(temp->dato);
			temp = temp->sig;
		}

		cantidadNodos = obj.cantidadNodos;
	}

	void insertar(int dato)
	{

		Nodo* nuevo = new Nodo(dato);

		if (!cabeza) {

			cabeza = nuevo;
			cantidadNodos++;
			return;
		}

		Nodo* temp = cabeza;

		while (temp->sig) {

			temp = temp->sig;
		}

		nuevo->sig = nullptr;
		nuevo->ant = temp;
		temp->sig = nuevo;
		cantidadNodos++;

		return;
	}

	void insertarEnPosición(int dato, int n){

		if (!cabeza) {

			insertar(dato);

			return;
		}

		if (n <= 0) {

			return;
		}
		else if (cantidadNodos >= n) {

			Nodo* nuevo = new Nodo(dato);

			if (cantidadNodos == 1) {

				cabeza->dato = dato;
				cantidadNodos++;

				delete nuevo;
				return;
			}
			else if (n - 1 == 0) {

				cabeza->ant = nuevo;
				nuevo->sig = cabeza;
				cabeza = nuevo;
				cantidadNodos++;

				return;
			}
			else if (n - 1 == cantidadNodos) {

				insertar(dato);

				return;
			}
			else {

				Nodo* temp = cabeza;
				int contador = 0;

				while (contador != n - 1 && temp->sig) {

					temp = temp->sig;
					contador++;
				}

				nuevo->sig = temp;
				nuevo->ant = temp->ant;
				nuevo->ant->sig = nuevo;
				temp->ant = nuevo;

				cantidadNodos++;
				return;
			}
		}
		else {

		return;
		}
	}

	int getDatoEnPosicion(int n)
	{

		if (n <= 0) {

			return -1;
		}
		else if (cantidadNodos >= n) {

			if (cantidadNodos == 1) {

				return cabeza->dato;
			}
			else if (n == 1) {

				return cabeza->dato;
			}
			else {

				Nodo* temp = cabeza;
				int contador = 1;

				while ((contador != n) && temp->sig) {

					temp = temp->sig;
					contador++;
				}

				return temp->dato;
			}
		}
		else {

			return -1;
		}
	}

	void borrarEnPosición(int n)
	{

		if (n <= 0) {

			return;
		}
		else if (cantidadNodos >= n) {

			if (cantidadNodos == 1) {

				delete cabeza;
				cantidadNodos--;
				return;
			}
			else if (n == 1) {

				Nodo* temp = cabeza;

				cabeza = temp->sig;
				delete temp;

				cantidadNodos--;
				return;
			}
			else if (n == cantidadNodos) {

				Nodo* temp = cabeza;
				int contador = 1;

				while (contador != n && temp->sig) {

					temp = temp->sig;
					contador++;
				}

				Nodo* temp2 = temp->ant;

				temp2->sig = nullptr;

				delete temp;
				cantidadNodos--;

				return;
			}
			else {

				Nodo* temp = cabeza;
				int contador = 1;

				while (contador != n && temp->sig) {

					temp = temp->sig;
					contador++;
				}

				Nodo* temp2 = temp->ant;

				temp2->sig = temp->sig;
				temp->sig->ant = temp2;
				delete temp;
				cantidadNodos--;

				return;
			}
		}
		else {

			return;
		}
	}

	const int getCantidadNodos()
	{

		return cantidadNodos;
	}

	void heapify(int i)
	{

		int mayor = 0;
		int izq = obtenerPosHijoI(i);
		int der = obtenerPosHijoD(i);

		if (getDatoEnPosicion(izq) > getDatoEnPosicion(i)) {

			mayor = izq;
		}
		else {

			mayor = i;
		}

		if (getDatoEnPosicion(der) > getDatoEnPosicion(mayor)) {

			mayor = der;
		}

		if (mayor != i) {

			intercambiar(getNodoEnPosicion(mayor), getNodoEnPosicion(i));
			heapify(mayor);
		}
	}

	~ListaDobleEnlazada()
	{

		Nodo* temp = cabeza->sig;
		Nodo* temp2 = nullptr;

		while (temp->sig) {

			temp2 = cabeza;
			cabeza = temp;

			delete temp2;
			temp = temp->sig;
		}

		delete cabeza;
	}
};


#endif // !LISTADOBLEENLAZADA_H
