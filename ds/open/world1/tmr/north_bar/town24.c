// Room: /open/world1/tmr/north_bar/town24.c

inherit ROOM;

void create()
{
	set("short", "北蠻村－村長家");
	set("long", @LONG
這裡是村長家，大廳佈置的古色古香，旁邊的圓桌上放
著組茶具，正沏著一壺茶，茶香味與庭院的花香味融合在空
氣中，外頭不時吹進來微微風，讓人感覺非常的舒暢。
LONG
	);
	set("light", 1);
        set("valid_startroom", 1);
	set("objects", ([
	__DIR__"npc/mayor" : 1,  ]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"town21",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
