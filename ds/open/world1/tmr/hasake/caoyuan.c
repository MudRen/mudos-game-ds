// caoyuan.c 草原
inherit ROOM;
void create()
{
        set("short", "草原邊緣");
        set("long", @LONG
這裡是大草原和沙漠接壤之地，青草由稀至密，向西綿綿延伸而去。
地上有幾行駱駝踏過的蹄印，看樣子這裡常常有商隊來往。西南方好像有
些炊煙。
LONG);
        set("exits", ([
            "east" : __DIR__"caoyuan1.c",
            "northwest" : __DIR__"pmchang",
        ]));
        set("objects", ([
                    __DIR__"npc/biaoshi" : 1,
        ])); 
        set("outdoors", "land");
        setup();
}
