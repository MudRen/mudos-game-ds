#include <ansi.h>
inherit ITEM;
inherit F_BULLET;
void create()
{

set_name(HIW"永恆之矢"NOR,({"forever bolt","bolt"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "隻");
        set("long",HIW"世界之數所製之箭，殺傷力強大。\n"NOR);
        }
    set("value", 8000);
    set_weight(2000);
    set("amount",30);                
    set("bullet/damage",200+random(161));        
    set("bullet/unit","隻");        
    set("bullet/name",HIW"永恆之矢"NOR);      
    set("type","small");            
    setup();
}
