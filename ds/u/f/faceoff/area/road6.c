#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"小路"NOR);
set("long",@LONG
從這裡再往東北走就到十萬大山的山口了, 從你這裡已經
可以看到十萬大山的山脈了, 雖然十萬大山曾因為龍井棧到而
名聲大噪, 不過現在也只剩一些農夫在那裡了....
LONG
    );
 set("exits",([ "northeast":__DIR__"road7",
		"southwest":__DIR__"road5",
]));
 set("objects", ([__DIR__"npc/mountain_cat": 4,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
