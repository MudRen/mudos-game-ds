// Room: /d/xiangyang/anfupailou.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "安撫府牌樓");
	set("long", @LONG
這裡是安撫使府前的一座牌樓，高達二丈，由黃玉制成，
和東面的將軍府屋頂的琉璃瓦在陽光的照耀下黃白掩映，金碧
輝煌，令人目為之眩，感覺分外巍峨莊嚴。你抬頭望去，但見
牌樓上四個大金字“安撫使府”。牌樓下站著兩派手那刀槍的
宋兵，緊緊盯著每一個靠近這兒的人。北面就是安撫府大院了。
南面就是襄陽的中央廣場。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"guangchang",
		"north" : __DIR__"anfugate",
	]));

	setup();
	replace_program(ROOM);
}