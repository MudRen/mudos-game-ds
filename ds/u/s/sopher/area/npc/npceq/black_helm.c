#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(GRN"黑魔巨盔"NOR ,({ "black helm" , "helm"  }) );
        set("long","這是一個相當厚重的深黑色魔盔。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "helmet");
        set("unit", "頂" );
         set("value",60);
set("armor_prop/armor",10);
        }
        setup();
} 
