//�x�W�C���Ĥ@������ �Ĥ��W windwalk ���~ -by tmr- 2000/5/20

#include <ansi.h>
#include <armor.h>
inherit PANTS;

void create()
{
          set_name(HIC "�B���F��" NOR ,({ "ice-moon skirt","skirt"}) );
          set("long",@long
�x�W�C���Ĥ@������ �Ĥ��W windwalk ���~�C
    �o�O���d�~�B���ҦR�����b�l������ؤ���ҽs´�Ӧ��A
�]�����F�Q���j���B�������I���~�ٱa���������F��C
long
);
          set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "fur");
                set("unit", "��" );
                set("value",1000);
                set("valme",3);
                set("no_sac",1);
		set("wear_msg","$N��W�F�B���F�¡A�P��u��b�U�b�����B���[���Z�F�C\n");
		set("remove_msg","$N��U�F�B���F�¡A�u�𪺹B��S��_�쥭�`���Pı�C\n");
                set("armor_prop/armor", 5);
        }
        setup();
}

int query_autoload() { return 1; }
