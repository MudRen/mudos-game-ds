// Room: /d/xiangyang/nixianglou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "覓香樓");
	set("long", @LONG
襄陽城裡沒有不知道“覓香樓”的。雖是抗戰時期，來往
公務卻多，飯後談資也富，生意反見興隆。樓下佈置簡易，顧
客多是匆匆的行人，買點包子、雞腿、米酒就趕路去了。樓上
是雅座。抗戰期間，厲行節約，不許揮霍，就沒啥生意，只好
關了。
LONG );
	set("exits", ([
		"west" : __DIR__"southjie2",
	]));
	set("objects", ([
//         __DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
