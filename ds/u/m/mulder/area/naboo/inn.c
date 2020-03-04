// Room: /u/m/mulder/area/naboo/inn.c

inherit ROOM;

void create()
{
	set("short", "旅館");
	set("long", @LONG
這裡是一間五星級的旅館，費用當然是比較昂貴，還日一些
日用品提供給住客。從這裡的裝修看來，你知道這裡的設計師一
定是在宇宙很有名氣的。
LONG
	);
    set("no_kill",1);
   set("no_shoot",1);
   set("no_cast",1);
   set("no_exert",1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/keeper" : 1,
]));
	set("room_type", "hotel");
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"road3",
  "enter" : __DIR__"inn2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
