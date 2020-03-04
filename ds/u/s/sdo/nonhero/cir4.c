inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『相』字，而另一邊的牆上寫著：『
藥王佛十二願三願資生無盡：願我來世得菩提時，以無量無邊智慧方
便，令諸眾生皆得無盡所受用物，莫令眾生有所乏少。』
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"west" : __DIR__"cir3",
  		"southeast" : __DIR__"cir9",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
