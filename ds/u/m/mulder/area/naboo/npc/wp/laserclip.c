#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

	set_name(HIC"激光能源夾"NOR,({"laster clip","laser","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個激光能源夾, 每一組激光能源夾出廠時都裝有20束激光。裝填指令:(reload clip)\n");
        set("value", 1200);
        set_weight(500);
        set("amount",20);                
        set("bullet/damage",30);        
        set("bullet/unit","束");        
        set("bullet/name","激光");     
        set("type","energy");      
        }
        setup();
}   