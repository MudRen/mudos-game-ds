#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIW"格爾維拉街"NOR);
        set ("long", @LONG
離開了迪蘭斯大道，這裡稍顯冷清，你望西邊望去
，有一家服務處，似乎能提供給你不少關於超龍軍團的
資料喔!
LONG);
        
        set("exits", ([
        "west" : __DIR__"dragon6",
        "east" : __DIR__"dragon2",
         ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}    
