// Room: /u/t/tmr/area/lake-road3.c
#include <path.h>

#include <room.h>
inherit DOOR;
inherit ROOM;

void create()
{
	set("short", "竹林小徑");
	set("long", @LONG
一條竹林間的小徑，四周除了翠綠挺拔的觀音竹，眼前有間草屋，周
圍編竹為籬，籬上交纏薔薇、木香、刺梅、木楓、金雀；籬邊遍下蜀葵、
鳳仙、雞冠、秋葵....等數種，不可枚舉。往東南穿過雜草，有條山道。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"woodhouse",
   "southeast":ACME_PAST"bonze/b1",
  "northwest" : __DIR__"lake-road2",
]));
       create_door("enter", "柴門", "out", DOOR_CLOSED);
	set("item_desc", ([ /* sizeof() == 1 */
//  "enter" : (: look_door,     "enter" :),
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	set("no_map",1);
	setup();
//    replace_program(ROOM);
}
