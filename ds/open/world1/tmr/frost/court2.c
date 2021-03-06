// Room: /open/world1/tmr/frost/court2.c

inherit ROOM;

void create()
{
	set("short", "寒澈道觀-中庭");
	set("long", @LONG
你正走在道觀內的中庭，中庭為道觀內的的中正部份，可通往道觀各
處的建築。整體來說，觀內建築分成人造景觀及自然景觀兩大類，建築本
身也有等級差別，可分成殿式建築、大式建築及小式建築三個等級。四週
環境清幽安祥，路過的道人都親切地跟你打聲招呼。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"court1",
  "east" : __DIR__"depositary",
  "north" : __DIR__"court3",
]));
	set("current_light", 2);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
