// Room: /tmr/garea/forest10.c

inherit ROOM;

void create()
{
	set("short", "林中小路");
	set("long", @LONG
你正走在一條林中的小路，四週彌漫著一片淡霧，還透著一絲寒氣，
北面的方向便不時傳來一股惡臭味，透過迷霧望去，隱隱約約可看見有處
綠沼。往南迷霧深處瞧去，更見慘白一片，只怕走得進去，找不到路出來
.....
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
        "southeast" : __DIR__"forest9",
	  "northwest" : __DIR__"forest12",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
