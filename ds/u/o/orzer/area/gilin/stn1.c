inherit ROOM;
void create()
{
        set("short","古木上");
        set("long",@LONG
你爬到了古木上面來，這裡看來枝葉茂密，而且古木們連綿相連不斷，
讓你有點不知道從何走起，不過古木頂端傳來奇特鳴聲，而且這些古木似乎
被什麼東西保護著，陰氣不會十分強烈，不過這上面的生物看來不太友善。
LONG
        );
        set("exits", ([
  "east" : __DIR__"stn2",
  "down" : __DIR__"t18",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}










