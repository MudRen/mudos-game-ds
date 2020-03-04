// Room: /u/s/slency/area/ugelan/farm4.c

inherit ROOM;

void create()
{
	set("short", "莊園");
	set("long", "這裡是城外的牧羊區，可以看見一些牧人與牧羊犬在草原上活動，\n""廣闊的地與天交錯成一幅每麗的圖畫，遠方高山被雲層籠罩住，虛無縹\n""緲，好一個奧妙的意象啊!!\n"
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"farm2",
  "west" : __DIR__"farm5",
]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
	replace_program(ROOM);
}
