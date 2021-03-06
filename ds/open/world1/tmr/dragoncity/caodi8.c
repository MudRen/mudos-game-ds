// Room: /open/world1/tmr/dragoncity/caodi8.c

inherit ROOM;

void create()
{
	set("short", "奧特蘭克-草地");
	set("long", @LONG
這兒是奧特蘭克山谷外的大草地，往北可以望見少帥軍
與虎人鐵櫻族終年爭戰的主要戰地－奧特蘭克山谷，雖然這
兒沒有半點戰火，但四週氣氛卻是充滿金屬肅殺之氣。
往北你注意到是一個軍隊駐紮的寨地。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : "/open/world1/tmr/crush_bone/map_23_4.c",
  "southwest" : __DIR__"caodi7e",
]));
	set("current_light", 4);
        set("objects", ([
                __DIR__"npc/orc_sentry" : 1, 
        ]) );
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
