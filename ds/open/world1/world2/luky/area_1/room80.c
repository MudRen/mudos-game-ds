// Modify with AreaMaker1.0
// Room80.c
#include <path.h>
inherit ROOM;

void create()
{
	set("short","大草原");
	set("long", @LONG
這裡是一片大草原，你的周圍都是高及膝蓋的綠草。遠方不時傳
來一陣陣知了的蟲鳴聲，你跟著聲音抬頭望去，看見西北邊有一片
濃密的樹林，西邊不遠處還有一個小池塘。
LONG
	);
	set("exits", ([
		"north": __DIR__"room70",
		"west": __DIR__"room79",
		//"bridge" : LUKY_NOW+"test/room3",
	]));
	set("no_clean_up", 0);
	set("outdoors","land");	
	setup();
	replace_program(ROOM);
}

