// Room: /u/s/slency/area/meetroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"幽遮蘭城"HIW"臨時會議室"NOR);
	set("long","這裡是一間頗大的會議廳, 裝潢十分豪華, 看來是巫師開臨時會的場所, \n""圓桌上的"YEL"咖啡"NOR"還在冒煙...。\n");
	set("exits", ([ /* sizeof() == 2 */
  "test" : __DIR__"area/ugelan/farm1",
  "out" : __DIR__"workroom",
]));
	set("no_clean_up", 1);
	set("light",1);
	setup();
	replace_program(ROOM);
}
