inherit ROOM;
void create()
{
	set("short", "步靈城東城門前");
	set("long",@LONG
這裡是步靈城東邊大門前的廣場，呈一個球形的半圓弧，在這兒有
一些的巡邏隊在巡邏這附近的安全，也順便看有無行蹤可疑的人物，聳
立在你面前的是高高的城牆，幾乎有你的十倍之高，實在令人想不透是
如何蓋起的，城牆上也有許多的衛兵在巡邏。
LONG
	);
	set("exits", ([
  "west" : __DIR__"beast4.c",
  "east" : __DIR__"bdoor1.c",
]));
	set("outdoors","land");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}