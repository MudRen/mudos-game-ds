#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
        set_name(HIW"大蛇手甲"NOR ,({ "snake hands","hands" }) );
        set("long","一雙由八歧大蛇的皮所製成的手甲, 隱隱發出淡淡的白光。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "fur");
        set("unit", "雙" );
        set("value",20000);
        set("armor_prop/armor", 8);
        set("armor_prop/con",8);
        set("armor_prop/str",8);
        }
        setup();
}
