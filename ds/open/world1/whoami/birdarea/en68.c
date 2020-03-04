#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG 
在這一大片泥沼地裡, 你突然發現一小塊的池塘, 冒出陣陣
的泉水, 使你馬上低下頭去暢飲一番, 清涼的氣息讓人神清氣爽
. 池塘邊的千年巨蛙正在不停呱呱叫著, 帶來一股生氣.
LONG);
 set("exits",(["west":__DIR__"en67",
               "southeast":__DIR__"en71",
               ]));
 set("objects",([__DIR__"npc/tfrog" : 3+random(3),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

