#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
        set_name(HIY"爍千面"NOR,({"faceoff mask","mask"}) );
        set("long",@LONG
一個閃閃發光的面具，散發著不屬於這個世界的光輝....
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
                set("unit", "個");       
                set("value",2000);          
                set("volume", 2);                       
                set("material", "gold");   
        }
        set("armor_prop/armor",1);       
        set("armor_prop/int",1);
        setup();
}

