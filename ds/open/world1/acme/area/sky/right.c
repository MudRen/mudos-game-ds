inherit ROOM;

void create()
{
	set("short", "鍛氣室");
	set("long", @long
一間八邊形的練武房，八面牆上各刻有擺著古怪姿勢的人形圖案，房間底
下是用青石鋪成，上面刻滿卦文，似是一種奇妙的步法，真是玄奇房間中
還擺置精工打造，巧心設計的機關銅人。
long);
	set("exits", ([
		"east" : __DIR__"room15",
	]));
	setup();
}
