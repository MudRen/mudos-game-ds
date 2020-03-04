inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『壽者』二字，而另一邊的牆上寫著
：『藥王佛十二願十一願得妙飲食：願我來世得普提時，若諸有情，
饑渴所惱，為求食故，造諸惡業；得聞我名，專念受持，我當先以上
妙飲食，飽足其身，後以法味，畢竟安樂而建立之。』 
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west" : __DIR__"cir10",
  		"south" : __DIR__"cir15",
  		"north" : __DIR__"cir5",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
