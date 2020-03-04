inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你好不容易通過狹窄難行的小徑，這裡的道路寬廣不少，感覺心情
也輕鬆了許多，前面就是山坡下，似乎通往著一座森林，看來陰森鬱悶
，氣氛十分不尋常，可能有什麼危險的事物。
LONG
        );
        set("exits", ([
  "southup" : __DIR__"m5-5",
  "northwest" : __DIR__"m7",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}





