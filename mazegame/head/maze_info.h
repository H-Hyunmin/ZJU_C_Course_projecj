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



// ����һ���ṹ�� posi_info�����ڱ�ʾ�Թ��е�ÿ��λ�õ���Ϣ
typedef struct posi_info
{
	int row;            // ������
	int column;         // ������
	int access;     // �Ƿ��ͨ�� 1��ͨ�� 0����ͨ��
	int pass_direction[4];    // �������� �ĸ������Ƿ���� 1���� 0������
	struct posi_info* pre;   // ǰ�����  ����BFS��¼·��

}posi_info;

// typedef struct prop{
// 	int isgold;
// }prop;

#define WindowHeight 10  //���ڸ߶� 
#define WindowWidth 16  //���ڿ�� 
#define MazeCenter 7.5 //�Թ�����
#define MazeCubeLength 0.2 //�Թ������С

//�Թ����������Ϣ
extern int row, col;
extern int start_x, start_y;
extern int end_x, end_y;

extern int current_x, current_y;
extern int selected_x, selected_y;

extern struct posi_info** MAZE;



#endif // !__MAZE_INFO__

//void Draw_Maze(struct position** arr, int row, int col);