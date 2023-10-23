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

// 这个结构体用于在栈中保存每个路径的中间信息。
struct LinkStack* current_stack;

// 这个链表用于存储算法找到的所有路径。
struct List_LinkStack* All_route;

void access(struct posi_info *pointer);

void add(struct posi_info **position_list,struct posi_info *posi,struct posi_info *pre);

void initsearch(struct posi_info** pointer);

void add_route(struct List_LinkStack_node** newhead, struct List_LinkStack** All_route,struct LinkStack** current_route);
/*
 * bfs函数使用广度优先搜索算法来寻找从起点(x1, y1)到终点(x2, y2)的最短路径。
 * arr是一个指向posi_info指针的指针，表示地图上每个位置的状态。
 * row和col是地图的行数和列数。
 * 返回一个指向Linkstack结构体的指针，其中包含了从起点到终点的最短路径。
 */
struct LinkStack* BFS_Search(struct posi_info** pointer, int row, int col, int x1, int y1, int x2, int y2);





/*
* 这个函数实现了深度优先搜索算法，用于在由位置数组（arr）表示的迷宫中从起点（x1，y1）到终点（x2，y2）找到所有可能的路径。
* x，y是当前位置，count用于存储递归深度。
*/
void DFS(struct posi_info** arr, int row, int col, int x1, int y1, int x2, int y2, int x, int y, int count);



#endif // !__search__
