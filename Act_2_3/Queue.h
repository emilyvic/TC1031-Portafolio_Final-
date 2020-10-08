#ifndef Queue_h
#define Queue_h

#include "Node.h"

template<class T>
class Queue{ //definir clase List
	private:
		Node <T>* head;
        Node <T>* tail;
		int size; //tamaño de la lista 
	public:
        Queue(); //constructor default
        void print();//metodo para imprimir todos los elementos de la queue
        void clear(); //borrar todos los elementos de la lista
		int getSize();//retornar el tamano de la queue
		void enqueue(T data); //agregar un dato a la lista
		T dequeue(); //eliminar el primer dato agregado a la cola
		T front();//primer elemento agregado
		T back();//ultimo elemento agregado
};

template<class T>
Queue<T>::Queue(){
	head = NULL; //head apunta a NULL
	tail = NULL; //tail apunta a NULL
	size = 0; //inicializar la lista con 0 elementos
}


template<class T>
void Queue<T>::print(){
	cout << "Tamano de la cola: " << size << endl;
	cout <<"Elementos de la Cola:  ";
    Node<T>* aux = head; //inicializar la variable aux con el primer elemento (el que apunta top)
	for (int i=0; i<size; i++){ //recorrer size veces
        cout << (aux -> data); //imprimir el dato aux
        aux = aux -> next; //actualizar aux apuntando al dato siguiente
		cout <<endl;
    }
}//Complejidad O(n)


template<class T>
void Queue<T>::clear(){
	if(size=!0){
		head = NULL; //head apunta a NULL
		tail = NULL; //tail apunta a NULL
		size = 0; //inicializar la lista con 0 elementos
	}else{
		cout <<"la lista ya esta vacia"<<endl;
	}

}

template<class T>
int Queue<T>::getSize(){
    return size; //mandar el valor de size
}

template<class T>
T Queue<T>::front(){
    if(size!=0){
		return head->data; //mandar el valor de size
	}else{
		throw runtime_error("Lista vacia");
	}

}

template<class T>
T Queue<T>::back(){
    if(size!=0){
		return tail->data; //mandar el valor de size
	}else{
		throw runtime_error("Lista vacia");
	}
}

template<class T>
void Queue<T>::enqueue(T data){
	Node<T>* prev; //crear nuevo nodo
	if(size == 0){ //si la lista esta vacia
		head = new Node<T>(data);//crear nuevo nodo 
		tail = head;
	}else{
		tail->next = new Node<T>(data);//crear nuevo nodo 
		tail -> next ->prev = tail;//el anterior elemento apuntara al nuevo 
		tail = tail->next;//el previo sera el utlimo elemento agregado 
	} //tail tambien apunta a este dato
	size ++;//incrementar el tamano del arreglo
}

template<class T>
T Queue<T>::dequeue(){
	if(size!=0){//si la lista no esta vacia
		T value = head->data; //alamacenar el valor de la variable
		head = head->next; //cambiar el head al siguiente elemento en la lista
		size--;//disminuir la size
		return value;
	}else{
		throw runtime_error("No se puede eliminar primer elemento, lista vacia");
	}
}

#endif