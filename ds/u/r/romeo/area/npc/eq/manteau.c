#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
        set_name(HIB "�]�P�ܭ�" NOR,({ "devil-manteau","manteau" }) );
        set("long",
"�o�O�@�󨾤����ܭ��A�I����¸�W�@���r��ݰ_�Ӯ�դQ��\n"
);
        set_weight(2000);
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
        set("armor_prop/con", 1);
        }
        setup();
}
