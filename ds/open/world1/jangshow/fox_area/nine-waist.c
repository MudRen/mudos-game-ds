#include <armor.h>
#include <ansi.h>
inherit WAIST;
 
void create()
{
        set_name(HIW"九尾銀束"NOR,({ "nine-fox waist","waist" }) );
        set("long",HIW"九尾妖狐的尾巴，可以捲成一圈，當成腰帶，實用性相當高。\n"NOR);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("volume",5);
        set("material","golden");
        set("unit", "件" );
        set("value",10000); 
        }     
        set("armor_prop/armor", 5);  
        set("armor_prop/str",2);
        set("armor_prop/int",2);
        set("armor_prop/bar",-1);
        setup();
}
