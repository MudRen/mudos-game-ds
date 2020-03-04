
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
這是通往巫毒教教壇的走廊，平時來這的都是來膜拜神靈
的，這條走廊兩旁種了些奇奇怪怪的植物，也有遮陽遮雨的屋頂，
撐住屋頂的梁柱雕工極佳。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room34",
	    "west" : __DIR__"room37",
	    "north": __DIR__"room38",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
