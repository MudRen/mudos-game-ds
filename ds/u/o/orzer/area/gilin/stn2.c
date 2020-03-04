inherit ROOM;
void create()
{
        set("short","古木上");
        set("long",@LONG
你在古木上行走著，古木上面的視線不太佳，許多分叉的樹枝擋住前方
，讓你要一面撥開樹枝一面前進，不過古木頂端傳來奇特鳴聲，而且這些古
木似乎被什麼東西保護著，陰氣不會十分強烈，不過這上面的生物看來不太
友善。
LONG
        );
        set("exits", ([
  "west" : __DIR__"stn1",
  "east" : __DIR__"stn3",
]));
        set("no_clean_up", 0);
        set("light",0);
        setup();
        replace_program(ROOM);
}










