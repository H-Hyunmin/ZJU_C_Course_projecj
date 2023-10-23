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

//linktqueue.h�ж������������нṹ��LinkQueue_node��LinkQueue����ʾ�����С�
//����LinkQueue_node������һ��posi_info���͵�ֵ��ָ����һ���ڵ��ָ�룬LinkQueue�����˶��еĴ�С��ͷָ���βָ�롣
//data.h�л��������������нṹ��List_LinkQueue_node��List_LinkQueue����ʾ�����е�һ���б�

// ����һ���ṹ�壬��ʾ��ջ�е�һ���ڵ�
struct LinkStack_node
{
	struct posi_info value; // �洢�ڵ��ֵ
	struct LinkStack_node* next; // ָ����һ���ڵ��ָ��
};

// ����һ���ṹ�壬��ʾ��ջ
struct LinkStack
{
	int size; // ��ջ�Ĵ�С
	struct LinkStack_node* head; // ָ��ջ����ָ��
};

// ����һ���µ�ջ
struct LinkStack* Init_LinkStack(void);

// ��һ��Ԫ��ѹ��ջ��
void Push_LinkStack(struct LinkStack* new_linkstack, struct posi_info new_value);

// ��ջ�е���һ��Ԫ��
struct posi_info Pop_LinkStack(struct LinkStack* pop_linkstack);


// ����һ���ṹ�壬��ʾ�����е�һ���ڵ㣬�ýڵ��д洢һ��ջ
// ��DFS�����ڴ洢����·��
struct List_LinkStack_node
{
	struct LinkStack value; // �洢�ڵ��ֵ����һ��ջ
	struct List_LinkStack_node* next; // ָ����һ���ڵ��ָ��
};

// ����һ���ṹ�壬��ʾ��ջ���ɵ�����
struct List_LinkStack
{
	int size; // ����Ĵ�С
	struct List_LinkStack_node* head; // ָ������ͷ��ָ��
	struct List_LinkStack_node* tail; // ָ������β��ָ��
};

// ����һ���µ�����
struct List_LinkStack* generate_List_LinkStack();






// ������һ���ṹ��LinkQueue_node����ʾ�����еĽڵ㣬������һ��position���͵�ֵ��ָ����һ���ڵ��ָ��
struct LinkQueue_node      
{
	struct posi_info value;
	struct LinkQueue_node* next;
};

// ������һ���ṹ��queue����ʾ��ͨ���У������˶��еĴ�С��ͷָ���βָ��
struct LinkQueue         
{
	int size;
	struct LinkQueue_node* head;
	struct LinkQueue_node* tail;
};

    

// ������һ������Enter_LinkQueue����һ��posi_info���͵�ֵ���뵽������
void Enter_LinkQueue(struct LinkQueue* linkqueue, struct posi_info value);          

       


#endif // !__LINKQUEUE__
