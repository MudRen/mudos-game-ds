#include <ansi.h> 
inherit ROOM; 
void create() 
{
        set("short", "水寒星洞");
        set("long", @LONG
河水滲入土壤，重力將水往下拉，直到水充滿土壤與底層岩石
，使得這裡的土壤到達飽和狀態，所以這裡到處都是爛泥碎石，想
要走路都很難。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room5",  
  "south" : __DIR__"room3",]));
        set("no_clean_up", 0);

        setup();
}

