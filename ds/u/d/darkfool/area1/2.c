// Room: /u/d/darkfool/area1/2.c

inherit ROOM;

void create()
{
	set("short", "街道");
	set("long", @LONG
你正走在新諾提斯的東西向主要大街上，街道兩側盡是一個個金
屬製形式各異的方形物，若是仔細一點觀察，你會發現它們上面都刻
著小小的HANS商標。這些東西是HANS集團出品的高科技速成屋，看來
這鎮裡的居民幾乎清一色都是以此為家，或許跟HANS負責這裡的礦業
發展有關吧。東方不遠處有間跟鎮裡其他建築迥異的小屋子，它不是
金屬所製，看來像是用木頭建成的。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"1",
  "east" : __DIR__"3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
