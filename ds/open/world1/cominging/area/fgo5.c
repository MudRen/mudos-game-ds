inherit ROOM;

void create()
{
	set("short", "森林中");
	set("long", @LONG
你來到了這個還不算安靜的地方，地上偶爾來幾隻小山豬，緊接也
追來了幾隻不知名的動物，旁邊的樹幹上有許多的螞蟻在勤奮的工作，
而天氣如此的炎熱，讓人不禁佩服其耐力，現在你也有些搞不清東南西
北，也隨便亂走一通。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"fgo6.c",
  "east" : __DIR__"fgo4.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(4),
]));
	setup();
	replace_program(ROOM);
}
