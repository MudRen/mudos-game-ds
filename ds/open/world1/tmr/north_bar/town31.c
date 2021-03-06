// Room: /open/world1/tmr/north_bar/town31.c

inherit ROOM;

void create()
{
	set("short", "北蠻村-石壁洞口");
	set("long", @LONG
來到這裡，似乎已經走到盡頭了。眼前似乎是一處洞穴，
應該就是北蠻村村民恐懼的千年洞穴，傳聞裡面住有吃人的怪
物，每年總有幾個倒楣鬼誤闖進去洞裡，就沒有再出來過了。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"town30",
  "enter" : __DIR__"entrance",
]));
	set("no_clean_up", 0);
	set("current_light", 3);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
