// Room: /u/s/sonicct/area/shop3.c

inherit ROOM;

void create()
{
	set("short", "防具店");
	set("long", @LONG
這是一間簡潔的防具店，都是旅行人士經常出入的地方。房
間內掛滿各式各樣的防具，供人客自己購買，還以十分合理的價
錢售出。
LONG
	);
	set("light",1);
	set("no_skill",1);
	set("no_clean_up", 0);
	set("room_type","sell");        
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road4",
  "south" : __DIR__"road10",
  ]));
	set("no_clean_up",0);

	setup();
	replace_program(ROOM);
}
