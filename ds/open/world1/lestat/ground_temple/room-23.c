inherit ROOM;

void create()
{
        set( "short", "地底神殿遺跡") ;
        set( "long", @LONG
[ 呱呱呱 ...]的叫聲迴盪在四周，偌大的房間內到處都是石頭人像
，各種姿勢的人像都栩栩如生，且大小就跟真人一般，但令人奇怪的
是，這些石頭人像的臉上都露出恐懼萬分的神情。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
                  "west" : __DIR__"room-22",
        ]));
        set("objects",([
                   __DIR__"../npc/stone_bird" : 1,
                 ]) );
        set("light",0);
        set("no_clean_up", 0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        setup();
}

