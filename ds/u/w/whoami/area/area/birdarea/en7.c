#include <ansi.h>
inherit MOBROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");

 set("long",@LONG
你現在來到一處樹木林立的地方, 一陣陣的風撲面而來, 樹
上有一堆的蟬正在那嘰嘰的叫著, 好似歡迎你來到這裡, 這裡往
北長年被白霧遮蔽, 鮮少有旅人進入而全身而退的.
LONG
    );
 
 set("exits",(["north":__DIR__"en8",
               "east":__DIR__"en18",
               "southwest":__DIR__"en6",
     ]));
 
 set("no_clean_up", 0);
 set("outdoors","land");
 set("chance",80);
        set("mob_amount",3);    
        set("mob_max",12);
        set("mob_object",({     
            __DIR__"npc/chan",
        }) );
        set("no_clean_up", 0);
        set("outdoors","forest");
 setup();
}

