inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『我』字，而另一邊的牆上寫著：『
藥王佛十二願二願開曉事業：願我來世得菩提時，身如琉璃，內外明
徹，淨無瑕穢，光明廣大，功德巍巍，身善莊嚴，過於日月；幽冥眾
生，悉蒙開曉，隨意所趣，作諸事業。』
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  		"west" : __DIR__"cir2",
  		"south" : __DIR__"cir7",
  		"east" : __DIR__"cir4",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
