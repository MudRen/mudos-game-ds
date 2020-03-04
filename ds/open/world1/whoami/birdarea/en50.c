#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"東北"NOR"澤林");
 set("long",@LONG 
你慢慢的走到東北澤林的深處，隨著兩旁的樹木漸漸高大,
這裡的光線也越來越微弱, 慢慢地, 你發現前面將是森林沼澤
區, 越是往前進, 濃濃的沼氣更是讓氣氛顯得詭異.
LONG);
 set("exits",(["west":__DIR__"en51",
               "northeast":__DIR__"en49",
               ]));
 
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

