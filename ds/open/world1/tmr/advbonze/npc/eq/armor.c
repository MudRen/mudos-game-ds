#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("ù�~�@��" ,({ "luo-han armor","armor" }) );
        set("long",@LONG
�@�󷥬��p�����@�ҡA���Pı�o�X�ӫD�`����A�b���m�ĤH��������
�@�w���\�ġC�b�@�ҤU�\ô�F�X�������u�A�@�ۭˤ]ı�o���[�C
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(15000);
                set("material", "gold");
                set("unit", "��");
                set("value",3000);
                set("volume",3);
        }
                 set("armor_prop/armor", 24);
                 set("limit_con",20);
                 set("limit_str",20);
                 set("armor_prop/con", 2);
                 set("armor_prop/str", 2);
        setup();
}
