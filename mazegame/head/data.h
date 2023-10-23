#ifndef __LINKQUEUE__
#define __LINKQUEUE__
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>
#include <conio.h>

#include "../libgraphics/graphics.h"
#include "../libgraphics/extgraph.h"
#include "../libgraphics/genlib.h"
#include "../libgraphics/simpio.h"
#include "../libgraphics/strlib.h"
#include "../libgraphics/linkedlist.h"
#include "../libgraphics/imgui.h"
#include "../libgraphics/boolean.h"
#include "../libgraphics/gcalloc.h"
#include "../libgraphics/random.h"

#include "maze_info.h"

//linktqueue.h中定义了两个队列结构体LinkQueue_node和LinkQueue，表示链队列。
//其中LinkQueue_node包含了一个posi_info类型的值和指向下一个节点的指针，LinkQueue包含了队列的大小、头指针和尾指针。
//data.h中还定义了两个队列结构体List_LinkQueue_node和List_LinkQueue，表示链队列的一个列表。

// 定义一个结构体，表示链栈中的一个节点
struct LinkStack_node
{
	struct posi_info value; // 存储节点的值
	struct LinkStack_node* next; // 指向下一个节点的指针
};

// 定义一个结构体，表示链栈
struct LinkStack
{
	int size; // 链栈的大小
	struct LinkStack_node* head; // 指向栈顶的指针
};

// 创建一个新的栈
struct LinkStack* Init_LinkStack(void);

// 将一个元素压入栈中
void Push_LinkStack(struct LinkStack* new_linkstack, struct posi_info new_value);

// 从栈中弹出一个元素
struct posi_info Pop_LinkStack(struct LinkStack* pop_linkstack);


// 定义一个结构体，表示链表中的一个节点，该节点中存储一个栈
// 在DFS中用于存储所有路径
struct List_LinkStack_node
{
	struct LinkStack value; // 存储节点的值，即一个栈
	struct List_LinkStack_node* next; // 指向下一个节点的指针
};

// 定义一个结构体，表示链栈构成的链表
struct List_LinkStack
{
	int size; // 链表的大小
	struct List_LinkStack_node* head; // 指向链表头的指针
	struct List_LinkStack_node* tail; // 指向链表尾的指针
};

// 创建一个新的链表
struct List_LinkStack* generate_List_LinkStack();






// 定义了一个结构体LinkQueue_node，表示队列中的节点，包含了一个position类型的值和指向下一个节点的指针
struct LinkQueue_node      
{
	struct posi_info value;
	struct LinkQueue_node* next;
};

// 定义了一个结构体queue，表示普通队列，包含了队列的大小、头指针和尾指针
struct LinkQueue         
{
	int size;
	struct LinkQueue_node* head;
	struct LinkQueue_node* tail;
};

    

// 定义了一个函数Enter_LinkQueue，将一个posi_info类型的值加入到队列中
void Enter_LinkQueue(struct LinkQueue* linkqueue, struct posi_info value);          

       


#endif // !__LINKQUEUE__
