// Room: /open/world1/acme/bonze/b5.c

inherit ROOM;

void create()
{
	set("short", "上山小路");
	set("long", @LONG
走出荒野的山道，眼前出現一條只容一人通行的石子小徑，曲曲
折折的向上盤旋；道旁雜草蔓生，似乎有東西在虎視眈眈的盯著你看
，你不自覺地有些膽怯，只希望快些離開這山嶺，回到城鎮之中。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"b6",
  "northdown" : __DIR__"b4",
]));
        set("outdoors","land");

	setup();
	replace_program(ROOM);
}
