#include <armor.h>
#include <ansi.h>
inherit ARMOR;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"石盔"NOR,({"stone-armor","armor"}) );
        set("long","這是一件石做的防具，是古代遺留下來的其中一件神器。\n");
        set_weight(12500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","副");
set("value",5000);
set("material","rock");
set("armor_prop/armor", 30);
        }
        setup();
}
