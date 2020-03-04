inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
你來到了一個相當複雜的路口，南邊不遠處矗立著一座巨大的門
，東南方的道路則不知道通往哪裡，往北的路上，有兩位穿著緊身裝
束的人類看守著，看來北邊的道路通往的地方大有文章。
LONG
);
        set("exits", ([ /* sizeof() == 4 */
                  "south" : __DIR__"room-27",
                  "north" : __DIR__"room-32",
                  "southeast" : __DIR__"room-28",
                  "southwest" : __DIR__"room-26",
        ]));
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}


