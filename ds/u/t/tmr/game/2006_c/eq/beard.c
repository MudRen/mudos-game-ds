#include <armor.h>
#include <ansi.h>
inherit MASK;

void create()
{
        set_name(HIR"聖誕"HIW"大白鬍"NOR,({ "christmas beard","beard" }) );
        set("long",@LONG
這是一撮白色的大鬍子，不知道為什麼，你就是想要戴上它。 
LONG);
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material","fur");
        set("unit","撮");
        set("value",1);
        }
        set("armor_prop/armor",1);
        setup();
}

