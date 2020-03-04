// updated 26/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST。Road＠North"NOR);
	set("long", @LONG
這裡又是一個十字路口，向東是一間防具售賣店，而向西是一間回收
屋。而北面是通往政府大樓的道路，往南便是你來的市中心。這附近的風
景很普通，沒有什麼特別之處。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shop1.c",
  "south" : __DIR__"dst8.c",
  "north" : __DIR__"dst10.c",
  "east" : __DIR__"shop3",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
