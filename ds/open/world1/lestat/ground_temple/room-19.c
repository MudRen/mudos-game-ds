inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
來到這裡，你眼睛不由得為之一亮，在地下迷宮中，居然還有這
樣一個地方，壁上掛滿了一幅幅的名畫，房間的擺設相當古典優雅，
各種名貴的古董分佈在四周。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"room-20",
        ]));
        set("objects",([
                   __DIR__"../npc/hong" : 1,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

