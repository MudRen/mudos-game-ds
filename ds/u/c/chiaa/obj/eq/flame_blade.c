#include <weapon.h>           //�n��include �Z�������
#include <ansi.h>             //�w�q��X
inherit BLADE;

void create()
{
 set_name( HIY "�K" YEL "�" NOR , ({"flame blade","blade"}));
        set_weight(5678);
        if( clonep() )     //�t�Ϊ��Ѽ�..�]�w....
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","�o��M�P�@��p�ꪺ�M�j���ۦP,�M������,
                 ���]�۷��W�Q�C\n");
      set("value",5555);
      set("material", "steel");  //���� ��
      set("wield_msg", "$n�q�A�y��«�X,�b�Ѫ���F�X��,
                    ����$N�⤤�C\n");//$N���a$n�Z��
      set("unwield_msg", "$N�N�⤤��$n��F�X�U�W�����J�M�T�C\n");
        }
        init_blade(456);
 set("weapon_prop/blade",30);       //�[enable�ޯ�30
 set("weapon_prop/force",20);        //�[enable�ޯ�20
        setup();
}
