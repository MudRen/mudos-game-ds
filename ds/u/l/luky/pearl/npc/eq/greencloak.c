#include <ansi.h>

#include <armor.h>

inherit CLOAK;

void create()
{
set_name("�񴹩ܭ�",({"green cloak","cloak"}) );
set("long","�@��Q�����R���`���ܭ��C�����¸�F�X�������b�W���C\n");
set_weight(3400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material","cloth");
set("unit", "��");
set("value",5473);
//set("armor_prop/armor",33);
set("armor_prop/dex",1);
set("limit_lv",51);
        }
        setup();
}
