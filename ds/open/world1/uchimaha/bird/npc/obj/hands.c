#include <ansi.h>
#include <armor.h>
inherit WRISTS;
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
        set("value",10000);
        set("armor_prop/armor", 8);
        set("limit_str",8);
        set("armor_prop/dex",1);
        set("armor_prop/int",2);
        }
        setup();
}
