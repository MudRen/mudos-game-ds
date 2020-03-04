#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG
走到泥沼區深處, 這裡反而沒有一開始的恐怖，沼澤地所帶
有的沼氣, 也因為待在此處時間久了, 逐漸克服. 走著走著，發
現幾隻蜻蜓在天空飛舞著, 但這裡的蜻蜓似乎特別的不同.
LONG);
 set("exits",(["north":__DIR__"en57",
               "south":__DIR__"en67",
               ]));
 set("objects",([__DIR__"npc/fly" : 4+random(4),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

