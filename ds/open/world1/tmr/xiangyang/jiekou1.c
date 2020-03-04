// Room: /d/xiangyang/jiekou1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "大街口");
	set("long", @LONG
因為這兒是十字街口，所以非常熱鬧。小商小販們在向行
人吆喝著，兜售他們的商品。雖然襄陽飽受蒙古軍侵擾，但這
兒看不出人們有絲毫的緊張，好像他們已司空見慣、習以為常
了。北面和西面是胡同，許多襄陽城的老百姓住在裡面，東面
和南面是青石鋪就的大街。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"northroad1",
		"south" : __DIR__"westroad2",
		"west"  : __DIR__"hutong1",
		"north" : __DIR__"hutong2",
	]));
	set("objects", ([
	//	"/d/village/npc/seller" : 1,
	]));
	set("coor/x", -530);
	set("coor/y", -470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}