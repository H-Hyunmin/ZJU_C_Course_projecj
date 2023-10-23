#include "../head/draw_gui.h"
#include "../head/search.h"

int page = 1;//1:主菜单，2:游戏界面，3:游戏结束，4:帮助，5:关于，6:编辑模式，7:保存，8:读取，9:难度选择，10:模式选择，11:游戏进行中，12:游戏暂停  13:游戏教程
int mode = 0;//1:经典,2:闯关模式,3:挑战模式
int difficulty = 1;//难度控制

int define_row = 10;//定义行数
int define_col =10;

int mode2_row = 0;
int mode2_col = 0;
int mode2_guan = 1;//关卡数

int iseditblankmap = 0;//是否编辑空白地图
int isselfdefinemap = 0;//是否随机生成地图
int IsSucceed = 0;//0:未成功，1:成功
int RoutineDisplay = 0;//显示所有路径模式
int IsEditing = 0;//是否在编辑模式
int MazeChanged = 1;//迷宫是否改变，进而是否需要绘制迷宫，减少绘图量
int saving=0;

HWND window;


//page
void draw_page(int page) {
	SetPenSize(2);
	// ();

	//初始页面
	if (page == 1) {
		ClearScreen(0, 0, 16, 10);
    	draw_bmp("./picture/mainpage.bmp",0,0,16,10);  //左上角定位
		char* page1[] = {
		"开始新游戏",
		"继续游戏",
		"游戏教程",
		"退出游戏    Ctrl-E"
		};
		//设置按钮位置及其大小
		double x, y, w, h;
		x = 3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		start_button(button(GenUIID(0), x-2, y, w, h, page1[0]));//新游戏
        draw_bmp("./picture/startgame.bmp",x-2,y+3.2,w,h);  //左上角定位
		continue_button(button(GenUIID(0), x + 1.5, y, w, h, page1[1]));//继续游戏
        draw_bmp("./picture/continuegame.bmp",x+1.5,y+3.2,w,h);  //左上角定位
        gameteach_button(button(GenUIID(0), x + 5.0, y, w, h, page1[2]));//游戏规则
        draw_bmp("./picture/gameteach.bmp",x+5.0,y+3.2,w,h);  //左上角定位
		exit_button(button(GenUIID(0), x + 8.5, y, w, h, page1[3]));
	    draw_bmp("./picture/exitgame.bmp",x+8.5,y+3.2,w,h);  //左上角定位
	}
	//选择难度
	if (page == 3) {
		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);
		char* label3[] = {
		"简单",
		"一般",
		"困难",
		"自定义",
		"返回上一页    Ctrl-B"
		};

		double x, y, w, h;
		x = 3.5;
		y = 2.5;
		h = 1.2;
		w = 1.7;

		easy_start(button(GenUIID(0), x-2, y, w, h, label3[0]));
        draw_bmp("./picture/easy.bmp",x-2,y+3.8,w,h);  //左上角定位
		mid_start(button(GenUIID(0), x + 0.8, y, w, h, label3[1]));
		draw_bmp("./picture/normal.bmp",x+0.8,y+3.8,w,h);  
		hard_start(button(GenUIID(0), x + 3.6, y, w, h, label3[2]));
		draw_bmp("./picture/hard.bmp",x+3.6,y+3.8,w,h);  
		define_start(button(GenUIID(0), x + 6.4, y, w, h, label3[3]));
		draw_bmp("./picture/selfdefine.bmp",x+6.4,y+3.8,w,h);  
		back_button2(button(GenUIID(0), x + 9.2, y, w, h, label3[4]));
		draw_bmp("./picture/backlastpage.bmp",x+9.2,y+3.8,w,h);  
	}
	//游戏开始
	if (page == 4) {
		//如果是初始化，就刷新
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}

		char* label3[] = {
		"最短路径",
		"全部路径",
		"保存    Ctrl-S",
		"返回上一页",
		"编辑地图"
		};
		//设置按钮位置及其大小
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //左上角定位
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //左上角定位
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //左上角定位
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //左上角定位
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);
		if (IsSucceed == 1) {
			//画出游戏胜利标签以及对应文字

					char* label[] = {
						"",
						"",
						""
				//"返回主菜单",
				//"返回上一页",
				//"再来一局"
			};

			double sx = 14;
			double sy = 6;
			double h = 0.8;
			double w = 1.44;
			double st =1;
			success_back_button(button(GenUIID(0), sx, sy, w, h, label[0]));
 			draw_bmp("./picture/gamebackmainpage.bmp",sx,sy+st-4.5,w,h); 	
			success_backlastpage_button(button(GenUIID(0), sx, sy - 1.25, w, h, label[1]));
			draw_bmp("./picture/gamebacklastpage.bmp",sx,sy+st-3.25,w,h);
			success_restart_button(button(GenUIID(0), sx, sy - 2.5, w, h, label[2]));
			draw_bmp("./picture/anothergame.bmp",sx,sy+st-2,w,h);
		
		}

		//绘制地图
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//绘制其它
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
	//显示路径模式
	if (page == 5) {
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}
		char* label3[] = {
		"下一路径",
		"返回游戏"
		};

		label3[0] = All_route->head == NULL ? "已全部显示" : "下一路径";
		//设置按钮位置及其大小
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;

		next_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
		draw_bmp("./picture/nextroute.bmp",x-0.5,y-t,w,h);
		back_button4(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/backgame.bmp",x+1.2,y-t,w,h);

		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		
	}
	//编辑地图模式
	if (page == 6) {
		ClearScreen(0, 0, 16, 10);
		Draw_Maze(MAZE, row, col);
		char* label3[] = {
		"查看帮助",
		"退出编辑"
		};

		//设置按钮位置及其大小
		// double x, y, w, h;
		// x = 1.0;
		// y = 7.0;
		// h = 1.2;
		// w = 2.4;
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;

		help_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
		draw_bmp("./picture/edithelp.bmp",x-0.5,y-t,w,h);
		back_button5(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/exitedit.bmp",x+1.2,y-t,w,h);
		Draw_Maze(MAZE, row, col);
		draw_selected(selected_x, selected_y, row, col);
	}

		if (page == 13) {
		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/teachpage.bmp",0,0,16,10);  //左上角定位
		char* label3[] = {
		"规则说明",
		"操作简介",
		"关于我们",
		"返回主菜单"
		};

		//设置按钮位置及其大小
		double x, y, w, h;
		x =3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		ruleexplain_button(button(GenUIID(0), x -2, y, w, h, label3[0]));
		draw_bmp("./picture/ruleexplain.bmp",x -2,y+3.2,w,h);  //左上角定位
        operate_button(button(GenUIID(0), x+1.5, y , w, h, label3[1]));
		draw_bmp("./picture/operate.bmp",x +1.5,y+3.2,w,h);
        about_button(button(GenUIID(0), x+5.0, y , w, h, label3[2]));
		draw_bmp("./picture/about.bmp",x +5,y+3.2,w,h);
        back_button6(button(GenUIID(0), x+8.5, y, w, h, label3[3]));
        draw_bmp("./picture/backmainpage.bmp",x +8.5,y+3.2,w,h);
	}
	if (page == 14) {

		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //左上角定位
		char* label3[] = {
		"经典模式",
		"闯关模式",
		"挑战模式",
		"返回主菜单"
		};

		//设置按钮位置及其大小
		double x, y, w, h;
		x =3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		classicgame_button(button(GenUIID(0), x -2, y, w, h, label3[0]));
		draw_bmp("./picture/classicmode.bmp",x -2,y+3.2,w,h);
        passthrough_button(button(GenUIID(0), x+1.5, y , w, h, label3[1]));
		draw_bmp("./picture/passthroughmode.bmp",x +1.5,y+3.2,w,h);
        adventure_button(button(GenUIID(0), x+5.0, y , w, h, label3[2]));
		draw_bmp("./picture/adventure.bmp",x +5,y+3.2,w,h);
        back_button(button(GenUIID(0), x+8.5, y, w, h, label3[3]));
        draw_bmp("./picture/backmainpage.bmp",x +8.5,y+3.2,w,h);
	}
		if (page == 15) {

		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //左上角定位
		char* label3[] = {
		"随机地图",
		"编辑空白地图",
		"模式介绍",
		"返回上一页"
		};

		//设置按钮位置及其大小
		double x, y, w, h;
		x =3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		randmap_button(button(GenUIID(0), x -2, y, w, h, label3[0]));
		draw_bmp("./picture/randommap.bmp",x -2,y+3.2,w,h);
        editblankmap_button(button(GenUIID(0), x+1.5, y , w, h, label3[1]));
		draw_bmp("./picture/editblankmap.bmp",x +1.5,y+3.2,w,h);
        modeintroduce_button(button(GenUIID(0), x+5.0, y , w, h, label3[2]));
		draw_bmp("./picture/modeinstruction.bmp",x +5,y+3.2,w,h);
        backlastpage_button(button(GenUIID(0), x+8.5, y, w, h, label3[3]));
		draw_bmp("./picture/backlastpage.bmp",x+8.5,y+3.2,w,h);        
	}
if (page == 16) {

		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/passthroughmodeground.bmp",0,0,16,10);  //左上角定位
		char* label3[] = {
		"开始游戏",
		"模式介绍",
		"返回上一页"
		};

		//设置按钮位置及其大小
		double x, y, w, h;
		x =4;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		startgame16_button(button(GenUIID(0), x -1, y, w, h, label3[0]));
       	draw_bmp("./picture/passthroughstartgame.bmp",x-1,y+3.2,w,h);
        modeintroduce16_button(button(GenUIID(0), x+2.5, y , w, h, label3[1]));
		draw_bmp("./picture/modeinstruction.bmp",x +2.5,y+3.2,w,h);
        backlastpage16_button(button(GenUIID(0), x+6, y, w, h, label3[2]));
       	draw_bmp("./picture/backlastpage.bmp",x+6,y+3.2,w,h);
	}	
if (page == 17) {
		//如果是初始化，就刷新
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}
		char* label3[] = {
		"最短路径",
		"全部路径",
		"保存    Ctrl-S",
		"返回上一页",
		"编辑地图"
		};
		//设置按钮位置及其大小
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //左上角定位
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //左上角定位
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //左上角定位
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //左上角定位
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);

		if (IsSucceed == 1) {
			//画出游戏胜利标签以及对应文字

					char* label[] = {
						"",
						"",
						""
				//"返回主菜单",
				//"返回上一页",
				//"再来一局"
			};

			double sx = 14;
			double sy = 6;
			double h = 0.8;
			double w = 1.44;
			double st =1;
			success_back_button(button(GenUIID(0), sx, sy, w, h, label[0]));
 			draw_bmp("./picture/gamebackmainpage.bmp",sx,sy+st-4.5,w,h); 	
			success_backlastpage_button(button(GenUIID(0), sx, sy - 1.25, w, h, label[1]));
			draw_bmp("./picture/gamebacklastpage.bmp",sx,sy+st-3.25,w,h);
			success_restart_button(button(GenUIID(0), sx, sy - 2.5, w, h, label[2]));
			draw_bmp("./picture/anothergame.bmp",sx,sy+st-2,w,h);
		
		}

		//绘制地图
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//绘制其它
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
	if (page == 18) {

		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //左上角定位
		char* label3[] = {
		"确定",
		"返回上一页"
		};
       	static char lable1[80]=""; 
       	static char lable2[80]=""; 
		//设置按钮位置及其大小
		double x, y, w, h;
		x =3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;
		draw_bmp("./picture/inputrow.bmp",x ,y+2,w*1.5,h*1.5);
		draw_bmp("./picture/inputcol.bmp",x+5.2 ,y+2,w*1.5,h*1.5);
	    if(textbox(GenUIID(0), x+2.9, y+1.2, 0.35, 0.5, lable1, sizeof(lable1))){
			sscanf(lable1,"%d",&define_row);
		}
		if(define_row!=10){
			printf("%d",define_row);
		}

	    if(textbox(GenUIID(0), x+8.1, y+1.2, 0.35, 0.5, lable2, sizeof(lable2))){
			sscanf(lable2,"%d",&define_col);
		}
		if(define_col!=10){
			printf("%d",define_col);
		}



		sure_button( button(GenUIID(0), x+1.5, y-1.8 , w, h, label3[0]));
		draw_bmp("./picture/sure.bmp",x +1.5,y+5.0,w,h);
        backlastpage18_button(button(GenUIID(0), x+5.0, y-1.8 , w, h, label3[1]));
        draw_bmp("./picture/backlastpage.bmp",x +5.0,y+5.0,w,h);
	}
//游戏开始
	if (page == 19) {
		//如果是初始化，就刷新
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}

			char* label3[] = {
		"最短路径",
		"全部路径",
		"保存    Ctrl-S",
		"返回上一页",
		"编辑地图"
		};
		//设置按钮位置及其大小
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //左上角定位
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //左上角定位
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //左上角定位
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //左上角定位
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);
		if (IsSucceed == 1) {
			//画出游戏胜利标签以及对应文字

					char* label[] = {
						"",
						"",
						"",
						""
				//"返回主菜单",
				//"返回上一页",
				//"再来一局"
			};

			double sx = 14;
			double sy = 6;
			double h = 0.8;
			double w = 1.44;
			double st =1;
			success_back_button(button(GenUIID(0), sx, sy, w, h, label[0]));
 			draw_bmp("./picture/gamebackmainpage.bmp",sx,sy+st-4.5,w,h); 	
			success_backlastpage_button(button(GenUIID(0), sx, sy - 1.25, w, h, label[1]));
			draw_bmp("./picture/gamebacklastpage.bmp",sx,sy+st-3.25,w,h);
			success_restart_button(button(GenUIID(0), sx, sy - 2.5, w, h, label[2]));
			draw_bmp("./picture/anothergame.bmp",sx,sy+st-2,w,h);
		
		}


		//绘制地图
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//绘制其它
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
	if (page == 20) {

	
		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //左上角定位
		char* label3[] = {
		"确定",
		"返回上一页"
		};
       	static char lable1[80]=""; 
       	static char lable2[80]=""; 
		//设置按钮位置及其大小
		double x, y, w, h;
		x =3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;
		draw_bmp("./picture/inputrow.bmp",x ,y+2,w*1.5,h*1.5);
		draw_bmp("./picture/inputcol.bmp",x+5.2 ,y+2,w*1.5,h*1.5);
	    if(textbox(GenUIID(0), x+2.9, y+1.2, 0.35, 0.5, lable1, sizeof(lable1))){
			sscanf(lable1,"%d",&define_row);
		}
		if(define_row!=10){
			printf("%d",define_row);
		}

	    if(textbox(GenUIID(0), x+8.1, y+1.2, 0.35, 0.5, lable2, sizeof(lable2))){
			sscanf(lable2,"%d",&define_col);
		}
		if(define_col!=10){
			printf("%d",define_col);
		}



		sure_button20( button(GenUIID(0), x+1.5, y-1.8 , w, h, label3[0]));
		draw_bmp("./picture/sure.bmp",x +1.5,y+5.0,w,h);
        backlastpage20_button(button(GenUIID(0), x+5.0, y-1.8 , w, h, label3[1]));
        draw_bmp("./picture/backlastpage.bmp",x +5.0,y+5.0,w,h);
	}

	//闯关模式	
if (page == 21) {
		//如果是初始化，就刷新
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}

		
		char* label3[] = {
		"最短路径",
		"全部路径",
		"保存    Ctrl-S",
		"返回上一页",
		"编辑地图"
		};
		//设置按钮位置及其大小
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //左上角定位
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //左上角定位
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //左上角定位
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //左上角定位
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);

		if (IsSucceed == 1) {
			//画出游戏胜利标签以及对应文字

					char* label[] = {
						"",
						"",
						"",
						""
				//"返回主菜单",
				//"返回上一页",
				//"再来一局"
			};

			double sx = 14;
			double sy = 6;
			double h = 0.8;
			double w = 1.44;
			double st =1;
			success_back_button21(button(GenUIID(0), sx, sy, w, h, label[0]));
 			draw_bmp("./picture/gamebackmainpage.bmp",sx,sy+st-4.5,w,h); 	
			success_backlastpage_button21(button(GenUIID(0), sx, sy - 1.25, w, h, label[1]));
			draw_bmp("./picture/gamebacklastpage.bmp",sx,sy+st-3.25,w,h);
			success_nextguan_button(button(GenUIID(0), sx, sy - 2.5, w, h, label[2]));
			draw_bmp("./picture/nextguan.bmp",sx,sy+st-2,w,h);
		
		}



		//绘制地图
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//绘制其它
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}


//page1
void drawpage1(){
		ClearScreen(0, 0, 16, 10);
    	draw_bmp("./picture/mainpage.bmp",0,0,16,10);  //左上角定位
		char* page1[] = {
		"开始新游戏",
		"继续游戏",
		"游戏教程",
		"退出游戏    Ctrl-E"
		};
		//设置按钮位置及其大小
		double x, y, w, h;
		x = 3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		start_button(button(GenUIID(0), x-2, y, w, h, page1[0]));//新游戏
        draw_bmp("./picture/startgame.bmp",x-2,y+3.2,w,h);  //左上角定位
		continue_button(button(GenUIID(0), x + 1.5, y, w, h, page1[1]));//继续游戏
        draw_bmp("./picture/continuegame.bmp",x+1.5,y+3.2,w,h);  //左上角定位
        gameteach_button(button(GenUIID(0), x + 5.0, y, w, h, page1[2]));//游戏规则
        draw_bmp("./picture/gameteach.bmp",x+5.0,y+3.2,w,h);  //左上角定位
		exit_button(button(GenUIID(0), x + 8.5, y, w, h, page1[3]));
	    draw_bmp("./picture/exitgame.bmp",x+8.5,y+3.2,w,h);  //左上角定位
}
void start_button(int a) {
	if (a == 1) {

		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 14;
	}
}

void continue_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);

		//导入上次地图，获取尺寸信息
		MAZE = read_maze_map(&row, &col,&current_x, &current_y, &GameTime, &mode, &difficulty,&mode2_guan);

		//设置游戏参数
		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		//游戏开始
		MazeChanged = 1;
		if (mode==1)page = 4;
		if (mode==2)page =21;
		GameOn = 1;
	}
}

void gameteach_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 13;
	}
}

void exit_button(int a) {
	if (a == 1) {
		//关闭程序
		exit(1);
	}
}

//page2
void only_start_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		mode = 0;
		//generate_maze(mode);
		page = 3;
		//GameOn = 1;
		DisplayClear();
	}
}

void multi_start_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		mode = 1;
		//generate_maze(mode);
		page = 3;
		//GameOn = 1;
	}
}

void back_button(int a) {
	if (a == 1) {
		GameOn = 0;
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		page = 1;
	}
}

//page3
void easy_start(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		difficulty = 1;
		generate_maze(mode, difficulty);
		page = 4;
		GameOn = 1;
	}
}

void mid_start(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		difficulty = 2;
		generate_maze(mode, difficulty);
		page = 4;
		GameOn = 1;
	}
}
void hard_start(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		difficulty = 3;
		generate_maze(mode, difficulty);
		page = 4;
		GameOn = 1;
	}
}
void define_start(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 18;
	}
}
void ex_hard_start(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		difficulty = 4;
		generate_maze(mode, difficulty);
		page = 4;
		GameOn = 1;
	}
}
void back_button2(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		GameOn = 0;
		page = 15;
	}
}

//page4

void short_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		struct LinkStack* temp = BFS_Search(MAZE, row, col, current_x, current_y, end_x, end_y);
		
		draw_page(page);
		Draw_Maze(MAZE, row, col);
		Draw_Routine(temp, row, col);
	}
}

void all_button(int a) {
	if (a == 1) {
		if (mode == 0) {
			Refresh();
			ClearScreen(0, 0, 16, 10);
			MazeChanged = 1;

			struct LinkStack* temp = BFS_Search(MAZE, row, col, current_x, current_y, end_x, end_y);

			Draw_Routine(temp, row, col);
		}
		if (mode == 1 || 2) {
			//暂停计时器
			//算出路径
			int count = 0;
			DFS(MAZE, row, col, current_x, current_y, end_x, end_y, current_x, current_y, count);
			//进入显示模式
			Refresh();
			ClearScreen(0, 0, 16, 10);
			MazeChanged = 1;
			RoutineDisplay = 1;
			page = 5;
		}
	}
}



void save_button(int a) {
	if (a == 1) {
		//保存地图
		saving=1;
		save_maze_map(MAZE, row, col, current_x, current_y, GameTime, mode, difficulty,mode2_guan);
		//保存其它信息
		page = 4;
	}
}

void back_button3(int a) {
	if (a == 1) {
		
			GameOn = 0;
			Refresh();
			ClearScreen(0, 0, 16, 10);
			//清空所有数据
			page = 15;
			mode = 0;//0:单通路，1:多通路
			difficulty = 1;//难度控制
			IsSucceed = 0;
			RoutineDisplay = 0;//显示所有路径模式
			IsEditing = 0;//是否在编辑模式
			MazeChanged = 1;//迷宫是否改变
			iseditblankmap = 0;
			isselfdefinemap = 0;
		//}
	}
}

void edit_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		IsEditing = 1;
		page = 6;
	}
}

void success_back_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		GameOn = 0;
		page = 1;
		mode = 0;//0:单通路，1:多通路
		difficulty = 1;//难度控制
		IsSucceed = 0;
		RoutineDisplay = 0;//显示所有路径模式
		IsEditing = 0;//是否在编辑模式
		MazeChanged = 1;//迷宫是否改变
		iseditblankmap = 0;
		isselfdefinemap = 0;
	}
}

void success_backlastpage_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		GameOn = 0;
		page = 15;
		mode = 0;//0:单通路，1:多通路
		difficulty = 1;//难度控制
		IsSucceed = 0;
		RoutineDisplay = 0;//显示所有路径模式
		IsEditing = 0;//是否在编辑模式
		MazeChanged = 1;//迷宫是否改变
		iseditblankmap = 0;
		isselfdefinemap = 0;
	}
}

void success_restart_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		GameOn = 0;
		IsSucceed = 0;
		RoutineDisplay = 0;//显示所有路径模式
		IsEditing = 0;//是否在编辑模式
		MazeChanged = 1;//迷宫是否改变
		//重新开始
		if (iseditblankmap==1) {
		generate_maze(mode, difficulty);
			page=20;
			}
		else if (isselfdefinemap==1) {
			generate_maze(mode, difficulty);
			page=18;
		}		


		else {
		GameOn = 1;
		generate_maze(mode, difficulty);
		page = 4;			
		}

		iseditblankmap = 0;
		isselfdefinemap = 0;
		draw_page(page);
	}
}

//page5
void next_button(int a) {
	if (a == 1) {
		if (All_route->head != NULL) {
			Refresh();
			ClearScreen(0, 0, 16, 10);
			MazeChanged = 1;

			
			draw_page(page);
			Draw_Maze(MAZE, row, col);
			draw_page(page);
			Draw_Routine(&All_route->head->value, row, col);
			All_route->head = All_route->head->next;

		}
		if (All_route->head == NULL) {
			ClearScreen(0, 0, 3, 10);
		}
	}
}

void back_button4(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		RoutineDisplay = 0;
		GameOn = 1;
		page = 4;
	}
}

//page6
void help_button(int a) {
	//跳出帮助
	if (a == 1) {
		MessageBox(
			window,
			TEXT("使用鼠标选择单元格,用wasd生成或消除地图中的墙"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}

void back_button5(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		IsEditing = 0;
		page = 4;
		GameOn = 1;
	}
}
//page 13
		void ruleexplain_button(int a) {
	//跳出帮助
	if (a == 1) {
		MessageBox(
			window,
			TEXT("规则说明：走出迷宫作为胜利条件，经典模式为一张地图，地图可选择自行创建和随机生成。闯关模式无限关卡；"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}

		void  operate_button(int a) {
	//跳出帮助
	if (a == 1) {
		MessageBox(
			window,
			TEXT("方向键操控小人进行前后左右的移动，在编辑地图的模式下能使用鼠标选择和wasd键进行生成或者取消墙的操作"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}
     
	 		void about_button(int a) {
	//跳出帮助
	if (a == 1) {
		MessageBox(
			window,
			TEXT(""),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}

void back_button6(int a) {
	if (a == 1) {
		GameOn = 0;
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		page = 1;
	}
}


 //page 14
void classicgame_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		mode=1;
		page = 15;
	}
}

void passthrough_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		mode = 2;
		page = 16;
	}
}

void adventure_button(int a) {
	if (a == 1) {
		MessageBox(
			window,
			TEXT("开发中，敬请期待"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		mode=3;
	}
}


//page 15
void randmap_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		mode = 1;
		//generate_maze(mode);
		page = 3;
		//GameOn = 1;
	}
}


void editblankmap_button(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 20;
	}
}
void modeintroduce_button(int a){
		if (a == 1) {
		MessageBox(
			window,
			TEXT("经典模式为一张地图，地图可选择自行创建和随机生成。可以自定义地图大小和生成空白地图。在编辑地图的模式下能使用鼠标选择+wasd键进行生成或者取消墙的操作。"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}


void backlastpage_button(int a){
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 14;
	}

}


//page 16

void startgame16_button(int a){
		if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
        mode2_guan=1;
		mode2_col=5;
		mode2_row=5;
		GameOn = 1;
        define_generate_maze(mode2_row,mode2_col);
		//generate_maze(mode, difficulty);
		GameOn = 1;
		page = 21;
	}

}
void modeintroduce16_button(int a){
		if (a == 1) {
		MessageBox(
			window,
			TEXT("闯关模式无限关卡，难度递增"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}
void backlastpage16_button(int a){
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 14;
	}
}

//page 17

//page 18
void sure_button(int a){

	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
        define_generate_maze(define_row,define_col);
		//generate_maze(mode, difficulty);
		GameOn = 1;
		isselfdefinemap=1;
		page = 4;
	}
}


void  backlastpage18_button(int a){
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 15;
	}
}

//page 19
void success_restart_button19(int a){
		if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 15;
	}
}

//page 20
void sure_button20(int a){

	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
        define_generateblank_maze(define_row,define_col);
		//generate_maze(mode, difficulty);
		GameOn = 1;
		mode=1;
		iseditblankmap=1;
		page = 19;
	}
}

void  backlastpage20_button(int a){
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		page = 15;
	}
}

//page 21
void success_nextguan_button(int a){
		if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
		IsSucceed = 0;
		mode2_guan++;
		switch (mode2_guan)
		{
		case 2: mode2_col=7;mode2_row=7;
			break;
		case 3: mode2_col=10;mode2_row=10;
			break;		
		case 4: mode2_col=15;mode2_row=15;
			break;
		case 5: mode2_col=20;mode2_row=18;
			break;
		case 6: mode2_col=25;mode2_row=20;
			break;
		case 7: mode2_col=30;mode2_row=23;
			break;
		case 8: mode2_col=43;mode2_row=25;
			break;
		case 9: mode2_col=37;mode2_row=28;
			break;
		case 10: mode2_col=40;mode2_row=30;
			break;
		case 11: mode2_col=45;mode2_row=32;
			break;
		default: mode2_col=50;mode2_row=32;
			break;
		}
        define_generate_maze(mode2_row,mode2_col);
		//generate_maze(mode, difficulty);
		GameOn = 1;
		page = 21;

	}
}

void back_button21(int a) {
if (a == 1) {
			GameOn = 0;
			Refresh();
			ClearScreen(0, 0, 16, 10);
			//清空所有数据
			page = 16;
			mode = 0;//0:单通路，1:多通路
			difficulty = 1;//难度控制
			IsSucceed = 0;
			RoutineDisplay = 0;//显示所有路径模式
			IsEditing = 0;//是否在编辑模式
			MazeChanged = 1;//迷宫是否改变
		}
}
void success_back_button21(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);

		GameOn = 0;
		//清空所有数据
		page = 1;
		mode = 2;//0:单通路，1:多通路
		difficulty = 1;//难度控制
		IsSucceed = 0;
		RoutineDisplay = 0;//显示所有路径模式
		IsEditing = 0;//是否在编辑模式
		MazeChanged = 1;//迷宫是否改变
	}
}

void success_backlastpage_button21(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		GameOn = 0;
		//清空所有数据
		page = 16;
		mode = 2;//0:单通路，1:多通路
		difficulty = 1;//难度控制
		IsSucceed = 0;
		RoutineDisplay = 0;//显示所有路径模式
		IsEditing = 0;//是否在编辑模式
		MazeChanged = 1;//迷宫是否改变
	}
}


/*
 * 该函数将迷宫的信息保存到文件中。
 * 
 * 参数：
 * arr：迷宫的二维数组
 * row：迷宫的行数
 * col：迷宫的列数
 * 返回值：无
 */
void save_maze_map(struct posi_info** pointer, int row, int col,int cx, int cy, double time, int mode, int difficulty,int mode2_guan) {
	    saving =0;
		FILE *fp = fopen("./map/maze_map.m", "wb");
		if (fp == NULL){
		printf("Error opening!\n");
		exit(1);
		}

		// 写入迷宫的行数和列数
		fwrite(&row, sizeof(int), 1, fp);
		fwrite(&col, sizeof(int), 1, fp);

		// 写入迷宫的每个位置的信息
		int i = 0;
		for (i = 0; i < row; i++) {
		fwrite(pointer[i], sizeof(struct posi_info), col, fp);
		}
		fwrite(&cx, sizeof(int), 1, fp);//写入当前玩家的位置的横坐标
		fwrite(&cy, sizeof(int), 1, fp);//写入当前玩家的位置的纵坐标
		fwrite(&time, sizeof(double), 1, fp);//写入游戏用时
		fwrite(&mode, sizeof(int), 1, fp);//写入游戏模式
		fwrite(&difficulty, sizeof(int), 1, fp);//写入游戏难度
		fwrite(&mode2_guan, sizeof(int), 1, fp);//写入游戏模式2的关卡

		// 关闭文件
		fclose(fp);
}





/*
 * 该函数从文件中读取迷宫的信息，并返回一个指向迷宫二维数组的指针。
 * 
 * 参数：
 * row：指向整型变量的指针，用于存储迷宫的行数
 * col：指向整型变量的指针，用于存储迷宫的列数
 * 
 * 返回值：
 * 该函数返回一个指向迷宫二维数组的指针，该数组存储了迷宫的每个位置的信息。
 * 
 * 注意：
 * 该函数会动态分配内存，调用者需要负责释放该内存。
 */
struct posi_info** read_maze_map(int* row, int* col,int* cx, int* cy, double* time, int* mode, int* difficulty,int* mode2_guan){

		
		FILE *fp = fopen("./map/maze_map.m", "rb");
	if (fp == NULL) { // 如果文件不存在，则返回NULL
		printf("Error opening!\n");
		exit(1);
	}

	// 读取迷宫的行数和列数
	fread(row, sizeof(int), 1, fp);
	fread(col, sizeof(int), 1, fp);

	// 动态分配内存
	int i = 0, j = 0, k = 0; 
	struct posi_info** pointer = (struct posi_info**)malloc((*row) * sizeof(struct posi_info*));//分配行
	for (i = 0; i < *row; i++) {
		pointer[i] = (struct posi_info*)malloc((*col) * sizeof(struct posi_info));//分配列
	}

	// 读取迷宫的每个位置的信息
	for (i = 0; i < *row; i++) {
		fread(pointer[i], sizeof(struct posi_info), (*col), fp);
	}
	
	fread(cx, sizeof(int), 1, fp);
	fread(cy, sizeof(int), 1, fp);
	fread(time, sizeof(double), 1, fp);
	fread(mode, sizeof(int), 1, fp);
	fread(difficulty, sizeof(int), 1, fp);
	fread(mode2_guan, sizeof(int), 1, fp);
	// 关闭文件
	fclose(fp);

	// 返回指向迷宫二维数组的指针
	return pointer;
}
void ClearScreen(double x, double y, double width, double height)
{
	SetPenColor("White");
	MovePen(x - 0.1, y - 0.1);
	StartFilledRegion(0);
	DrawLine(width + 0.2, 0);
	DrawLine(0, height + 0.2);
	DrawLine(-width - 0.2, 0);
	DrawLine(0, -height - 0.2);
	EndFilledRegion();
}
void Refresh(){
				// 获取当前窗口的句柄
			HWND hwnd = GetForegroundWindow();
			// 强制刷新当前窗口
			UpdateWindow(hwnd);

}