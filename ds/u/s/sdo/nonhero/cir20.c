inherit ROOM;

void create()
{
	set("short", "無相法環");
	set("long", @LONG
這裡一邊的牆上寫著大大的『相』字，而另一邊的牆上寫著：『
藥王佛十二願九願回邪歸正：願我來世得菩提時，令諸有情出魔罥網
，解脫一切外到纏縛；若墮種種惡見稠林，皆為引攝置於正見，漸令
修習諸菩薩行，速證無上正等菩提。』 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  		"northwest" : __DIR__"cir15",
  		"east" : __DIR__"cir21",
	]));
	set("current_light", 0);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
