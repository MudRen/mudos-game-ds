inherit ROOM;
void create()
{
        set("short","山路");
        set("long",@LONG
你正在山路上緩緩的前進著，由於山路狹小，所以走來十分的辛苦
，而周圍看來頗為荒涼，可能是這裡離人群聚居處較為遙遠，因此少有
人跡，前面有一條往上的小徑。
LONG
        );
        set("exits", ([
  "northup" : __DIR__"m3",
  "southwest" : __DIR__"m1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}



