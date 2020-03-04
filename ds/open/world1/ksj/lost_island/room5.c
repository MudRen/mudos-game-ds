#include <ansi.h>
inherit MOBROOM;

void create()
{
        set("short", "遺世島－"HIG"獸原"NOR);
        set("long", @LONG
這裡是一望無際的大草原，長滿及膝的青翠雜草，還有許多不知
名的花草植物，草原上飛舞著七彩蝴蝶和奇異的昆蟲，遠遠可以看到
珍禽異獸在草原中奔跑覓食，放眼望去渺無人煙，儼然是動物的世外
桃源，東邊和南邊是高聳入雲的山壁。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"room6",
  "north" : __DIR__"room10",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        set("chance",25);
	set("mob_amount", 2);
        set("mob_max",3);
        set("mob_object",({  
            __DIR__"npc/thunder-bird",
        }) );
        setup();
}
