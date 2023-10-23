#include "../head/callback.h"
#include "../head/draw_map.h"
#pragma comment (lib, "winmm.lib")

int selected_x = 0;//ѡ�еĸ��ӵ�����
int selected_y = 0;
int GameOn = 0;



void redraw_gamepage(){
		ClearScreen(0, 0, 16, 10);    //����
		draw_page(page);             //����ҳ��
		Draw_Maze(MAZE, row, col);   //�����Թ�
		Draw_Robot(current_x, current_y, row, col); //��������
		Draw_Destination(end_x, end_y, row, col);  //�����յ�
}

enum key{ LEFT=37,UP=38,RIGHT=39,DOWN=40,A=65,D=68,W=87,S=83}key;


void KeyboardEventProcess(int key, int event) {
	uiGetKeyboard(key, event);//ui�⴦������¼�
	switch (event)
	{
	case KEY_DOWN:
	if (GameOn){
//��Ϸ�����У��ƶ�
		//��37���ϣ�38���ң�39���£�40
		switch (key)
		{
		case LEFT:	if (current_y != 0 && MAZE[current_x][current_y].pass_direction[0] == 1) {//�ж��Ƿ����ƶ���current_y�߽��жϣ�MAZE[current_x][current_y].dirction[0]�ж��Ƿ���ǽ
					current_y -= 1;
					redraw_gamepage();
			}
			break;
		case RIGHT:	if (current_y != col - 1 && MAZE[current_x][current_y].pass_direction[1] == 1) {
					current_y += 1;
					redraw_gamepage();
			}
		break;	
		case UP:	if (current_x != 0 && MAZE[current_x][current_y].pass_direction[2] == 1) {
					current_x -= 1;
					redraw_gamepage();
		}
		break;
		case DOWN:	if (current_x != row - 1 && MAZE[current_x][current_y].pass_direction[3] == 1) {
					current_x += 1;
					redraw_gamepage();
		}
			break;
		
		default:
			break;
		}
		if(key == 78){
			struct LinkStack* temp = BFS_Search(MAZE, row, col, current_x, current_y, end_x, end_y);
		//�ų�·�������㣨��ǰ�㣩
		Pop_LinkStack(temp);
		//��ȡ��һ��
		int i = 0;
		struct posi_info ans;
			ans = Pop_LinkStack(temp);
			double newx = curzsjx(ans.column, row, col);
			double newy = curzsjy(ans.row, row, col);

			double curx = curzsjx(current_y, row, col);
			double cury = curzsjy(current_x, row, col);

			//Draw_Rectangle(newx, newy);
			//Draw_Rectangle(curx, cury);
			double nextx=newx, nexty=newy;
		if (curx == nextx) {
			if (cury < nexty) {
				//����
				draw_bmp("./picture/down.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
			else {
				//����
				draw_bmp("./picture/up.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
		}
		else {
			if (curx > nextx) {
				//����
				draw_bmp("./picture/left.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
			else {
				//����
				draw_bmp("./picture/right.bmp", curx+ Boxlength / 7, 10-cury+Boxlength/7, Boxlength* 0.75, Boxwidth* 0.75);
			}
		}
		}
		//��Ϸʤ����Ҫ����
			if (current_x == end_x && current_y == end_y) {
				//��ʾ��Ϸ�������ṩ�°�ť
				IsSucceed = 1;
				if(mode==1){

					char* label[] = {
				"",
				"",
				"",
				""
			};
			double sx = 14;
			double sy = 6;
			double h = 0.8;
			double w = 1.44;
			double st =1.7;
			success_back_button(button(GenUIID(0), sx, sy, w, h, label[0]));
 			draw_bmp("./picture/gamebackmainpage.bmp",sx,sy+st-4.5,w,h); 	
			success_backlastpage_button(button(GenUIID(0), sx, sy - 1.25, w, h, label[1]));
			draw_bmp("./picture/gamebacklastpage.bmp",sx,sy+st-3.25,w,h);
			success_restart_button(button(GenUIID(0), sx, sy - 2.5, w, h, label[2]));
			draw_bmp("./picture/anothergame.bmp",sx,sy+st-2,w,h);
				}
			if(mode==2){

					char* label[] = {
				"",
				"",
				"",
				""
			};
			double sx = 14;
			double sy = 6;
			double h = 0.8;
			double w = 1.44;
			double st =1.7;
			success_back_button(button(GenUIID(0), sx, sy, w, h, label[0]));
 			draw_bmp("./picture/gamebackmainpage.bmp",sx,sy+st-4.5,w,h); 	
			success_backlastpage_button(button(GenUIID(0), sx, sy - 1.25, w, h, label[1]));
			draw_bmp("./picture/gamebacklastpage.bmp",sx,sy+st-3.25,w,h);
			success_nextguan_button(button(GenUIID(0), sx, sy - 2.5, w, h, label[2]));
			draw_bmp("./picture/nextguan.bmp",sx,sy+st-2,w,h);
				}
		}
	}

		//��ͼ�༭ģʽ
		if (IsEditing ) {
			switch (key)
			{
			case A:		if (selected_y != 0) {
						MAZE[selected_x][selected_y].pass_direction[0] = 1-MAZE[selected_x][selected_y].pass_direction[0]  ;//�޸ĵ�ǰ���ӵ����
						MAZE[selected_x][selected_y - 1].pass_direction[1] = 1-MAZE[selected_x][selected_y - 1].pass_direction[1] ;//�޸���߸��ӵ��ұ�
						redraw_gamepage();
					}
			break;
			case D:					if (selected_y != col-1) {
						MAZE[selected_x][selected_y].pass_direction[1] = 1-MAZE[selected_x][selected_y].pass_direction[1];//�޸ĵ�ǰ���ӵ����
						MAZE[selected_x][selected_y + 1].pass_direction[0] = 1-MAZE[selected_x][selected_y + 1].pass_direction[0] ;//�޸���߸��ӵ��ұ�
						redraw_gamepage();
					}
			break;
			case W:		if (selected_x != 0) {
						MAZE[selected_x][selected_y].pass_direction[2] = 1-MAZE[selected_x][selected_y].pass_direction[2] ;
						MAZE[selected_x - 1][selected_y].pass_direction[3] = 1-MAZE[selected_x - 1][selected_y].pass_direction[3] ;
						redraw_gamepage();
					}
			break;
			case S:					if (selected_x != 0) {
						MAZE[selected_x][selected_y].pass_direction[3] = 1-MAZE[selected_x][selected_y].pass_direction[3] ;
						MAZE[selected_x + 1][selected_y].pass_direction[2] = MAZE[selected_x + 1][selected_y].pass_direction[2] ;
						redraw_gamepage();
					}
			break;
			default:
				break;
			}
		
		}
		break;
	default:
		break;
	}
}


void MouseEventProcess(int x, int y, int button, int event) {
	uiGetMouse(x, y, button, event);//��ȡ�����Ϣ
	if(saving!=1)draw_page(page);
    if (IsEditing ) {
		Draw_Robot(current_x, current_y, row, col); 
		Draw_Destination(end_x, end_y, row, col);  
		//���ڱ༭ģʽ�µ������
		if(event == BUTTON_DOWN){
			double zsx=zsjx(row,col);
			double zsy=zsjy(row,col);
			selected_y = (ScaleXInches(x)*1.0-zsx)/Boxwidth;
			selected_x = (10.0-zsy-ScaleYInches(y)*1.0)/Boxlength; 
			printf("x:%lf y:%lf\n", selected_x, selected_y);
			printf("zsx:%lf zsy:%lf\n", zsx, zsy);
			printf("selected_x:%d selected_y:%d\n", selected_x, selected_y);
			if(selected_x>=0&&selected_x<row&&selected_y>=0&&selected_y<col){
				redraw_gamepage();
				draw_selected(selected_x, selected_y, row, col);    
			}
		}

	}

}

void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	if(page==19|| page==20){
	DisplayClear();
	draw_page(page);
	DisplayClear();
	draw_page(page);
	}
}



int GameTime = 0;

