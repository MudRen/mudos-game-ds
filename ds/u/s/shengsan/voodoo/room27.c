
inherit ROOM;

void create()
{
	set("short", "前廳");
	set("long", @LONG
地上的地毯是大紅色的，靠在牆邊的是整齊的桌椅及櫃子，常常會有
人來這打掃整理，你看到西面的牆上有許多的毒蟲標本，還蠻噁心的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "east" : __DIR__"room22",
	    "north": __DIR__"room26",
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
	replace_program(ROOM);
}
