inherit ROOM;
void create()
{
	set("short", "步靈城西大街");
	set("long",@LONG
這是步靈城中的西大街頭，在街上有許多小孩子在討論事情，你彷
彿聽到什麼井底、井壁蘚苔之類的，似乎很想要的樣子，在東方是步靈
城的中央廣場，而在西方則是往西大門前進的路，這裡的附近有一些的
藥舖，好像生意還不錯。
LONG
	);
	set("exits", ([
  "east" : __DIR__"bwest.c",
  "west" : __DIR__"bwest2.c",
  "north" : __DIR__"herbshop.c",
]));
	set("objects",([
  __DIR__"npc/child1.c":1,
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
