inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『無』字，而另一邊的牆上寫著：『
藥王佛十二願十願刑縛解脫：願我來世得菩提時，若諸有情，王法所
錄，繩縛鞭撻，繫閉牢獄，或當刑戮，及餘無量災難凌辱，悲愁煎逼
，身心受苦；若聞我名，以我福德威神力故，皆得解脫一切憂苦。』
東邊有一扇拱門，裡面好像有一尊雕像。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"north" : __DIR__"cir11",
  		"southeast" : __DIR__"cir20",
  		"east" : __DIR__"cir16",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
