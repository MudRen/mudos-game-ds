#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"庭院"NOR);
 set("long",@LONG
這裡雖然也是庭院，但時卻沒什麼花草，只右一片雜草
和一堆藤蔓，把前方的光線全都擋住了，不知道前方是什麼
東西，不禁讓你十分好奇。

LONG
    );

       set("exits",([
       "south":__DIR__"town23",
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

