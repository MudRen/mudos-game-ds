#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(HIB "�]�P�[���u" NOR,({ "devil-boots","boots" }) );
        set("long",
"�o�O�@���D�`��o���[���u�A���F�n�ݤ]�����D������\�ΤF�C\n"
);
        set_weight(900);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",25);
        set("limit_level",20);
        set("value",100);
        set("armor_prop/armor",1);
        set("armor_prop/dex", 1);
        set("armor_prop/int", -3);
        }
        setup();
}
