inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
房間內放置了各式各樣的服裝跟飾品，不論是男裝女裝，老的少
的都有，令你不禁覺得好奇，這麼多服裝是用來做什麼用的。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "southwest" : __DIR__"room-28",
        ]));
        set("objects",([
                   __DIR__"../npc/lei" : 1,
                 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}


