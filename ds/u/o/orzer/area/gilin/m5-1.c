inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你好不容易通過狹窄難行的小徑，這裡的道路寬廣不少，感覺心情
也輕鬆了許多，前面就是山坡下，面前聳立著一個哨樓，讓你頗為驚奇
，在這人煙罕至的地方，竟然有官兵在守備。
LONG
        );
        set("exits", ([
  "southup" : __DIR__"m5",
  "north" : __DIR__"m5-2",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}







