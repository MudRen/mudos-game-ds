//�x�W�C���Ĥ@������ �Ĥ��W windwalk ���~ -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
          set_name(HIC "�����H��" NOR ,({ "wind-moon leggings","leggings"}) );
          set("long",@long
�x�W�C���Ĥ@������ �Ĥ��W windwalk ���~�C
    �o�O�μs�H�c�����}�@���_--����--�ҥ��y�Ӧ����A
�]���N�����@�몺���A�P�����쭫�q�A�ӥB����O�q���L�k�˥����@�C
long
);
          set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gem");
                set("unit", "��" );
                set("value",1000);
                set("valme",3);
                set("no_sac",1);
		set("wear_msg","$N��W�F�����H�ҡA�P�����L�����ʧ�[�����t�ۦb�F�C\n");
		set("remove_msg","$N��U�F�����H�ҡA���L�S��_��쥻���t�סC\n");
                set("armor_prop/armor", 5);
        }
        setup();
}

int query_autoload() { return 1; }
