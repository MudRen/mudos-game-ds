inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『相』字，而另一邊的牆上寫著：『
藥王佛十二願十二願得妙衣具：願我來世得菩提時，若諸有情貧無衣
食，蚊蟲寒熱，晝夜逼惱；若聞我名，專念受持，如其所好，即得種
種上妙衣服，亦得一切寶莊嚴具，華鬘塗香，鼓樂眾伎隨。』東邊有
一扇拱門，裡面好像有一尊雕像。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"south" : __DIR__"cir11",
  		"northeast" : __DIR__"cir2",
  		"east" : __DIR__"cir6",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
