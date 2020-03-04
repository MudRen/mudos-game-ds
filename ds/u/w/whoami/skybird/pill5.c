#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"大廳"NOR);
 set("long",@LONG
這裡是天梟冶藥一派的大廳, 通常要討論教務, 或掌門要接待
客人, 都是在此實施, 你發現這裡並沒有繁華的裝飾, 牆壁是用簡
單的木板搭成, 有一種滄桑的感覺.
LONG);
 set("exits",([ "southeast":__DIR__"pill6",
                "west":__DIR__"pill3",
    ]));
set("objects", ([__DIR__"npc/master" : 1,
                __DIR__"npc/birdguard" : 1+random(2),
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("master",environment(me)) && 
     ( (dir=="southeast") ))
       {
        message_vision(YEL"趙長孫對$N微微一笑，說道：這位" + RANK_D->query_respect(me) + "請留步，再過去就是內人休憩的房間了。\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

