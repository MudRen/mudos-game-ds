#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(HIY "金黃羽盔" NOR,({ "gold helmet","helmet"}) );
        set("long","金黃羽盔由純黃金打造而成的頭盔，看來價值不菲。\n");
        set_weight(2400);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        	set("material", "gold");
        	set("unit","頂");
        }
        set("value",3300);
        set("limit_lv",20);
        set("armor_prop/armor",15);
        set("armor_prop/str",1);
        set("armor_prop/dex",-1);
        setup();
        set("volume",3);
}
