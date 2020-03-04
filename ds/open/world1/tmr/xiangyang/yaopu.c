// Room: /d/xiangyang/yaopu.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "藥鋪");
	set("long", @LONG
藥鋪不大，卻異常的整潔；正面是櫃台，櫃台後面是個大
櫃子幾百個小抽屜上一一用紅紙標著藥材的名稱；靠近屋頂的
牆上懸著一塊黑底金字的匾額，寫著“妙手回春”。地下幾個
伙計正在分揀剛剛收購來的草藥。東邊一張小矮桌兒，上面放
著筆墨紙硯，桌後坐著一位老郎中。一股刺鼻藥味充滿了整個
房間。
LONG );
	set("exits", ([
		"north" : __DIR__"eastjie1",
	]));
	set("objects", ([
//		"/d/city/npc/huoji" : 1,
	]));
	set("coor/x", -490);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}