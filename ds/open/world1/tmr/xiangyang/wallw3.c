// Room: /d/xiangyang/wallw3.c
// Date: Jan. 8 1999 by Winder
// Modified by Zeratul Jan 15 2001,限制了瘋狂爬城

inherit __DIR__"wall.c";

void create()
{
	set("short", "石階");
	set("long", @LONG
這是登向城頭的石階，因為城牆很高，所以很陡。石階兩
側有可供拉車上下的斜坡道。
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	set("exits", ([
		"northup"   : __DIR__"wallw5",
		"southdown" : __DIR__"wallw1",
	]));
	set("coor/x", -550);
	set("coor/y", -480);
	set("coor/z", 20);
	setup();
}