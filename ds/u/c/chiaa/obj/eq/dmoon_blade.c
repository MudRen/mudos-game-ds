//u/c/chiaa/obj/eq/dmoon_blade.c

#include <weapon.h>           //�n��include �Z�������
#include <ansi.h>             //�w�q��X
inherit BLADE;

void create()
{
   set_name( CYN "�X" YEL "��" WHT "�M" NOR, ({"dmoon blade","blade"}));
        set_weight(7777);
        if( clonep() )     //�t�Ϊ��Ѽ�..�]�w....
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o�O�ǻ������]�M,�����L���H�����n
                    �o��M���{�P,�~��r�����C\n");
                set("value",6000);
                set("limit_int",25);  //�����25
                set("material", "steel");  //���� ��
                set("wield_msg", "$N��X�@��ô�b�y����$n���b�⤤,
                    �|�P����^�y�ɤ@�I�C\n");
                set("unwield_msg", "$N�N�⤤��$n���J�y�����M�T�C\n");
        }
        init_blade(333);
 set("weapon_prop/blade", 20);       //�[ enable �ޯ�10
 set("weapon_prop/force",10);        //�[enable �ޯ� 10
        setup();
}
