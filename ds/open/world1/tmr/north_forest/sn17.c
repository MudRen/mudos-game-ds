// Room: /u/l/lestia/area/sn17.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG
走到這裡，原本緊跟著你的那陰冷眼神已不知何時失去了蹤影，取而代
之的則是一份寂靜無聲的恐懼，除了幾隻螳螂在草上歇息之外，就只有綠樹
和冷風在陪伴著你，原本還有一點光線的森林到了這裡也漸漸因樹木林立，
樹葉繁多而變得黑暗。
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn18",
  "west" : __DIR__"sn16",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
