#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIR"炎龍魔盔"NOR ,({ "fire helm" , "helm"  }) );
        set("long","這是一個相當厚重的火紅色頭盔。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "helmet");
        set("unit", "頂" );
         set("value",60);
        set("armor_prop/armor", 30);
        }
        setup();
} 
