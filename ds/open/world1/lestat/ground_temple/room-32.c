inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
在一片黑暗中，什麼都看不到，但是你始終覺得有人在監視著你
，那種隨時被監視的感覺，讓你感到相當不安，只想趁早離開這裡。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "south" : __DIR__"room-30",
        ]));
        set("objects",([
                   __DIR__"../npc/xu_kong" : 1,
                 ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
  load_object(__DIR__"temp");
}


