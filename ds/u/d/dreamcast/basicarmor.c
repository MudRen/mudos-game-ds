#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIM"幻"BLK"影"HIW"龍"HIC"甲"NOR,({"dreamcast armor","armor"}) );
        set("long",@LONG
這就是Dreamcast身上穿的護甲，是Dreamcast在盤古開天時，
把影龍殺了，取它的鱗所做的，相當堅硬•

LONG
);
        set_weight(5000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("armor_prop/armor", 50);
         set("armor_prop/str",2);
                set("unit", "件");       
         set("armor_prop/con",2);
         set("armor_prop/dex",-2);
                set("value",100);          
                set("volume", 3);                       
                set("material", "air");   
        }
        setup();
}

