// Room: /open/world1/cominging/purple_sun/4fs.c

inherit ROOM;

void create()
{
	set("short", "紫陽山頂-觀景台");
	set("long", @LONG
這裡是紫陽山頂的一處觀景台，雖然空氣有點稀薄，但總是會有
一些遊客到此遊玩。尤其在萬籟俱寂的夜晚，仰頭靜望可看到繁星點
點，可說是月影光如晝，銀霜茫茫，鮮花團錦簇，美景交融。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"4f1",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
