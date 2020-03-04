#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","小徑");

 set("long",@LONG
你向腳下看了一看, 只見這個小徑上的痕跡比剛才的路多了
很多, 可見這裡所走過的人更多, 你似乎在北方遠處看到了一棟
小屋, 而在東方卻似乎有一樣高的出奇的樹木, 你心念一動, 那
該不會就是參天古木吧....?
LONG);
 set("exits",([ "west":__DIR__"tree3",
                 "north":__DIR__"tree7",
                 "northeast":__DIR__"tree9",
    ]));
 set("objects", ([__DIR__"npc/woodguard" : 2+random(3),
    ]));
 set("no_clean_up",0);
 set("outdoors","forest");
 setup();
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("wood guard",environment(me)) && 
     ( (dir=="northeast") ))
       {
        message_vision("天梟護木使用身體擋住了東北向的道路•\n",me);
        message_vision(YEL"天梟護木使說﹕$N想過去？！那就要看你有沒有這個本事了！！\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

