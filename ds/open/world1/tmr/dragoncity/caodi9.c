// Room: /open/world1/tmr/dragoncity/caodi9.c

inherit ROOM;

void create()
{
	set("short", "奧特蘭克-草地");
	set("long", @LONG
這兒是奧特蘭克山谷外的大草地，往北可以望見少帥軍
與虎人鐵櫻族終年爭戰的主要戰地－奧特蘭克山谷，雖然這
兒沒有半點戰火，但四週氣氛卻是充滿金屬肅殺之氣。
LONG
	);
	set("outdoors", "land");
	set("current_light", 5);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"caodi10",
  "southeast" : __DIR__"caodi7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
