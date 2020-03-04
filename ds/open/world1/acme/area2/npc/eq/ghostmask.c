#include <armor.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit MASK;

void create()
{
        set_name(HIW"冥王鬼面"NOR,({ "ghost mask","mask" }) );
        set("long","這個面具是幽冥地窖的冥王觴炯平時不離『面』之物，\n"
                   "看起來十分猙獰可怖，但不知有什麼作用。\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","張");
        set("value",100);
        set("limit_lv",25);
        set("limit_int",33);
        set("replica_ob",__DIR__"mask");
        }
        set("armor_prop/int",2);
        set("armor_prop/armor",2);
        set("armor_prop/wit",1);
        set("armor_prop/bio",-1);
        setup();
}
