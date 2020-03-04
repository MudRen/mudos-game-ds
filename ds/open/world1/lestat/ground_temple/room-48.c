inherit ROOM;

void create()
{
        set( "short", "廢棄礦坑") ;
        set( "long", @LONG
年久失修的礦坑中，還殘留著不少的礦藏，最近似乎又有人開始
開採這些礦產了，一批批的礦工來到這裡工作，讓這個已經廢棄的礦
坑又開始有了人跡。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "west" : __DIR__"room-47",
                  "south" : __DIR__"room-50",
        ]));
        set("objects",([
                   __DIR__"../npc/mine_worker" : 3,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        setup();
}
