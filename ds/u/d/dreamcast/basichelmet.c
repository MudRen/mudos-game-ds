#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
        set_name(HIM"夢"HIC"幻"HIW"頭盔"NOR ,({ "dreamcast helmet","helmet" }) );
        set("long","這是一頂DREAMCAST專用的頭盔。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(12000);
        set("material", "iron");
        set("unit", "頂" );
       set("value",50000);
        set("limit_str",8);
     set("armor_prop/armor",9);
        set("armor_prop/int",3);
                set("volume",3);
        set("armor_prop/dex",-1);
        }
        setup();
}

