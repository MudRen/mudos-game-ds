#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("袈裟" ,({ "buddha's cloth","cloth" }) );
        set("long","這是和尚平時穿著的衣服。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1200);
        set("material", "cloth");
        set("unit", "件" );
        set("value",1200);
        }
        set("armor_prop/armor", 6);
        set("armor_prop/dodge", 6);
        setup();
}
