// Room: /u/l/lestia/area/sn11.c

inherit ROOM;

void create()
{
	set("short", "北方大森林");
	set("long", @LONG
一片片樹葉在你頭上飛舞著，些許的陽光藉著葉與葉中的縫隙穿射過來
，使得地上黑色的樹蔭浮現著點點光粒，靈幻宗便是隱藏於這片廣大的森林
之中，許多有心學習幻術的人們，都嚮往拜入靈幻宗。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn10",
  "south" : __DIR__"sn12",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
