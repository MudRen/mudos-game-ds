#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
        set_name(HIW"�j�D���"NOR ,({ "snake hands","hands" }) );
        set("long","�@���ѤK�[�j�D���֩һs�������, �����o�X�H�H���ե��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(1000);
        set("material", "fur");
        set("unit", "��" );
        set("value",20000);
        set("armor_prop/armor", 8);
        set("armor_prop/con",8);
        set("armor_prop/str",8);
        }
        setup();
}
