#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
        set_name(HIB "�]�P�ԯ���" NOR,({ "devil-helmet","helmet" }) );
        set("long",
"�o�O�@���ǻ������Y���A�Ϊ����O�����Y�A�����D�q����a��һs�y�C\n"
);
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",10);
        set("armor_prop/str", 1);
        set("armor_prop/con", -3);
        }
        setup();
}
