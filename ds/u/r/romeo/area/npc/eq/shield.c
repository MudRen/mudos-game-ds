#include <armor.h>
#include <ansi.h>
inherit SHIELD;

void create()
{
        set_name("�p���^��",({ "lighting-unicorn-shield","shield" }) );
        set("long",
"�o�O���p�����޵P�A������F�^ˤ�����A��X�����N��F���q
�A��Ǫ��p���h�H�x�R���ĤH����q�I�C\n"
);
        set_weight(7000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
        set("material", "leather");
        set("unit", "��" );
        set("limit_con",20);
        set("limit_level",15);
        set("value",100);
        set("armor_prop/armor",5);
        set("armor_prop/dex", -1);
        }
        setup();
}

