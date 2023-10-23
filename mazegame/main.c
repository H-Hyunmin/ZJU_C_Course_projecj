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

#include "./head/test.h"
#include "./libgraphics/graphics.h"
#include "./libgraphics/extgraph.h"
#include "./libgraphics/genlib.h"
#include "./libgraphics/simpio.h"
#include "./libgraphics/strlib.h"
#include "./libgraphics/linkedlist.h"
#include "./libgraphics/imgui.h"
#include "./libgraphics/boolean.h"
#include "./libgraphics/gcalloc.h"
#include "./libgraphics/random.h"
#include "./head/draw_gui.h"
#include "./head/callback.h"


void Main()
{
    
    //设置窗口大小 
    SetWindowSize(WindowWidth, WindowHeight);
    
    
    //设置窗口标题 
    SetWindowTitle("MAZE GAME");
    InitGraphics();
    //InitConsole();
    //HWND hwnd = GetDesktopWindow(); // 获取桌面窗口句柄作为定时器消息的接收者

    registerKeyboardEvent(KeyboardEventProcess);
    registerMouseEvent(MouseEventProcess);
    registerCharEvent(CharEventProcess);


}