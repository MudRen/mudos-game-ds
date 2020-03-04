// Room: /u/s/suez/area/hotel_back.c
inherit ROOM;
void create()
{
	set("short", "客棧後院");
	set("long", @LONG
你的眼前一亮，一條碧綠的小溪就在你面前流過，而一座可愛的小竹
橋橫跨其上，四周的竹林也不時飄出清爽的山風，橋的對面的竹林中隱約
有間小屋或許可以過去(pass)看看。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hotel_path",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_pass", "pass");
}

int do_pass(string arg)
{
        object me;
        me=this_player();
 

        if (arg != "小竹橋" && arg !="橋" )
                return 0;
        else 
        {
        me->move(__DIR__"hotel_room4");
        return 1;
        }
}