#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
        set_name( GRN "深綠皮鞋"  NOR ,({ "deep green shoes" , "shoes" }) );
        set("long","這是一雙不知道什麼皮做的深綠色皮鞋。\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "雙" );
                set("value" ,1);
                set("material","gold");
             }
                set("armor_prop/armor", 6);
                set("armor_prop/shield", 4);
                set("armor_prop/dodge", 20);
                set("armor_prop/dex",5);
        setup();
}

int query_autoload() { return 1; }

