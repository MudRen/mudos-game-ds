#include <ansi.h>
inherit MOBROOM;

void create()
{
        set("short", "遺世島－"HIG"獸原"NOR);
        set("long", @LONG
這裡是一望無際的大草原，長滿及膝的青翠雜草，還有許多不知
名的花草植物，草原上飛舞著七彩蝴蝶和奇異的昆蟲，遠遠可以看到
珍禽異獸在草原中奔跑覓食，放眼望去渺無人煙，儼然是動物的世外
桃源。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"room6",
  "west" : __DIR__"room8",
  "south" : __DIR__"room3",
  "north" : __DIR__"room12",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("chance",15);
        set("mob_amount",1); 
        set("mob_max",1);
        set("mob_object",({
            __DIR__"npc/prick-cow",
        }) );
        setup();
}
