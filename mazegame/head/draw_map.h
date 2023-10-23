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



//��ͼ��λ��Ϣ
#define Boxlength 0.26  //���ӳ��� 
#define Boxwidth 0.26  //���ӿ�� 
#define Centerx 7.0     //�Թ����ĵ������
#define Centery 4.64    //�Թ����ĵ�������
#define Radius 0.05   //�켣Բ��İ뾶 



//��������
void ClearScreen(double x, double y, double width, double height);

//�Թ�����תͼ������
//ת���߼����Թ�����(x,y) -> ͼ������(y,x)


double zsjx(int row ,int col);
double zsjy(int row ,int col);

double curzsjx(int y, int row, int col);
double curzsjy(int x, int row, int col);
double txzsjy(int y, int row, int col);

//�����Թ�
void Draw_Maze(struct posi_info** arr, int row, int col);

//��������
void Draw_Robot(int x, int y, int row, int col);


//�����յ�
void Draw_Destination(int x, int y, int row, int col);


//���ӻ�·��
void Draw_Routine(struct LinkStack* s, int row, int col);

//�༭ģʽ��Ⱦɫ
void draw_selected(int x, int y, int row, int col);
//��ʽ����
void Refresh();
int unaccessed_adjacentnode(struct posi_info** pointer, int row, int col, int x, int y);
#endif // !__DRAW_MAP__

