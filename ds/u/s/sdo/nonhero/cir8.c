inherit ROOM;

void create()
{
	set("short", "東黃金埵");
	set("long", @LONG
這裡有一具約三人高的雕像，相貌栩栩如生，不怒自威。旁邊立
了塊石碑，上面寫著：『持國天』，看來這尊雕像就是護世四天王中
的持國天了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"cir9",
	]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("objects", ([
  		__DIR__"obj/east_sky_statue" : 1,
	]));

	setup();
	replace_program(ROOM);
}
