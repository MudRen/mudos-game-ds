// Room: /open/world1/tmr/advbonze/summit2.c

inherit ROOM;

void create()
{
	set("short", "凌雲峰頂-平台東北角");
	set("long", @LONG
你正站在凌雲峰頂上東北角的一處平台中，在你前方不遠處供奉著一
尊「不動金剛羅漢石像」，在往前數步就是峰頂的崖邊，地上積雪日深，
稍一踩不穩，就會連滾帶爬的摔下山去。
LONG
	);
	set("outdoor", "snow");
	set("no_recall",1);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "snow");
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"summit1",
]));

	setup();
	replace_program(ROOM);
}
