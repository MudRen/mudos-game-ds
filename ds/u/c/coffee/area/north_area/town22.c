#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"北蠻村"NOR"－"HIG"庭院"NOR);
 set("long",@LONG
這裡是村長家門前的庭院，裡面種著許多花，看來村長
還蠻喜歡園藝的。從這裡可以看到村長正在屋裡喝著茶，但
是卻又再嘆息著•••

LONG
    );

       set("exits",([
       "north":__DIR__"town23",        "west":__DIR__"town21", 
           ]));

        set("objects", ([
           ])); 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}     

