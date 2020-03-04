inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
燒盡的柴火，尚有一絲餘溫，肉香伴隨著白色的煙，環繞盤據在
這個房間，營火堆上正串著一隻山豬在烤著，飢腸轆轆的你，口水都
流到腳邊了。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "east" : __DIR__"room-08",
        ]));
        set("objects",([
                   __DIR__"../npc/gui" : 1,
                 ]) );
        set("light",1);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

