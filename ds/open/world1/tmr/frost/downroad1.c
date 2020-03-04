// Room: /open/world1/tmr/freezetaoism/downroad1.c

inherit ROOM;

void create()
{
	set("short", "地下祕道");
	set("long", @LONG
你正在一條地下祕道裡，其通道不寬，約可容納一個人擠著身子通過
，四周靜得連一根針掉在地上都能聽的一清二楚。
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"downroad2",
  "up" : __DIR__"temple7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
