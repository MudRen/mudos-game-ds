inherit ROOM;
void create()
{
        set("short","祭靈森林內側");
        set("long",@LONG
這裡是森林內側的深處了，此地的霧氣也最為濃厚，而且人型生
物也越來越強，也許再往下走就能得知他們保護的東西，也讓你更為
謹慎小心起來，也許不是什麼簡單的東西。
LONG
        );
        set("exits", ([
        "northwest" : __DIR__"t42", 
        "northeast" : __DIR__"t44",        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}














