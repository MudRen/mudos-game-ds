inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『無』字，而另一邊的牆上寫著：『
藥王佛十二願一願生佛平等：願我來世得阿耨多羅三菩提時，自身光
明，熾然照耀無量無數世界，以三十二大丈夫相，八十隨形好，莊嚴
其身；令一切有情，如我無異。』
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"cir5",
  		"east" : __DIR__"cir3",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
