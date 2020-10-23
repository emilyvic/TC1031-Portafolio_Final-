#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "Node.h"
#include "DoubleLinkedList.h"

template<class T>
class PriorityQueue{ //definir clase List
	private:
		DoubleLinkedList<T> heap;
		void downSort(int index);
		void upSort(int index);
		void swap (int index1, int index2);//intercambiar elementos de la lista
		int size; //tamaño de la lista 
		int getMax(int index1, int index2);
	public:
        PriorityQueue(); //constructor default
		PriorityQueue(DoubleLinkedList<T> llist); //constructor a traves de una linked list
		int getSize();//retorna la cantidad de elementos en la heap
		bool isEmpty(); //retorna si esta vacia la heap
		void print();//metodo para imprimir todos los elementos de la queue
		T remove();//quitar el primer elemento de la heap
		void insert(T data);//insertar un elemento al final de la heap
};

template<class T>
PriorityQueue<T>::PriorityQueue(){
	size = 0; //inicializar la lista con 0 elementos
}

template<class T>
PriorityQueue<T>::PriorityQueue(DoubleLinkedList<T> llist){
	if(!llist.isEmpty()){
		heap = llist;
		size = llist.getSize();
		int index = size / 2; //empezar en el de la mitad
		downSort(index);
	}
}

template<class T>
void PriorityQueue<T>::swap(int index1, int index2){ //intercambiar las posiciones de los elementos de los indices especificados
	T aux = heap[index1];
	heap.updateAt(index1, heap[index2]);
	heap.updateAt(index2, aux);
}

//obtener el elemento maximo de los indices especificados
template<class T>
int PriorityQueue<T>::getMax(int index1, int index2){
	if (heap[index1] >= heap[index2]){
		return index1;
	}else{
		return index2;
	}
}

//arreglar el heap hacia abajo
template<class T>
void PriorityQueue<T>::downSort(int index){
	while(index >= 1){
		int pos = index;
		int max;
		while( pos*2 <= size){//mientras la posicion del hijo 1 sea menor o igual a size
			int s1 = pos*2;//posicion hijo 1
			int s2 = pos*2 + 1;//posicion hijo 2
			if (s2 > size){//si el hijo 2 es mayor a size (ultimo caso)
				max = s1;//entonces escoger al hijo 1 como el mayor
			}else{
				max = getMax(s1, s2); //obtener el hijo de mayor valor
			}
			if (heap[max] > heap[pos]){//comparar si el hijo es mayor al padre 
				swap(pos, max);//intercambiar valores
				pos = max;// reestablecer la posicion a comparar
			}else{
				pos = size;//salir del ciclo
			}
		}
		index --;
	}
}//Complejidad: O(log2(n))

//arreglar el heap hacia arriba
template<class T>
void PriorityQueue<T>::upSort(int index){
	while(index > 1){
		int posf = index/2;
		if(heap[index] >= heap[posf]){ //si el hijo es mayor que el padre
			swap(index, posf);
			index = posf;
			posf = index/2;
		}else{
			index = 1;
		}
	}
}//Complejidad: O(log2(n))

template<class T>
bool PriorityQueue<T>::isEmpty(){
	return size == 0;
}

template<class T>
void PriorityQueue<T>::print(){
	heap.print();
}

template<class T>
int PriorityQueue<T>::getSize(){
	size = heap.getSize();
    return size; //mandar el valor de size
}

template<class T>
T PriorityQueue<T>::remove(){
	if(!isEmpty()){
		T aux = heap[1];
		swap(1, size);
		heap.removeTail();
		size--;
		downSort(1);
		return aux;
	}else{
		throw runtime_error("No se puede eliminar un elemento de una lista vacia");
	}
}

template<class T>
void PriorityQueue<T>::insert( T data){
	heap.addLast(data); //agregar al final de la lista
	getSize(); //obtener el tamano de la lista
	if(!isEmpty()){//si no esta vacia, entonces
		upSort(size);//arreglala hacia abajo
	}
}

#endif