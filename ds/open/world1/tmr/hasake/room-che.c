// Room: /open/world1/tmr/hasake/room-che.c

inherit ROOM;

void create()
{
	set("short", "車爾庫的家");
	set("long", @LONG
車爾庫的帳蓬中收拾得很整潔，一張張織著紅花綠草的羊毛毯掛在四
周。矮桌上放著幾個大酒碗，一個身材苗條的女孩子捧了酒漿出來笑嘻嘻
地看著你。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/aman" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"caoyuan8",
]));

	setup();
	replace_program(ROOM);
}
