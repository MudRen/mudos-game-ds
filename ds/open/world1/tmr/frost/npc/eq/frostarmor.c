#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HBK"�H�����Z"NOR ,({ "frost armor","armor" }) );
        set("long","�H�����[�D�Ҭ��������Z�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(38000);
                set("unit","��");
                set("value",10000);
                set("volume",3);
                set("armor_prop/armor", 30);
                set("armor_prop/str", 1);
                set("limit_con",20);
        }
        setup();
}
