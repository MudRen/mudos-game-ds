#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(WHT"鐵項鍊"NOR,({ "iron neck","neck" }) );
        set("long","這是一件完全用鐵打造的盾牌[0;1;36m�[1mA[0m防禦力高[0;1;36m�[1mC[0m\n");
        set_weight(200);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
set("volume",5);
         set("material","steel");
                set("unit", "件" );
       set("value",200);
                set("armor_prop/armor", 5);
                
        }
        setup();
}

