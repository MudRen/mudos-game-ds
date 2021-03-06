// Room: /u/d/darkfool/area1/l2.c

inherit ROOM;

void create()
{
	set("short", "街道-往圖書館");
	set("long", @LONG
四周靜悄悄的，你有點驚訝的發現路的兩旁長了一排小小的樹，剛好
延伸到圖書館館臺階前，好像在迎接要走入圖書館的人一般，看著可愛的
小樹，心情也覺得恬適了起來。你在猜想應該是圖書館裡的人種的。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"l1",
  "south" : __DIR__"l3",
]));

	setup();
	replace_program(ROOM);
}
