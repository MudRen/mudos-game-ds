#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","千年古洞－洞內");
 set("long",@LONG 
走在這裡，十分的安靜，你看到旁邊一棵棵的鐘乳石和地上
的石筍，讓人知道這個古洞已經有上千年的歷史了。但是這裡卻
沒有幾個人來過，但是周圍的景象讓你覺得到沒有什麼邪氣存在
著。
LONG
    );

       set("exits",([
       "north":__DIR__"entrance",
       "southeast":__DIR__"f3",
       "southwest":__DIR__"f2",
           ]));
        set("objects", ([
           ]));
 set("no_clean_up", 0);
 setup();
}     

