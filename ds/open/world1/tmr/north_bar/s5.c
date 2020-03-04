// Room: /open/world1/tmr/north_bar/s5.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
這裡突然跑出數隻野獸，開始發瘋似的亂攻擊你！讓你反應
不太過來，加上地上的泥沼地，讓你的行動更加的不方辯了，不
知道是否還能出的去••
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"s2",
  "east" : __DIR__"s10",
  "north" : __DIR__"s6",
  "west" : __DIR__"s9",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
