// Room: /d/xiangyang/southjie2.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
這裡是襄陽城裡的繁華地段，雖然久經戰火，但在郭靖等
人的保衛下，襄陽的老百姓過著非常安安穩穩的生活。西邊是
襄陽城內最大的一家賭場。東邊是一座兩層的樓閣，掛著“酒”
的招簾，門額上懸掛一方橫匾，上書“覓香樓”三字。一陣陣
酒肉香味撲鼻而來。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"east"  : __DIR__"nixianglou",
		"west"  : __DIR__"duchang",
		"south" : __DIR__"southjie3",
		"north" : __DIR__"southjie1",
	]));
	set("objects", ([
	//	"/d/city/npc/liumang" : 1,
	]));
	set("coor/x", -500);
	set("coor/y", -530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}