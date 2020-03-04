// Room: /open/world1/tmr/north_bar/town9.c

inherit ROOM;

void create()
{
	set("short", "北蠻村-石壁道路");
	set("long", @LONG
這裡吹著強烈的風，讓你覺得開始冷了，加上蕭蕭的風吹聲
，讓人不禁開始緊張起來，不知道是要往回走，還是繼續前進。
小路再往前點有個彎道，入口又更加狹窄，陽光也漸漸照射不到
了，不安的感覺油然而生。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town8",
  "east" : __DIR__"town28",
]));
	set("no_clean_up", 0);
	set("shrot", "北蠻村-石壁道路");
	set("outdoors", "land");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
