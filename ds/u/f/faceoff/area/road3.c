#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小路"NOR);
set("long",@LONG
雖然這一段路程相當荒涼, 但並不代表全東北地區皆是蠻
荒之地, 只不過是這一段路程比較荒涼而已, 再往東北方去的
十萬大山就曾因為龍井棧道而繁榮....
LONG
    );
 set("exits",([ "west":__DIR__"road2",
		"northeast":__DIR__"road4",
]));
 set("objects", ([__DIR__"npc/man" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
