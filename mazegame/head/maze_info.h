#ifndef __MAZE_INFO__
#define __MAZE_INFO__
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
#include <time.h>

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



// 定义一个结构体 posi_info，用于表示迷宫中的每个位置的信息
typedef struct posi_info
{
	int row;            // 行坐标
	int column;         // 列坐标
	int access;     // 是否可通过 1可通过 0不可通过
	int pass_direction[4];    // 左右上下 四个方向是否可行 1可行 0不可行
	struct posi_info* pre;   // 前驱结点  用于BFS记录路径

}posi_info;

// typedef struct prop{
// 	int isgold;
// }prop;

#define WindowHeight 10  //窗口高度 
#define WindowWidth 16  //窗口宽度 
#define MazeCenter 7.5 //迷宫中心
#define MazeCubeLength 0.2 //迷宫单格大小

//迷宫所需基本信息
extern int row, col;
extern int start_x, start_y;
extern int end_x, end_y;

extern int current_x, current_y;
extern int selected_x, selected_y;

extern struct posi_info** MAZE;



#endif // !__MAZE_INFO__

//void Draw_Maze(struct position** arr, int row, int col);