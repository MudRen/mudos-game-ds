//u/c/chiaa/obj/eq/leading_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(GRN"��"HIB"�N"HIR"��"HIC"�g"NOR,({"leading sword","sword"}));
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","��");
      set("long","�o�O�@���P�D�H�߷N�۳q���C,�u�n�వ��H�C�X�@,
          �Ʀܯല�o�X�Q�����쪺�¤O�C\n");
      set_weight(7000);
      set("value",20000);
      set("material","wolfram");  //���� ��
      set("wield_msg", "$n�H���֪��t�ױq�A�I�W���X,�C�����@�T,
          ���b�A���e�����B�C\n");
       set("unwield_msg", "$N�N�⤤��$n���J�I�W���C�T�C\n");

   }
        init_sword(511);     //�Z�������O
 set("weapon_prop/sword",35);        //�[ enable �ޯ�35
 set("weapon_prop/parry",20);        //�[enable  �ޯ�20
setup();
}
