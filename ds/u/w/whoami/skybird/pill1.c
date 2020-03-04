#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"大門"NOR);
 set("long",@LONG
這裡是天梟冶藥一派的大門口, 自天梟分裂後尉遲妄和邢獨
風相繼遠走, 只剩天梟冶藥一派尚存於十萬大山群山之中, 冶藥
一派是目前天梟分裂後尚能生存的明證, 再往內走即可進入天梟
, 往西則是十萬大山.
LONG);
 set("exits",([ "enter":__DIR__"pill2",
                "west":__DIR__"ten12",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2+random(2),
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 create_door("enter","小木門","out",DOOR_CLOSED,"nokey");
}

