inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你繼續的前進著，這裡的寒氣較為減弱，也讓你感覺比較自在不少
生物也看起來比較活潑，莫非有什麼東西影響了森林的詭異氣息，看來
是有人在對抗森林內的東西，也讓你想看看對方是誰。
LONG
        );
        set("exits", ([
  "north" : __DIR__"t7",
  "southeast" : __DIR__"t3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}









