#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"天梟後院"NOR);

 set("long",@LONG
這裡再向北走就是負有聖名的天梟聖泉, 往東北則是參天古
木, 你可以看見西方是處理天梟弟子生活的宿舍和廚房, 這裡其
實是連結更多地方的後院, 你發現這裡真是名副其實的[ 三步一
崗, 五步一哨. ]
LONG);
 set("exits",([ "northeast":__DIR__"tree1.c",
                "west":__DIR__"bird7.c",
                "north":__DIR__"water.c",
                "south":__DIR__"bird5.c", 
    ]));
 set("objects", ([
       __DIR__"npc/birdguard" : 2+random(3),
       __DIR__"npc/guard_captain" : 1,
                ]));
set("no_clean_up",0);
set("light",1);
 setup();
}

int valid_leave(object me, string dir)
{
   me = this_player();
    if (present("guard",environment(me)) &&  ( (dir=="north") ))
       {
        message_vision("天梟守衛伸手擋住了往北的通路•\n",me);
        message_vision(YEL"天梟守衛說﹕這裡不是$N能進去的地方，還是快回去吧\n"NOR,me);
       } 
    if (present("lee",environment(me)) &&  ( (dir=="north") ))
       {
        message_vision("李鎮遠伸手擋住了往北的通路•\n",me);
        message_vision(YEL"李鎮遠說﹕這裡不是$N能進去的地方，還是快回去吧\n"NOR,me);
       }
    if (present("captain",environment(me)) &&  ( (dir=="north") ))
       {
        message_vision("小隊長伸手擋住了往北的通路•\n",me);
        message_vision(YEL"小隊長說﹕滾∼∼！！\n"NOR,me);
       }
    else return ::valid_leave(me,dir);

}

