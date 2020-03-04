inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
好不容易走完了又長又暗的通道，你來到了一座巨大的地下神殿
前面，巨大的神殿加上周圍被開鑿的洞穴，真不知道要多少的人力才
能完成，讓你迫不及待地想進去看看。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "up" : __DIR__"room-01",
                  "north" : __DIR__"room-03",
        ]));
        set("objects",([
                   __DIR__"../npc/s_guard" : 2,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

