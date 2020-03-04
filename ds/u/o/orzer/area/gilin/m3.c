inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你通過了山道來到了一條蜿蜒的小徑，這比剛剛的山路更為狹窄，
而且也較為彎曲，感覺反而走來倍添難度，不過卻還是有跡可循，看來
這裡也是曾經有人走過，只是現在沒落了。
LONG
        );
        set("exits", ([
  "southdown" : __DIR__"m2",
  "northwest" : __DIR__"m4",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}



