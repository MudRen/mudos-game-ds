// Room: /u/l/lestia/area/sn20.c

inherit ROOM;

void create()
{
	set("short", "北方大森林-小徑");
	set("long", @LONG

你眼前出現了一條筆直的小道直通往森林的深處，微風緩緩的吹來，腳
下的草地漸漸變成因許多人走過而踏平的泥地，泥地上還有許多因枯萎而掉
落變黃的樹葉，每走一步都會聽到與枯葉磨擦而生的沙沙聲，平添了一份恐
怖。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([
__DIR__"npc/rabbit":2,
]));

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"sn19",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
