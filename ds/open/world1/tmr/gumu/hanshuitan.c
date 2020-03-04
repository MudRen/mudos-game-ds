// hanshuitan.c 寒水潭
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
	set("short", "寒水潭");
	set("long", @LONG
這里是草地的邊緣，青草已經很稀疏了，仍然有一二玉蜂來回地飛
過尋覓食物。你的面前是一個清波蕩漾的大水潭 (tan)，陽光映照下，
水面泛起了一道七色彩虹，望著這般美景，你俗念盡消。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northwest" : __DIR__"caodi2",
	]));
	set("objects", ([
          __DIR__"npc/yufeng" : 4,
	]));
	set("item_desc", ([
		"tan": "潭水很清，隱約可以見過水底的怪石嶙峋，一二游魚倏地從水底游過，又不知道躲到哪塊石頭后面藏身去了。\n",
	]) );
	setup();
	replace_program(ROOM);
}

