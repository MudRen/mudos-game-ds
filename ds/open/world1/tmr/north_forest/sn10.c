// Room: /open/world1/tmr/north_forest/sn10.c

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
	set("world", "undefine");
        set("objects", ([ 
                __DIR__"npc/troll": 2,
        ]));
	set("no_clean_up", 0);
	set("current_light", 5);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"sn11",
  "west" : __DIR__"sn9w",
  "east" : __DIR__"sn9",
]));

	setup();
	replace_program(ROOM);
}
