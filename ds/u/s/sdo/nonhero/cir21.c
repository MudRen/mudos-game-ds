inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『眾生』二字，而另一邊的牆上寫著
：『藥王佛十二願八願轉女成男：願我來世得菩提時，若有女人為女
百惡之所逼惱，極生厭離，願捨女身；聞我名已，一切皆得轉女成男
，具丈夫相，乃至證得無上菩提。』 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
    		"west" : __DIR__"cir20",
  		"north" : __DIR__"cir17",
  		"east" : __DIR__"cir22",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
