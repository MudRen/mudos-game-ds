#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIR"�a���j��"NOR ,({ "hell holds","holds" }) );
        set("long","�@���g���A�媺��M,�E�ױ��ͮɳ��n�ݵۥ��C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(500);
        set("material", "linen");
        set("unit", "��" );
        set("value",300);
        }
         set("armor_prop/armor", 10);
         set("armor_prop/shield", 2);
         set("armor_prop/int", -1);
         set("armor_prop/str", 2);
        setup();
}


