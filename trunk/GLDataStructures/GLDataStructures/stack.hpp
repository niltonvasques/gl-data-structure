#ifndef STACK_HPP
#define STACK_HPP

#pragma once

#define DEFAULT_CAPACITY 100


template <class Type> class Stack{
	struct stack_{
		Type content;
		struct stack_ *next;
	} typedef STACK_S;
public: 
	Stack();
	virtual ~Stack();

	int push(Type t);
	int pop(Type &t);
	int pick(Type &t);
	bool isEmpty();


private:
	STACK_S *stackPtr;
	void freeStack(STACK_S *freePtr);
};
#endif

template <class Type>
Stack<Type>::Stack(){
	stackPtr = NULL;
}

template <class Type>
Stack<Type>::~Stack(){
	freeStack(stackPtr);
}

template <class Type>
int Stack<Type>::push(Type t){
	STACK_S *top = (STACK_S*) malloc(sizeof(STACK_S));
	if(top != NULL){
		top->next = stackPtr;
		top->content = t;
		stackPtr = top;
		return 1;
	}
	return 0;
}

template <class Type>
int Stack<Type>::pop(Type &t){
	if(stackPtr != NULL){
		t = stackPtr->content;
		STACK_S *freePtr = stackPtr;
		stackPtr = freePtr->next;
		free(freePtr);
		return 1;
	}
	return 0;
}

template <class Type>
int Stack<Type>::pick(Type &t){
	if(stackPtr != NULL){
		t = stackPtr->content;
		return 1;
	}
	return 0;
}

template <class Type>
void Stack<Type>::freeStack(STACK_S *freePtr){
		if(freePtr == NULL) return;
		freeStack(freePtr->next);
		free(freePtr);	
}

template <class Type>
bool Stack<Type>::isEmpty(){
	return (this->stackPtr == NULL);
}