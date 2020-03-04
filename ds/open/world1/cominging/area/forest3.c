inherit ROOM;
void create()
{
	set("short", "森林外端");
	set("long",@LONG
你悄悄的走進了這塊森林之中的小區域感覺到這裡空氣的新鮮，在
樹上有一些蛇類纏繞，似乎還有眼鏡蛇的樣子，在你的腳下有一株株寄
生在樹幹上的香菇，不過看起來鮮豔，也許是一種劇毒也不一定。
LONG
	);
	set("exits", ([
  "south" : __DIR__"forest4.c",
  "north" : __DIR__"forest2.c",
]));
	set("outdoors","forest");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
