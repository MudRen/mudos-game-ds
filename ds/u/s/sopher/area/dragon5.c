#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIC"清涼走道"NOR);
        set ("long", @LONG
來到這，你被一陣花香所迷。啊~好香的花啊！你
情不自禁的靠近芬芳散發處...東邊似乎有座花園的樣
子？
LONG);
        
        set("exits", ([
        "west" : __DIR__"dragon2",
        "east" : __DIR__"flower_road1",
         ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}    
