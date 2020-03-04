#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG
經過長途跋涉, 你似乎已經消耗了不少體力, 於是找了一個
比較安全的樹下休息著, 但週遭的氣氛還是讓你隨時保持警戒心
. 突然發現頭上有幾隻長相怪異的蜜蜂, 不由得拔腿就跑..
LONG);
 set("exits",(["east":__DIR__"en67",
               "southwest":__DIR__"en70",
               ]));
 set("objects",([__DIR__"npc/bee" : 3+random(3),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

