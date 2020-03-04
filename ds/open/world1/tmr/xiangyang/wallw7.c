// Room: /d/xiangyang/wallw7.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "西城頭");
	set("long", @LONG
這裡是襄陽的西城頭。一些宋兵正在城頭巡邏，一個牙將
正在這兒負責接受各種守城材料，一些弓箭手正撚弓搭箭緊盯
著城下的動靜。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"northeast" : __DIR__"walln8",
		"southdown" : __DIR__"wallw5",
	]));
	set("objects", ([
		__DIR__"npc/ya"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -550);
	set("coor/y", -460);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}