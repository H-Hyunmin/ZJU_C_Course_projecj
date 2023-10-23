#include "../head/data.h"



//定义一个栈结构体
struct LinkStack* Init_LinkStack(void) {
	//分配内存空间
	struct LinkStack* linkstack = (struct LinkStack*)malloc(sizeof(struct LinkStack));
	//初始化栈
	linkstack->size = 0;	
	linkstack->head = NULL;
	return linkstack;
}

//入栈操作
void Push_LinkStack(struct LinkStack* new_linkstack, struct posi_info new_value) {
	//新建一个栈节点
	struct LinkStack_node* newhead = (struct LinkStack_node*)malloc(sizeof(struct LinkStack_node));

	//将新节点插入到栈顶
	newhead->next = new_linkstack->head;
	new_linkstack->head = newhead;
	//将元素放入节点中
	newhead->value = new_value;
	//栈大小加1
	new_linkstack->size++;
}

//出栈操作
struct posi_info Pop_LinkStack(struct LinkStack* pop_linkstack) {
	if (pop_linkstack->head != NULL) {
		//取出栈顶元素
		struct posi_info temp = pop_linkstack->head->value;
		//将栈顶指针指向下一个节点
		pop_linkstack->head = pop_linkstack->head->next;
		//栈大小减1
		pop_linkstack->size--;
		return temp;
	}
}




//定义一个链表栈结构体
struct List_LinkStack* generate_List_LinkStack() {
	//分配内存空间
	struct List_LinkStack* list_linkstack = (struct List_LinkStack*)malloc(sizeof(struct List_LinkStack));
	//初始化链表栈
	list_linkstack->size = 0;	
	list_linkstack->head = NULL;
	list_linkstack->tail = NULL;
	return list_linkstack;
}




//向队列中添加元素
void Enter_LinkQueue(struct LinkQueue* new_linkqueue, struct posi_info new_value) {
	//如果队列为空
	if (new_linkqueue->head == NULL) {
		//分配内存空间
		new_linkqueue->head = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		new_linkqueue->tail = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		//将元素添加到队列头
		new_linkqueue->head->value = new_value;
		new_linkqueue->head->next = NULL;
		//队列尾指向队列头
		new_linkqueue->tail = new_linkqueue->head;
		//队列大小加1
		new_linkqueue->size++;
	}
	else {
		//分配内存空间
		struct LinkQueue_node* newtail = (struct LinkQueue_node*)malloc(sizeof(struct LinkQueue_node));
		//将元素添加到队列尾
		newtail->value = new_value;
		newtail->next = NULL;
		new_linkqueue->tail->next = newtail;
		//队列尾指向新的队列尾
		new_linkqueue->tail = newtail;
		//队列大小加1
		new_linkqueue->size++;
	}
}







