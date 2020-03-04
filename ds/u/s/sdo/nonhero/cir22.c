inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『無』字，而另一邊的牆上寫著：『
藥王佛十二願七願身心康樂：願我來世得菩提時，若諸有情眾病逼切
，無救無歸，無醫無藥，無親無家，貧窮多苦，我之名號一經其耳，
眾病悉除，身心安樂；家屬資具，悉皆豐足，乃至證得無上菩提。』 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"west" : __DIR__"cir21",
  		"northeast" : __DIR__"cir19",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
