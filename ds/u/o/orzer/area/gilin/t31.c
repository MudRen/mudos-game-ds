inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
你慢慢的朝向森林深處走去，這裡的陰氣很重，四周瀰漫一股股的
的含怨之氣，遠處傳來緩緩的走路聲，可是又感覺不到半點生人的氣息
，到底到底是什麼東西在移動著，霧氣漸漸轉為濃厚。
LONG
        );
        set("exits", ([
        "southwest" : __DIR__"t32",
        "north" : __DIR__"t30",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}













