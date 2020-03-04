// Room: /open/world1/acme/area/f3.c

inherit ROOM;

void create()
{
	set("short", "野林");
	set("long", @LONG
這是野林的另一處，森林中倒有一番新氣象，大樹和野竹間隔林
立，野竹粗大，巨木宏偉，更顯得自身的渺小，在佈滿落葉的林地上
赫然發現數個腳印，不是野獸，而是人的腳印，你心裡不禁想，在這
種地方，竟會出現人的腳印，故不由自主的提高警覺。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"f2",
  "west" : __DIR__"f4",
]));
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
