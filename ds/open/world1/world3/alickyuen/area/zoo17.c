// Room: /open/world3/alickyuen/area/zoo17.c
//updated by alickyuen 26/12
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", HIC"ST。Secret＠CyberZoo "NOR);
	set("long", @LONG
想不到一個這麼繁榮的動物園後竟然是一間破舊的小屋。看起來那不
像動物園的建築物，似乎是人為的••••••你似乎聽到裡面有些微妙
的聲音。你不禁害怕起來，究竟入面有什麼呢？
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"zoo12",
  "enter" : __DIR__"zoo18",
]));
create_door("enter","大鐵門","out",DOOR_CLOSED);
	set("world", "future");
	set("no_clean_up", 0);
set("outdoors","land");
	setup();
	replace_program(ROOM);
}
