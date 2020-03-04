#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","滅骨峰");

 set("long",@LONG
這裡就是十萬大山中的次高峰 -- 滅骨峰了! 之所以會如此
稱呼是因為百年前義薄雲天的大俠, 胡育慘死在這, 你不禁為這
位大俠哀悼, 這裡往東是一條小路, 往西是通往最高峰奇倪峰, 
往北則通往十萬大山深處.
LONG
    );
 set("exits",([ "south":__DIR__"ten1",
	        "north":__DIR__"ten20",
		"east":__DIR__"ten3",

        "westup":__DIR__"ten9",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
