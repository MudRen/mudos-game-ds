// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠East[2;37;0m");
	set("long", @LONG
人群在這裡左擠右湧，你差一點就被迫走出去。原來這裡北面的那間
就是馳名的蛋糕店，每天都有一群人來這裡買他們的蛋糕，而且這裡的附
近是一個機械動物園，所以這蛋糕店的客人愈來愈多。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dst11.c",
  "north" : __DIR__"cakeshop",
  "east" : __DIR__"dst13.c",
]));
set("objects",([
__DIR__"npc/soser" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
