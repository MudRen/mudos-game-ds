// Room: /u/f/fanny/area/forest/forest5.c

inherit ROOM;

void create()
{
	set("short", "松樹林");
	set("long", @LONG
順著山徑走過來，那一股莫名的壓力也漸漸增強，但奇怪的是，
肅殺之氣卻漸漸的淡了，左右兩邊的樹木也有越來越高大的感覺，似
乎比剛剛所看到的樹還大了許多。這有棵參天巨木，光要環抱住它，
沒三十個人恐怕還無法做到。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"forest6",
  "north" : __DIR__"forest2.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
