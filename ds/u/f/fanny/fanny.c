// Room: /u/f/fanny/workroom.c

inherit ROOM;

void create()
{
	set("short", "笑紅塵的窩");
	set("long", @LONG
這是笑紅塵工作的地方，這裡有一把紅塵劍，跟許多陳年老酒
這來笑紅塵是個酒鬼吧，在笑紅塵的口裡還聲聲唸著他的「笑紅塵」
這首曲子，似乎還挺能自得其樂的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "wiz" : "/d/wiz/hall1",
]));
	set("world", "undefine");
    set("no_clean_up", 1);

	setup();
	replace_program(ROOM);
}
