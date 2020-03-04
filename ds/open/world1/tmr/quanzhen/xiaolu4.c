// xiaolu4.c 後山小路
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "後山小路");
        set("long", @LONG
這裡是後山上的小路。這條小路好像不是人工刻意修出來的，
也許只是以前的採藥人踩多了，現出這樣一條小路來。走到這裡，
你好像迷路了。
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"xiaolu3",
                "north" : __FILE__,
                "south" : __DIR__"xiaolu8",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2680);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}