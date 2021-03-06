// Room: /open/world1/acme/area/sky/room70.c

inherit ROOM;

void create()
{
	set("short", "【焯焰堂】");
	set("long", @LONG
這兒是天地會的神武教分堂，熱烘烘的感覺不斷地後你心底冒起
來，你看著四周的銅像，不由自主的被其嚴肅的神情所震懾，但不知
怎地，剛才那酷熱的感覺也隨之以散去。你心神一振竟發現前方有一
把紅炎炎的火，相信那就是神武教中的"神武真火"了。
LONG
	);
	set("light", "1");
	set("current_light", 3);
	set("objects", ([ /* sizeof() == 1 */
  "/open/world1/npc/goldman7" : 9,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/world1/manto/sky2_1f/map_7_13.c",
  "south" : __DIR__"room15",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
