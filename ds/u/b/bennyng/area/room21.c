// Room: /u/b/bennyng/area/room21.c

inherit ROOM;

void create()
{
	set("short", "寶瓶宮");
	set("long", @LONG
這裡便是寶瓶宮的盡頭，這裡的凍氣比其他地方還凍，真不愧是卡妙
，他強大的小宇宙，使你的機能遂漸減低，身體開始僵硬起來，你心想不
早點解決他，必定使你長眠於凍氣之中．
LONG
	);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room22",
  "west" : __DIR__"room20",
]));
        set("objects", ([
  __DIR__"npc/Aquarius.c":1,
]));
        set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
