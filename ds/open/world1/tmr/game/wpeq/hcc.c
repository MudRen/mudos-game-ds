//�x�W�C���Ĥ@������ �ĤG�W hcc ���~ -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIB "�s���Z" NOR ,({ "dragon king armor","armor"}) );
        set("long",@long
�x�W�C���Ĥ@������ �ĤG�W hcc ���~�C
  �o�O�@��q�j�N�԰�ӳ��ҫ����X�Ӫ��_�ҡC
long
);
            set_weight(10000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "��" );
                set("value",1000);
                set("valme",4);
                set("no_sac",1);
                set("armor_prop/armor", 10);
		set("wear_msg","$N��W�@���s���Z,�y��ı�o�ۤv�ϩ��@���s�몺���Y�C\n");
        }
        setup();
}

int query_autoload() { return 1; }
