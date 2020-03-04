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
 set("objects", ([__DIR__"npc/birdguard" : 2+random(3),
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}

