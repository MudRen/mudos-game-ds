#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("虎皮大衣" ,({ "tiger cloth" , "cloth" }) );
        set("long","這件衣服給人感覺相當的有氣派, 霸氣十足, 不過通常\n"
                   "只有類似山寨主的人士才會穿這種東西。\n");
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value" ,1500);
                set("material","fur");
        }
        set("armor_prop/armor", 6);
        set("armor_prop/shield", 4); 
        setup();
}
