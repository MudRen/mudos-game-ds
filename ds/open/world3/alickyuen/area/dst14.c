// updated 26/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠West[2;37;0m");
	set("long", @LONG
在南面的一個地方，你可以在那裡申請一本臨時通行證，作為不時之
需。而你亦發現了香味又近了一點，看來走這個方向準沒錯的。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"pass",
  "west" : __DIR__"dst15.c",
  "east" : __DIR__"dst7.c",
]));
set("outdoors","land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
