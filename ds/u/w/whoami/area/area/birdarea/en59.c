#include <ansi.h>
#include <room.h> 
inherit ROOM;
inherit __DIR__"muder.c";
void create()
{
 set("short",HIW"東北"NOR"澤林"NOR"－"YEL"泥沼區"NOR);
 set("long",@LONG
你毫無頭緒的到處亂走, 發覺這裡是泥沼區的邊緣. 但此處
意外的安靜, 反而讓人沒有安心的感覺, 突然背脊一陣陰風吹過
, 讓你全身雞皮疙瘩都起來了.
LONG);
 set("exits",(["west":__DIR__"en58",
               "northwest":__DIR__"en54",
               "south":__DIR__"en64",
               ]));
 set("objects",([__DIR__"npc/animal" : 4+random(4),
               ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

