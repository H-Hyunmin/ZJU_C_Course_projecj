#ifndef __DRAW_MAP__
#define __DRAW_MAP__

#include "maze_generate.h"
#include "data.h"

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



//绘图定位信息
#define Boxlength 0.26  //格子长度 
#define Boxwidth 0.26  //格子宽度 
#define Centerx 7.0     //迷宫中心点横坐标
#define Centery 4.64    //迷宫中心点纵坐标
#define Radius 0.05   //轨迹圆点的半径 



//清屏函数
void ClearScreen(double x, double y, double width, double height);

//迷宫坐标转图形坐标
//转化逻辑：迷宫坐标(x,y) -> 图形坐标(y,x)


double zsjx(int row ,int col);
double zsjy(int row ,int col);

double curzsjx(int y, int row, int col);
double curzsjy(int x, int row, int col);
double txzsjy(int y, int row, int col);

//画出迷宫
void Draw_Maze(struct posi_info** arr, int row, int col);

//画出人物
void Draw_Robot(int x, int y, int row, int col);


//画出终点
void Draw_Destination(int x, int y, int row, int col);


//可视化路线
void Draw_Routine(struct LinkStack* s, int row, int col);

//编辑模式下染色
void draw_selected(int x, int y, int row, int col);
//样式设置
void Refresh();
int unaccessed_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y);
#endif // !__DRAW_MAP__

