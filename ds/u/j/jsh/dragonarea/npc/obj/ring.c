#include <ansi.h> 
#include <armor.h>
inherit FINGER;

void create() 
{
        set_name(HIG"指"HIW"般"HIY"龍"NOR,({ "finger dragon","finger","dragon" }) );
        set("long","一顆龍型圖案的戒指，似乎有特別的功\效。\n");
        set_weight(8000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
     set("volume",5);
         set("material","gem");
                set("unit", "件" );
       set("value",2000);
set("armor_prop/armor", 4); 
set("armor_prop/dodge", 2);
set("armor_prop/ap", 100);
                
        }
        setup();
}

