#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{


 set("short", HIG"龍井客棧"NOR);
set("long", @LONG
這是唯一一家在龍井棧道崩壞以後還存留的客棧, 在龍
井棧道斷裂以後, 兩旁的客棧因此而全數倒閉, 如今這間客
棧也只是靠著收留十萬大山的遊客維生了....
LONG
        );
 set("exits",([ "east":__DIR__"ten_mountain9", 
    ]));
 set("objects", ([__DIR__"npc/waiter" : 1,
    ]));
set("valid_startroom", 1);
set("no_clean_up",0);
set("no_fight",1);
 set("no_fight", 1);
 set("light",1);
 setup();
 replace_program(ROOM);
}
