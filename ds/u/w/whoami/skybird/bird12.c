#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"石亭"NOR);

 set("long",@LONG
當天梟遇到教務上或武功上的難題時，便會在此展開會議， 
像你的眼前就有幾個天梟弟子正在討論一件難題，你可以趨前聽
看看他們在討論什麼問題，不過你一定要措詞適當，天梟可不喜
歡有人旁觀他們•
LONG
    );
 set("exits",([ "southeast":__DIR__"bird10",
    ]));
 set("objects", ([__DIR__"npc/chiang_chin_liu" : 1,
                  __DIR__"npc/bird_apprentice" : 3+random(2),
    ]));
set("light",1); 
set("outdoors",1);
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}

