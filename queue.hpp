#ifndef QUEUE_HPP 
#define QUEUE_HPP
#include <stdlib.h>
#include <stdio.h>

template<class T> class Queue{
	struct queue_{
		T content;
		struct queue_ *next;
	}typedef QUEUE;
public:
	Queue();
	~Queue();

	int insert(T content);
	int remove(T& content);
	int pickTail(T& content);
	int pickHead(T& content);
	bool isEmpty();

private:
	QUEUE *front;
	QUEUE *back;
};

template<class T>
Queue<T>::Queue(){
	front = NULL;
	back = NULL;
}

template<class T>
Queue<T>::~Queue(){
	while(!isEmpty()){
		QUEUE *temp = front->next;
		free(front);
		front = temp;
	}
	back = NULL;
}

template<class T>
int Queue<T>::insert(T content){
	QUEUE* node = (QUEUE*)malloc(sizeof(QUEUE));
	node->next = NULL;
	node->content = content;
	if(node!= NULL){
		if(back == NULL){ 
			back = node;
			front = node;
		}else{
			back->next = node;
			back = node;
		}
		return 1;
	}
	return 0;
}

template<class T>
int Queue<T>::remove(T &content){
	if(!isEmpty()){
		content = front->content;
		QUEUE *temp = front->next;
		free(front);
		front = temp;
		if(front == NULL) back = NULL;
		return 1;
	}
	return 0;
}

template<class T>
int Queue<T>::pickTail(T &tail){
	if(!isEmpty()){
		tail = back->content;
			return 1;
	}
	return 0;
}

template<class T>
int Queue<T>::pickHead(T &tail){
	if(!isEmpty()){
		tail = front->content;
			return 1;
	}
	return 0;
}


template<class T>
bool Queue<T>::isEmpty(){
	return (front == NULL);
}

#endif