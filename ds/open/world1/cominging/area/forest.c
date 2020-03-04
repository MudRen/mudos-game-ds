#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "森林外端");
	set("long",@LONG
這裡是步靈城南方的大森林的北邊，你似乎可以看見森林中古木參
天，鳥語花香的樣子，聽步靈城中路人所言，在那之中傳說在晚上時，
會有許多不知名的人在閒晃，曾有人被搶劫過，在北方是步靈城外的護
城河，在這的南方是往森林中而去。
LONG
	);
	set("exits", ([
  "southwest" : __DIR__"forest2.c",
  "north" : __DIR__"river.c",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
