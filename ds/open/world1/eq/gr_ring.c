#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name("大地指環",({"ground ring","ring"}) );
        set("long",@LONG
漆黑的鐵環，上面鑲著一顆藍寶石，發出淡淡的光芒。
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",20);
                set("unit", "只");       
                set("value",1200);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("armor_prop/armor",2);       
        set("armor_prop/str",1);
        set("armor_prop/con",1);
        setup();
}


