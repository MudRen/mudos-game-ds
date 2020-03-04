inherit ROOM;

void create()
{
	set("short", "洞窟內");
	set("long", @LONG
洞窟到這又漸漸的收攏，看來盡頭差不多就快要到了。不過南邊
還有一個小小的空間，而水聲就是從那裡傳出來的。這引起你的好奇
心，想要趕快過去看一下。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 4 */
  		"northwest" : __DIR__"gcave11",
  		"north" : __DIR__"gcave10",
  		"northeast" : __DIR__"gcave12",
  		"south" : __DIR__"gcave14",
	]));

	setup();
	replace_program(ROOM);
}
