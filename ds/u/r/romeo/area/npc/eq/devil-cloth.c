#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIB "魔星蠶絲衣" NOR,({ "devil-cloth","cloth" }) );
        set("long",
"這是一件由金蠶絲所製成的衣服，是一件珍品。\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "件" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/str", 1);
        }
        setup();
}
