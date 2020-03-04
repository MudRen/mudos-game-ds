// Room: /d/xiangyang/tiejiangpu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "鐵匠鋪");
	set("long", @LONG
這裡原來是一家極其簡陋的鐵匠鋪。近年來蒙古大軍屢次
進犯襄陽，這家鐵匠鋪被官府徵用，作為官辦作坊。目前規模
很大，一般用來為襄陽守軍打造鎧甲、兵器等，近來因襄陽需
籌備守城物資，奉郭夫人之命也生產一些鐵??、鐵錘、伐木斧
頭等。只見幾十個鐵匠正叮叮噹當地忙個不停。
LONG );
	set("exits", ([
		"west" : __DIR__"southjie3",
	]));
	set("objects", ([
		__DIR__"npc/tiejiang" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}