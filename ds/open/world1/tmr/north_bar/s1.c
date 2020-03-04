// Room: /open/world1/tmr/north_bar/s1.c

inherit ROOM;

void create()
{
	set("short", "千年古洞-地下二層");
	set("long", @LONG
這裡是古洞的第二層，真沒想到，這個黑暗的古洞，竟然還
有分層，而且這裡似乎更恐怖了。耳邊傳來陣陣的野獸的慘叫聲
，似乎是野獸在互相自殘的聲音。
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"s2",
  "up" : __DIR__"f12",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
   
        if( dir == "up" && !userp(me) && me->id("monster") )
                        return 0;
        return ::valid_leave(me,dir);
}
