#include <ansi.h>
#include <armor.h>
inherit WRISTS;
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
        set("value",10000);
        set("armor_prop/armor", 8);
        set("limit_str",8);
        set("armor_prop/dex",1);
        set("armor_prop/int",2);
        }
        setup();
}
