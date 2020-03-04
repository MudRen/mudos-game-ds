// Room: /u/a/acme/area3/p15.c

inherit ROOM;

void create()
{
	set("short", "馬房");
	set("long", @LONG
這是一間馬房，這裡飼養著許多駿馬，或許你可以趁著主人不注意時
偷偷的牽幾匹回去。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p14",
]));
       set("light",1);
set("objects",([
    __DIR__"npc/general3.c" : 1,
    __DIR__"npc/horse" : 1,
    __DIR__"npc/horse2" : 1,
]) );
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
