inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
這裡是森林內側的深處了，這裡有著隱隱的低吟聲，似乎有著什
麼不尋長的事物存在，人型生物感覺也比較稀少，莫非有什麼他們所
懼怕的物品，也許應該仔細的在附近探尋一番。
LONG
        );
        set("exits", ([
        "south" : __DIR__"t38", 
        "northeast" : __DIR__"t36",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














