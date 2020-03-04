inherit ROOM;

void create()
{
	set("short", "森林深處");
	set("long", @LONG
經過漫長的一段路，終於走到森林的深處了。在這裡可以完完全
全的感受到這片森林那神祕而無窮無盡的生命力。不過敏感的你似乎
感覺到在這附近有一股十分強大的力量，但是那股力量感覺非常溫和
，不帶有任何敵意。
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"path3",
  		"north" : __DIR__"path5",
	]));

	setup();
	replace_program(ROOM);
}
