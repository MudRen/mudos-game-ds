#include <armor.h>
#include <ansi.h>
inherit SSERVER;
inherit NECK;

void create()
{
        set_name(HIB "�]�P����" NOR,({ "devil-necklace","necklace" }) );
        set("long",
"�o�O�@���ݦ����Z������A�������S�X�@���������C\n"
);
        set_weight(500);
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
        set("armor_prop/str", 1);
        set("armor_prop/dex", -1);
        }
        setup();
}

