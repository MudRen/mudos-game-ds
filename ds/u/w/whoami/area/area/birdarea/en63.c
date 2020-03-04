#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG 
走到泥沼區的分歧小路, 雖然四周長著奇怪的植物, 但已經
別無選擇, 也只好硬著頭皮往前走. 可是你感覺到兩旁的花兒好
像慢慢張開它的花朵, 隨時一口把你吃掉!
LONG);
 set("exits",(["southwest":__DIR__"en67",
               "southeast":__DIR__"en69",
               ]));
 set("objects",([__DIR__"npc/flower" : 4+random(4),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

