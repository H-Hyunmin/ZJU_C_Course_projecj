#include "../head/draw_gui.h"
#include "../head/search.h"

int page = 1;//1:���˵���2:��Ϸ���棬3:��Ϸ������4:������5:���ڣ�6:�༭ģʽ��7:���棬8:��ȡ��9:�Ѷ�ѡ��10:ģʽѡ��11:��Ϸ�����У�12:��Ϸ��ͣ  13:��Ϸ�̳�
int mode = 0;//1:����,2:����ģʽ,3:��սģʽ
int difficulty = 1;//�Ѷȿ���

int define_row = 10;//��������
int define_col =10;

int mode2_row = 0;
int mode2_col = 0;
int mode2_guan = 1;//�ؿ���

int iseditblankmap = 0;//�Ƿ�༭�հ׵�ͼ
int isselfdefinemap = 0;//�Ƿ�������ɵ�ͼ
int IsSucceed = 0;//0:δ�ɹ���1:�ɹ�
int RoutineDisplay = 0;//��ʾ����·��ģʽ
int IsEditing = 0;//�Ƿ��ڱ༭ģʽ
int MazeChanged = 1;//�Թ��Ƿ�ı䣬�����Ƿ���Ҫ�����Թ������ٻ�ͼ��
int saving=0;

HWND window;


//page
void draw_page(int page) {
	SetPenSize(2);
	// ();

	//��ʼҳ��
	if (page == 1) {
		ClearScreen(0, 0, 16, 10);
    	draw_bmp("./picture/mainpage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* page1[] = {
		"��ʼ����Ϸ",
		"������Ϸ",
		"��Ϸ�̳�",
		"�˳���Ϸ    Ctrl-E"
		};
		//���ð�ťλ�ü����С
		double x, y, w, h;
		x = 3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		start_button(button(GenUIID(0), x-2, y, w, h, page1[0]));//����Ϸ
        draw_bmp("./picture/startgame.bmp",x-2,y+3.2,w,h);  //���ϽǶ�λ
		continue_button(button(GenUIID(0), x + 1.5, y, w, h, page1[1]));//������Ϸ
        draw_bmp("./picture/continuegame.bmp",x+1.5,y+3.2,w,h);  //���ϽǶ�λ
        gameteach_button(button(GenUIID(0), x + 5.0, y, w, h, page1[2]));//��Ϸ����
        draw_bmp("./picture/gameteach.bmp",x+5.0,y+3.2,w,h);  //���ϽǶ�λ
		exit_button(button(GenUIID(0), x + 8.5, y, w, h, page1[3]));
	    draw_bmp("./picture/exitgame.bmp",x+8.5,y+3.2,w,h);  //���ϽǶ�λ
	}
	//ѡ���Ѷ�
	if (page == 3) {
		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);
		char* label3[] = {
		"��",
		"һ��",
		"����",
		"�Զ���",
		"������һҳ    Ctrl-B"
		};

		double x, y, w, h;
		x = 3.5;
		y = 2.5;
		h = 1.2;
		w = 1.7;

		easy_start(button(GenUIID(0), x-2, y, w, h, label3[0]));
        draw_bmp("./picture/easy.bmp",x-2,y+3.8,w,h);  //���ϽǶ�λ
		mid_start(button(GenUIID(0), x + 0.8, y, w, h, label3[1]));
		draw_bmp("./picture/normal.bmp",x+0.8,y+3.8,w,h);  
		hard_start(button(GenUIID(0), x + 3.6, y, w, h, label3[2]));
		draw_bmp("./picture/hard.bmp",x+3.6,y+3.8,w,h);  
		define_start(button(GenUIID(0), x + 6.4, y, w, h, label3[3]));
		draw_bmp("./picture/selfdefine.bmp",x+6.4,y+3.8,w,h);  
		back_button2(button(GenUIID(0), x + 9.2, y, w, h, label3[4]));
		draw_bmp("./picture/backlastpage.bmp",x+9.2,y+3.8,w,h);  
	}
	//��Ϸ��ʼ
	if (page == 4) {
		//����ǳ�ʼ������ˢ��
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}

		char* label3[] = {
		"���·��",
		"ȫ��·��",
		"����    Ctrl-S",
		"������һҳ",
		"�༭��ͼ"
		};
		//���ð�ťλ�ü����С
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //���ϽǶ�λ
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //���ϽǶ�λ
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //���ϽǶ�λ
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //���ϽǶ�λ
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);
		if (IsSucceed == 1) {
			//������Ϸʤ����ǩ�Լ���Ӧ����

					char* label[] = {
						"",
						"",
						""
				//"�������˵�",
				//"������һҳ",
				//"����һ��"
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

		//���Ƶ�ͼ
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//��������
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
	//��ʾ·��ģʽ
	if (page == 5) {
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}
		char* label3[] = {
		"��һ·��",
		"������Ϸ"
		};

		label3[0] = All_route->head == NULL ? "��ȫ����ʾ" : "��һ·��";
		//���ð�ťλ�ü����С
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
	//�༭��ͼģʽ
	if (page == 6) {
		ClearScreen(0, 0, 16, 10);
		Draw_Maze(MAZE, row, col);
		char* label3[] = {
		"�鿴����",
		"�˳��༭"
		};

		//���ð�ťλ�ü����С
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
		draw_bmp("./picture/teachpage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* label3[] = {
		"����˵��",
		"�������",
		"��������",
		"�������˵�"
		};

		//���ð�ťλ�ü����С
		double x, y, w, h;
		x =3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		ruleexplain_button(button(GenUIID(0), x -2, y, w, h, label3[0]));
		draw_bmp("./picture/ruleexplain.bmp",x -2,y+3.2,w,h);  //���ϽǶ�λ
        operate_button(button(GenUIID(0), x+1.5, y , w, h, label3[1]));
		draw_bmp("./picture/operate.bmp",x +1.5,y+3.2,w,h);
        about_button(button(GenUIID(0), x+5.0, y , w, h, label3[2]));
		draw_bmp("./picture/about.bmp",x +5,y+3.2,w,h);
        back_button6(button(GenUIID(0), x+8.5, y, w, h, label3[3]));
        draw_bmp("./picture/backmainpage.bmp",x +8.5,y+3.2,w,h);
	}
	if (page == 14) {

		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* label3[] = {
		"����ģʽ",
		"����ģʽ",
		"��սģʽ",
		"�������˵�"
		};

		//���ð�ťλ�ü����С
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
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* label3[] = {
		"�����ͼ",
		"�༭�հ׵�ͼ",
		"ģʽ����",
		"������һҳ"
		};

		//���ð�ťλ�ü����С
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
		draw_bmp("./picture/passthroughmodeground.bmp",0,0,16,10);  //���ϽǶ�λ
		char* label3[] = {
		"��ʼ��Ϸ",
		"ģʽ����",
		"������һҳ"
		};

		//���ð�ťλ�ü����С
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
		//����ǳ�ʼ������ˢ��
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}
		char* label3[] = {
		"���·��",
		"ȫ��·��",
		"����    Ctrl-S",
		"������һҳ",
		"�༭��ͼ"
		};
		//���ð�ťλ�ü����С
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //���ϽǶ�λ
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //���ϽǶ�λ
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //���ϽǶ�λ
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //���ϽǶ�λ
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);

		if (IsSucceed == 1) {
			//������Ϸʤ����ǩ�Լ���Ӧ����

					char* label[] = {
						"",
						"",
						""
				//"�������˵�",
				//"������һҳ",
				//"����һ��"
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

		//���Ƶ�ͼ
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//��������
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
	if (page == 18) {

		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* label3[] = {
		"ȷ��",
		"������һҳ"
		};
       	static char lable1[80]=""; 
       	static char lable2[80]=""; 
		//���ð�ťλ�ü����С
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
//��Ϸ��ʼ
	if (page == 19) {
		//����ǳ�ʼ������ˢ��
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}

			char* label3[] = {
		"���·��",
		"ȫ��·��",
		"����    Ctrl-S",
		"������һҳ",
		"�༭��ͼ"
		};
		//���ð�ťλ�ü����С
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //���ϽǶ�λ
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //���ϽǶ�λ
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //���ϽǶ�λ
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //���ϽǶ�λ
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);
		if (IsSucceed == 1) {
			//������Ϸʤ����ǩ�Լ���Ӧ����

					char* label[] = {
						"",
						"",
						"",
						""
				//"�������˵�",
				//"������һҳ",
				//"����һ��"
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


		//���Ƶ�ͼ
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//��������
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
	if (page == 20) {

	
		ClearScreen(0, 0, 16, 10);
		draw_bmp("./picture/modepage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* label3[] = {
		"ȷ��",
		"������һҳ"
		};
       	static char lable1[80]=""; 
       	static char lable2[80]=""; 
		//���ð�ťλ�ü����С
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

	//����ģʽ	
if (page == 21) {
		//����ǳ�ʼ������ˢ��
		if (MazeChanged == 1) {
			ClearScreen(0, 0, 16, 10);
		}

		
		char* label3[] = {
		"���·��",
		"ȫ��·��",
		"����    Ctrl-S",
		"������һҳ",
		"�༭��ͼ"
		};
		//���ð�ťλ�ü����С
		double x, y, w, h,t;
		x = 1.0;
		y = 9.0;
		h = 0.8;
		w = 1.44;
		t =8.8;
       

		short_button(button(GenUIID(0), x-0.5, y , w, h, label3[0]));
        draw_bmp("./picture/shortestroute.bmp",x-0.5,y-t,w,h);  //���ϽǶ�λ
		all_button(button(GenUIID(0), x+1.2, y , w, h, label3[1]));
		draw_bmp("./picture/allroute.bmp",x+1.2,y-t,w,h);  //���ϽǶ�λ
		save_button(button(GenUIID(0), x+10.5, y , w, h, label3[2]));
		draw_bmp("./picture/savegame.bmp",x+10.5,y-t,w,h);  //���ϽǶ�λ
		back_button3(button(GenUIID(0), x+12.2, y , w, h, label3[3]));
		draw_bmp("./picture/gamebacklastpage.bmp",x+12.2,y-t,w,h);  //���ϽǶ�λ
		edit_button(button(GenUIID(0), x+2.9, y , w, h, label3[4]));
		draw_bmp("./picture/editmap.bmp",x+2.9,y-t,w,h);

		if (IsSucceed == 1) {
			//������Ϸʤ����ǩ�Լ���Ӧ����

					char* label[] = {
						"",
						"",
						"",
						""
				//"�������˵�",
				//"������һҳ",
				//"����һ��"
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



		//���Ƶ�ͼ
		if (MazeChanged == 1) {
			Draw_Maze(MAZE, row, col);
			MazeChanged = 0;
		}
		//��������
		Draw_Robot(current_x, current_y, row, col);
		Draw_Destination(end_x, end_y, row, col);
	}
}


//page1
void drawpage1(){
		ClearScreen(0, 0, 16, 10);
    	draw_bmp("./picture/mainpage.bmp",0,0,16,10);  //���ϽǶ�λ
		char* page1[] = {
		"��ʼ����Ϸ",
		"������Ϸ",
		"��Ϸ�̳�",
		"�˳���Ϸ    Ctrl-E"
		};
		//���ð�ťλ�ü����С
		double x, y, w, h;
		x = 3.5;
		y = 2.5;
		h = 1.8;
		w = 2.5;

		start_button(button(GenUIID(0), x-2, y, w, h, page1[0]));//����Ϸ
        draw_bmp("./picture/startgame.bmp",x-2,y+3.2,w,h);  //���ϽǶ�λ
		continue_button(button(GenUIID(0), x + 1.5, y, w, h, page1[1]));//������Ϸ
        draw_bmp("./picture/continuegame.bmp",x+1.5,y+3.2,w,h);  //���ϽǶ�λ
        gameteach_button(button(GenUIID(0), x + 5.0, y, w, h, page1[2]));//��Ϸ����
        draw_bmp("./picture/gameteach.bmp",x+5.0,y+3.2,w,h);  //���ϽǶ�λ
		exit_button(button(GenUIID(0), x + 8.5, y, w, h, page1[3]));
	    draw_bmp("./picture/exitgame.bmp",x+8.5,y+3.2,w,h);  //���ϽǶ�λ
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

		//�����ϴε�ͼ����ȡ�ߴ���Ϣ
		MAZE = read_maze_map(&row, &col,&current_x, &current_y, &GameTime, &mode, &difficulty,&mode2_guan);

		//������Ϸ����
		start_x = 0, start_y = 0;
		end_x = row - 1, end_y = col - 1;
		//��Ϸ��ʼ
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
		//�رճ���
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
			//��ͣ��ʱ��
			//���·��
			int count = 0;
			DFS(MAZE, row, col, current_x, current_y, end_x, end_y, current_x, current_y, count);
			//������ʾģʽ
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
		//�����ͼ
		saving=1;
		save_maze_map(MAZE, row, col, current_x, current_y, GameTime, mode, difficulty,mode2_guan);
		//����������Ϣ
		page = 4;
	}
}

void back_button3(int a) {
	if (a == 1) {
		
			GameOn = 0;
			Refresh();
			ClearScreen(0, 0, 16, 10);
			//�����������
			page = 15;
			mode = 0;//0:��ͨ·��1:��ͨ·
			difficulty = 1;//�Ѷȿ���
			IsSucceed = 0;
			RoutineDisplay = 0;//��ʾ����·��ģʽ
			IsEditing = 0;//�Ƿ��ڱ༭ģʽ
			MazeChanged = 1;//�Թ��Ƿ�ı�
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
		mode = 0;//0:��ͨ·��1:��ͨ·
		difficulty = 1;//�Ѷȿ���
		IsSucceed = 0;
		RoutineDisplay = 0;//��ʾ����·��ģʽ
		IsEditing = 0;//�Ƿ��ڱ༭ģʽ
		MazeChanged = 1;//�Թ��Ƿ�ı�
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
		mode = 0;//0:��ͨ·��1:��ͨ·
		difficulty = 1;//�Ѷȿ���
		IsSucceed = 0;
		RoutineDisplay = 0;//��ʾ����·��ģʽ
		IsEditing = 0;//�Ƿ��ڱ༭ģʽ
		MazeChanged = 1;//�Թ��Ƿ�ı�
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
		RoutineDisplay = 0;//��ʾ����·��ģʽ
		IsEditing = 0;//�Ƿ��ڱ༭ģʽ
		MazeChanged = 1;//�Թ��Ƿ�ı�
		//���¿�ʼ
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
	//��������
	if (a == 1) {
		MessageBox(
			window,
			TEXT("ʹ�����ѡ��Ԫ��,��wasd���ɻ�������ͼ�е�ǽ"),
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
	//��������
	if (a == 1) {
		MessageBox(
			window,
			TEXT("����˵�����߳��Թ���Ϊʤ������������ģʽΪһ�ŵ�ͼ����ͼ��ѡ�����д�����������ɡ�����ģʽ���޹ؿ���"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}

		void  operate_button(int a) {
	//��������
	if (a == 1) {
		MessageBox(
			window,
			TEXT("������ٿ�С�˽���ǰ�����ҵ��ƶ����ڱ༭��ͼ��ģʽ����ʹ�����ѡ���wasd���������ɻ���ȡ��ǽ�Ĳ���"),
			TEXT(""),
			MB_OK);
		Refresh();
		ClearScreen(0, 0, 16, 10);
		MazeChanged = 1;
	}
}
     
	 		void about_button(int a) {
	//��������
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
			TEXT("�����У������ڴ�"),
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
			TEXT("����ģʽΪһ�ŵ�ͼ����ͼ��ѡ�����д�����������ɡ������Զ����ͼ��С�����ɿհ׵�ͼ���ڱ༭��ͼ��ģʽ����ʹ�����ѡ��+wasd���������ɻ���ȡ��ǽ�Ĳ�����"),
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
			TEXT("����ģʽ���޹ؿ����Ѷȵ���"),
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
			//�����������
			page = 16;
			mode = 0;//0:��ͨ·��1:��ͨ·
			difficulty = 1;//�Ѷȿ���
			IsSucceed = 0;
			RoutineDisplay = 0;//��ʾ����·��ģʽ
			IsEditing = 0;//�Ƿ��ڱ༭ģʽ
			MazeChanged = 1;//�Թ��Ƿ�ı�
		}
}
void success_back_button21(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);

		GameOn = 0;
		//�����������
		page = 1;
		mode = 2;//0:��ͨ·��1:��ͨ·
		difficulty = 1;//�Ѷȿ���
		IsSucceed = 0;
		RoutineDisplay = 0;//��ʾ����·��ģʽ
		IsEditing = 0;//�Ƿ��ڱ༭ģʽ
		MazeChanged = 1;//�Թ��Ƿ�ı�
	}
}

void success_backlastpage_button21(int a) {
	if (a == 1) {
		Refresh();
		ClearScreen(0, 0, 16, 10);
		GameOn = 0;
		//�����������
		page = 16;
		mode = 2;//0:��ͨ·��1:��ͨ·
		difficulty = 1;//�Ѷȿ���
		IsSucceed = 0;
		RoutineDisplay = 0;//��ʾ����·��ģʽ
		IsEditing = 0;//�Ƿ��ڱ༭ģʽ
		MazeChanged = 1;//�Թ��Ƿ�ı�
	}
}


/*
 * �ú������Թ�����Ϣ���浽�ļ��С�
 * 
 * ������
 * arr���Թ��Ķ�ά����
 * row���Թ�������
 * col���Թ�������
 * ����ֵ����
 */
void save_maze_map(struct posi_info** pointer, int row, int col,int cx, int cy, double time, int mode, int difficulty,int mode2_guan) {
	    saving =0;
		FILE *fp = fopen("./map/maze_map.m", "wb");
		if (fp == NULL){
		printf("Error opening!\n");
		exit(1);
		}

		// д���Թ�������������
		fwrite(&row, sizeof(int), 1, fp);
		fwrite(&col, sizeof(int), 1, fp);

		// д���Թ���ÿ��λ�õ���Ϣ
		int i = 0;
		for (i = 0; i < row; i++) {
		fwrite(pointer[i], sizeof(struct posi_info), col, fp);
		}
		fwrite(&cx, sizeof(int), 1, fp);//д�뵱ǰ��ҵ�λ�õĺ�����
		fwrite(&cy, sizeof(int), 1, fp);//д�뵱ǰ��ҵ�λ�õ�������
		fwrite(&time, sizeof(double), 1, fp);//д����Ϸ��ʱ
		fwrite(&mode, sizeof(int), 1, fp);//д����Ϸģʽ
		fwrite(&difficulty, sizeof(int), 1, fp);//д����Ϸ�Ѷ�
		fwrite(&mode2_guan, sizeof(int), 1, fp);//д����Ϸģʽ2�Ĺؿ�

		// �ر��ļ�
		fclose(fp);
}





/*
 * �ú������ļ��ж�ȡ�Թ�����Ϣ��������һ��ָ���Թ���ά�����ָ�롣
 * 
 * ������
 * row��ָ�����ͱ�����ָ�룬���ڴ洢�Թ�������
 * col��ָ�����ͱ�����ָ�룬���ڴ洢�Թ�������
 * 
 * ����ֵ��
 * �ú�������һ��ָ���Թ���ά�����ָ�룬������洢���Թ���ÿ��λ�õ���Ϣ��
 * 
 * ע�⣺
 * �ú����ᶯ̬�����ڴ棬��������Ҫ�����ͷŸ��ڴ档
 */
struct posi_info** read_maze_map(int* row, int* col,int* cx, int* cy, double* time, int* mode, int* difficulty,int* mode2_guan){

		
		FILE *fp = fopen("./map/maze_map.m", "rb");
	if (fp == NULL) { // ����ļ������ڣ��򷵻�NULL
		printf("Error opening!\n");
		exit(1);
	}

	// ��ȡ�Թ�������������
	fread(row, sizeof(int), 1, fp);
	fread(col, sizeof(int), 1, fp);

	// ��̬�����ڴ�
	int i = 0, j = 0, k = 0; 
	struct posi_info** pointer = (struct posi_info**)malloc((*row) * sizeof(struct posi_info*));//������
	for (i = 0; i < *row; i++) {
		pointer[i] = (struct posi_info*)malloc((*col) * sizeof(struct posi_info));//������
	}

	// ��ȡ�Թ���ÿ��λ�õ���Ϣ
	for (i = 0; i < *row; i++) {
		fread(pointer[i], sizeof(struct posi_info), (*col), fp);
	}
	
	fread(cx, sizeof(int), 1, fp);
	fread(cy, sizeof(int), 1, fp);
	fread(time, sizeof(double), 1, fp);
	fread(mode, sizeof(int), 1, fp);
	fread(difficulty, sizeof(int), 1, fp);
	fread(mode2_guan, sizeof(int), 1, fp);
	// �ر��ļ�
	fclose(fp);

	// ����ָ���Թ���ά�����ָ��
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
				// ��ȡ��ǰ���ڵľ��
			HWND hwnd = GetForegroundWindow();
			// ǿ��ˢ�µ�ǰ����
			UpdateWindow(hwnd);

}