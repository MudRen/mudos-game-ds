#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"羽鞋"NOR, ({ "feather boots","boots" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這雙鞋子上面夾滿了羽毛, 看起來非常溫暖.\n");
                set("unit", "雙");
                set("value",300);
                set("material", "silk");
                set("armor_prop/armor", 5);
        }
       setup();
}
