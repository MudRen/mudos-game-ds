inherit ROOM;
void create()
{
        set("short","祭靈森林東側");
        set("long",@LONG
你繼續向森林東邊邁進，而寒氣持續不斷的加強，感覺讓人有點難
以承受的樣子，兩旁的樹木花草也都有氣無力，這樣的森林實在是毫無
生氣，令人無法輕易的放鬆，東北和西南都各有一條路。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t16",
  "southwest" : __DIR__"t13",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}










