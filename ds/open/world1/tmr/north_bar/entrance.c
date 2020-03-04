// Room: /open/world1/tmr/north_bar/entrance.c

inherit ROOM;

void create()
{
	set("short", "千年古洞－洞口");
	set("long", @LONG
這裡是古洞的洞口，但裡面十分安靜，連水滴生都可以聽的
一清二楚。但裡面傳來陣陣陰森的涼風，不禁讓人毛骨悚然，如
果你決定進去，務必要十分小心，提高警覺，不然還是快點走出
洞口吧！
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"f1",
   "out" : __DIR__"town31",
]));
	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
        ::valid_leave();
   
           if( dir == "out" && !userp(me) )
                        return 0;
        return ::valid_leave(me,dir);
}


