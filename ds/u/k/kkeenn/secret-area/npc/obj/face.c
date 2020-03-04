#include <armor.h>
inherit MASK;
void create()
{
        set_name("念幻之臉", ({ "psychical face","face" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一張不知名的面罩。\n");
                set("unit", "張");
                set("material", "sheet");
                set("no_sell",1);
                set("no_sac",1);
                set("value",800);          
                set("wear_msg", "$N的思想突然一個錯誤, 從$N的臉上似乎浮上一張$n\n");
                set("unequip_msg", "$N努力克制歪念, 終於讓$n消失了。\n");
           }
        set("armor_prop/dodge",4);
        set("armor_prop/armor",2);
        setup();
}

