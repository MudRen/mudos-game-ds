// Room: /d/xiangyang/qianzhuang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "錢莊");
	set("long", @LONG
這裡是襄陽的錢莊，因為這裡商業相當發達，各地的商號
都和這裡有銀錢來往。錢莊裡有很多人在存取錢，也有人在兌
換銀兩。看著這麼多的錢財滾來滾去，真是讓人眼饞啊。但眼
下大敵當前，全城一致抵禦元兵。錢莊的業務由華山弟子接管，
支援大俠郭靖和郭夫人。牆上貼著一個牌子(paizi)。
LONG );
	set("item_desc", ([
		"paizi" : @TEXT
     本錢莊提供以下服務：
      存錢        deposit
      取錢        withdraw
TEXT
	]));
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/huangzhen" : 1,
	]));
	setup();
	replace_program(ROOM);
}

