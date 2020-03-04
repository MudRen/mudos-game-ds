inherit ROOM;

void create()
{
	set("short", "森林外圍");
	set("long", @LONG
你看見北邊不遠處有著幾間房屋，看來已經到森林的邊緣了。不
過你看著身邊無數的樹影，不禁對這片廣大的樹林咋舌。不知道這片
綿延無盡的樹林究竟是如何長成的。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"burg1",
  "south" : __DIR__"path4",
]));

	setup();
	replace_program(ROOM);
}
