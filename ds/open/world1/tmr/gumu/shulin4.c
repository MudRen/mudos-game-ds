// shulin4.c 樹林
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "小樹林");
	set("long", @LONG
走在林中，你只聞錚錚琴聲，一股淡淡白煙，帶著極甜的花香，自
密林深處傳出。一群乳白色的蜜蜂在你身旁飛來飛去。不論往哪ㄦ走盡
是茂密的樹林。
LONG	);
	set("outdoors", "forest");
	set("exits", ([
		"east"  : __DIR__"shulin6",
		"west"  : __DIR__"shulin5",
		"north" : __DIR__"kongdi",
		"south" : __DIR__"shulin0",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
