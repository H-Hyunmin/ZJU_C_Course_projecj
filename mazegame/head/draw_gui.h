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

#define WindowHeight 10  //窗口高度 
#define WindowWidth 16  //窗口宽度 

extern int page;//绘图界面控制
extern int mode;//游戏模式
extern int difficulty;//游戏难度
extern int define_row;//自定义行数
extern int define_col;//自定义列数
extern int mode2_guan;//关卡数

extern int IsSucceed;//游戏是否胜利
extern int RoutineDisplay;//是否在显示道路模式
extern int IsSaved;//游戏是否保存
extern int IsEditing;//是否在编辑地图模式
extern int MazeChanged;//迷宫是否改变
extern int saving;



extern HWND window;   //窗口句柄 



//迷宫生成与绘制
void generate_maze(int mode, int difficulty);
void generate_blank_maze(int mode ,int difficulty);
void define_generate_maze(int define_row, int define_col);
void define_generateblank_maze(int define_row,int define_col);

//展示成绩
void show_score(int mode);

//画出上方菜单
void draw_menu();

//菜单按键反馈
void select_menu1(int a);
void select_menu2(int a);
void select_menu3(int a);


//画出各界面
//使用参数page控制绘图的内容
void draw_page(int page);

//page1按键反馈
void start_button(int a);
void continue_button(int a);
void gameteach_button(int a);
void exit_button(int a);

//page2按键反馈
void only_start_button(int a);
void multi_start_button(int a);
void back_button(int a);

//page3按键反馈
void easy_start(int a);
void mid_start(int a);
void hard_start(int a);
void define_start(int a);
void ex_hard_start(int a);
void back_button2(int a);

//page4按键反馈
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

//page5按键反馈
void next_button(int a);
void back_button4(int a);

//page6按键反馈
void help_button(int a);
void back_button5(int a);

//page13按键反馈
void ruleexplain_button(int a);
void operate_button(int a);
void about_button(int a);
void back_button6(int a);
//page14按键反馈
void classicgame_button(int a);
void passthrough_button(int a);
void adventure_button(int a);
//page15按键反馈
void randmap_button(int a);
void editblankmap_button(int a);
void modeintroduce_button(int a);
void backlastpage_button(int a);
//page16按键反馈
void startgame16_button(int a);
void modeintroduce16_button(int a);
void backlastpage16_button(int a);


//page18按键反馈

void sure_button(int a);
void backlastpage18_button(int a);
//page19按键反馈
void success_restart_button19(int a);
//page20按键反馈
void  backlastpage20_button(int a);
void sure_button20(int a);
//page21按键反馈
void success_back_button21(int a);
void success_backlastpage_button21(int a);
void success_nextguan_button(int a);
void back_button21(int a);



#endif // !__GUI__
