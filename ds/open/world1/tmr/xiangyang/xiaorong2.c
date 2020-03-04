// Room: /d/xiangyang/xiaorong2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "胡同");
	set("long", @LONG
這裡是襄陽城內老百姓的居住區。只見小弄兩邊是有些小
店面，有米行、小雜貨鋪等。一些居民從這裡進進出出。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"jiekou2",
	]));
	set("objects", ([
		__DIR__"npc/boy"  : 1,
		__DIR__"npc/girl" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}