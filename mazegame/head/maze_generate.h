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
* 生成全是0的地图
*/
struct posi_info** produce_init_maze(int row, int col);
struct posi_info** produce_blank_maze(int row, int col);

/*
* 使用Prim算法创建迷宫
* 要求预先传入用于存储的数组
* 0表示Wall， 1表示通路
*/
void prim_creatmaze(struct posi_info** pointer, int row, int col);

/*
* 该节点是否有未访问过的邻接点
*/
int unaccessed_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y);

/*
* 从所有的邻接点里随机选取一个
*/
struct posi_info* random_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y);

/*
* 消除两个节点之间的墙
*/
void eliminate_wall(struct posi_info** pointer, int x1, int y1, int x2, int y2);



/*
* 在dfs搜索获取距离信息之后
* 生成多通路迷宫
*/
void creat_multiroute_maze(struct posi_info** pointer, int row, int col);

/*
* 保存迷宫信息到map.m文件
*/
void save_maze_map(struct posi_info** pointer, int row, int col,int cx, int cy, double time, int mode, int difficulty,int mode2_guan);
//void save_maze_map(struct posi_info** pointer, int row, int col);

/*
* 读取已有的地图
*/
//struct posi_info** read_maze_map(int* row, int* col);
struct posi_info** read_maze_map(int* row, int* col,int* cx, int* cy, double* time, int* mode, int* difficulty,int* mode2_guan);

#endif // !__MAZE__

