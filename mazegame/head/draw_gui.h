#ifndef __GUI__
#define __GUI__
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

#include "draw_map.h"
#include "callback.h"

#define WindowHeight 10  //���ڸ߶� 
#define WindowWidth 16  //���ڿ�� 

extern int page;//��ͼ�������
extern int mode;//��Ϸģʽ
extern int difficulty;//��Ϸ�Ѷ�
extern int define_row;//�Զ�������
extern int define_col;//�Զ�������
extern int mode2_guan;//�ؿ���

extern int IsSucceed;//��Ϸ�Ƿ�ʤ��
extern int RoutineDisplay;//�Ƿ�����ʾ��·ģʽ
extern int IsSaved;//��Ϸ�Ƿ񱣴�
extern int IsEditing;//�Ƿ��ڱ༭��ͼģʽ
extern int MazeChanged;//�Թ��Ƿ�ı�
extern int saving;



extern HWND window;   //���ھ�� 



//�Թ����������
void generate_maze(int mode, int difficulty);
void generate_blank_maze(int mode ,int difficulty);
void define_generate_maze(int define_row, int define_col);
void define_generateblank_maze(int define_row,int define_col);

//չʾ�ɼ�
void show_score(int mode);

//�����Ϸ��˵�
void draw_menu();

//�˵���������
void select_menu1(int a);
void select_menu2(int a);
void select_menu3(int a);


//����������
//ʹ�ò���page���ƻ�ͼ������
void draw_page(int page);

//page1��������
void start_button(int a);
void continue_button(int a);
void gameteach_button(int a);
void exit_button(int a);

//page2��������
void only_start_button(int a);
void multi_start_button(int a);
void back_button(int a);

//page3��������
void easy_start(int a);
void mid_start(int a);
void hard_start(int a);
void define_start(int a);
void ex_hard_start(int a);
void back_button2(int a);

//page4��������
void tip_button(int a);
void short_button(int a);
void all_button(int a);
void show_short_button(int a);
void pause_button(int a);
void save_button(int a);
void back_button3(int a);
void edit_button(int a);

void success_back_button(int a);
void success_backlastpage_button(int a);
void success_restart_button(int a);

//page5��������
void next_button(int a);
void back_button4(int a);

//page6��������
void help_button(int a);
void back_button5(int a);

//page13��������
void ruleexplain_button(int a);
void operate_button(int a);
void about_button(int a);
void back_button6(int a);
//page14��������
void classicgame_button(int a);
void passthrough_button(int a);
void adventure_button(int a);
//page15��������
void randmap_button(int a);
void editblankmap_button(int a);
void modeintroduce_button(int a);
void backlastpage_button(int a);
//page16��������
void startgame16_button(int a);
void modeintroduce16_button(int a);
void backlastpage16_button(int a);


//page18��������

void sure_button(int a);
void backlastpage18_button(int a);
//page19��������
void success_restart_button19(int a);
//page20��������
void  backlastpage20_button(int a);
void sure_button20(int a);
//page21��������
void success_back_button21(int a);
void success_backlastpage_button21(int a);
void success_nextguan_button(int a);
void back_button21(int a);



#endif // !__GUI__
