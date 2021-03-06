// Room: /open/world1/tmr/frost/temple1e.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-通道");
	set("long", @LONG
你正走在道觀內的通道，觀內的環境清幽而安詳，過往的道人也是一
副與世無爭的安樂貌。空氣中瀰漫著一股檀香味，淡淡然的並不刺鼻。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"temple1e2",
  "west" : __DIR__"temple1",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
