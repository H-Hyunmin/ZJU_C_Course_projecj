#ifndef __search__
#define __search__

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
#include "data.h"

// ����ṹ��������ջ�б���ÿ��·�����м���Ϣ��
struct LinkStack* current_stack;

// ����������ڴ洢�㷨�ҵ�������·����
struct List_LinkStack* All_route;

void access(struct posi_info *pointer);

void add(struct posi_info **position_list,struct posi_info *posi,struct posi_info *pre);

void initsearch(struct posi_info** pointer);

void add_route(struct List_LinkStack_node** newhead, struct List_LinkStack** All_route,struct LinkStack** current_route);
/*
 * bfs����ʹ�ù�����������㷨��Ѱ�Ҵ����(x1, y1)���յ�(x2, y2)�����·����
 * arr��һ��ָ��posi_infoָ���ָ�룬��ʾ��ͼ��ÿ��λ�õ�״̬��
 * row��col�ǵ�ͼ��������������
 * ����һ��ָ��Linkstack�ṹ���ָ�룬���а����˴���㵽�յ�����·����
 */
struct LinkStack* BFS_Search(struct posi_info** pointer, int row, int col, int x1, int y1, int x2, int y2);





/*
* �������ʵ����������������㷨����������λ�����飨arr����ʾ���Թ��д���㣨x1��y1�����յ㣨x2��y2���ҵ����п��ܵ�·����
* x��y�ǵ�ǰλ�ã�count���ڴ洢�ݹ���ȡ�
*/
void DFS(struct posi_info** arr, int row, int col, int x1, int y1, int x2, int y2, int x, int y, int count);



#endif // !__search__
