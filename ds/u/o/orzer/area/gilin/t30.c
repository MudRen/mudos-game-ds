inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
你到了祭靈森林的最內側了，這裡的陰氣很重，四周瀰漫一股股的
的含怨之氣，莫非這裡就是當初天朝和前朝軍隊的戰場，從這樣的氣息
之沉重，便也就可以推出當時戰況的慘烈，四周有著奇怪白影飄蕩。
LONG
        );
        set("exits", ([
        "south" : __DIR__"t31",
        "northeast" : __DIR__"t29",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}












