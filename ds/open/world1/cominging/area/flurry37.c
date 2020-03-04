inherit ROOM;

void create()
{
	set("short", "小舍前");
	set("long", @LONG
這裡是一個小舍的前面，你在小舍前的走廊就可以看到小舍有許多
的窗戶，大都是打開的，小舍的外面還有一個很長的屋簷，直到走廊外
端，很耐風吹雨打。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"flurry36.c",
  "eastdown" : __DIR__"flurry38.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}
