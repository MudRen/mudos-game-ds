#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIC"終結能源夾"NOR,({"sun clip","sun","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","一個終結能源夾, 每一組終結能源夾出廠時都裝有100組能源。裝填指令:(reload clip)\n");
        }
        set("value", 10000);
        set_weight(10000);
        set("amount",100);                
        set("bullet/damage",10000);        
        set("bullet/unit","組");        
        set("bullet/name","能源");     
        set("type","enegry");      
        setup();
}