#ifndef __MAZE__
#define __MAZE__

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
#include "search.h"


/*
* ����ȫ��0�ĵ�ͼ
*/
struct posi_info** produce_init_maze(int row, int col);
struct posi_info** produce_blank_maze(int row, int col);

/*
* ʹ��Prim�㷨�����Թ�
* Ҫ��Ԥ�ȴ������ڴ洢������
* 0��ʾWall�� 1��ʾͨ·
*/
void prim_creatmaze(struct posi_info** pointer, int row, int col);

/*
* �ýڵ��Ƿ���δ���ʹ����ڽӵ�
*/
int unaccessed_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y);

/*
* �����е��ڽӵ������ѡȡһ��
*/
struct posi_info* random_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y);

/*
* ���������ڵ�֮���ǽ
*/
void eliminate_wall(struct posi_info** pointer, int x1, int y1, int x2, int y2);



/*
* ��dfs������ȡ������Ϣ֮��
* ���ɶ�ͨ·�Թ�
*/
void creat_multiroute_maze(struct posi_info** pointer, int row, int col);

/*
* �����Թ���Ϣ��map.m�ļ�
*/
void save_maze_map(struct posi_info** pointer, int row, int col,int cx, int cy, double time, int mode, int difficulty,int mode2_guan);
//void save_maze_map(struct posi_info** pointer, int row, int col);

/*
* ��ȡ���еĵ�ͼ
*/
//struct posi_info** read_maze_map(int* row, int* col);
struct posi_info** read_maze_map(int* row, int* col,int* cx, int* cy, double* time, int* mode, int* difficulty,int* mode2_guan);

#endif // !__MAZE__

