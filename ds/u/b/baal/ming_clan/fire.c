inherit ROOM;
void create()
{
 set("short","聖火禁地");

 set("long",@LONG
這裡是明教中最神聖的地方，前方有一做聖火台，臺中然燒著聖火
，相傳當初明教教主和聖使在創幫時，受到重重阻礙，最後是以聖
火的力量度過難關，才有今日的明教。
LONG
    );
 set("exits",([ "down": __DIR__"saintming",
    ]));
        set("no_kill",1);
        set("objects",([
__DIR__"item/ming_platform" :1,
]));

        set("light",1);
 setup();
        set("stroom",1);
}

