inherit ROOM;

void create()
{
        set( "short", "廢棄礦坑") ;
        set( "long", @LONG
鑽過了小小的通道後，你來到了礦坑的深處，下方有一個洞穴可
以繼續往內部走，但是聽了剛剛那個老礦工說的話，你心裡覺得毛毛
的，似乎感到下方洞穴傳來一股陰森森的感覺。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "down" : __DIR__"room-33",
                  "north" : __DIR__"room-50",
        ]));
        set("light",0);
        set("no_clean_up", 0);
        setup();
}

