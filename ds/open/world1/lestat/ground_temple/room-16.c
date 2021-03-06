inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
通過大廳之後，地下通路開始變小變窄，空氣也越來越混濁，旁
邊的牆壁開始出現暗紅色的斑紋，大概是附近的岩層富含鐵礦跟銅礦
吧，這也表示地下遺跡越來越深入地底。
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "northwest" : __DIR__"room-20",
                  "southeast" : __DIR__"room-15",
        ]));
        set("objects",([
                   __DIR__"../npc/wood_monster" : 1,
                 ]) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

