inherit ROOM;
void create()
{
	set("short", "英雄之屋地下");
	set("long",@LONG
碰的一聲，你重重的跌落在此地，你觀望了一下四周，有許許多多
的武功密技在此，不過卻因為封在鐵櫃子中，也上了鎖，所以你沒辦法
閱讀，在東方的牆壁上留有一些些的字(word)。
LONG
	);
	set("exits", ([
  "up" : __DIR__"herohouse1.c",
]));
	set("item_desc",([
  "word" : "牆壁上面的字因為長滿了蘚苔而無法看清。\n",
]));
	set("no_clean_up", 0);
	set("light", 1);
	setup();
	replace_program(ROOM);
}