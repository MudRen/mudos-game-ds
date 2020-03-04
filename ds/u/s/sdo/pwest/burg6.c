inherit ROOM;

void create()
{
	set("short", "村子東邊小路");
	set("long", @LONG
走在村莊東邊的外圍小路上，你才發現，原來村莊是建築在這一
大片連綿不絕的樹林裡的一塊小空地上。而沿著小路望過去，盡頭又
是消失在樹林之中。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  		"east" : __DIR__"burg7",
  		"west" : __DIR__"burg1",
	]));

	setup();
	replace_program(ROOM);
}
