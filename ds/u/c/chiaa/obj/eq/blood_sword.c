//u/c/chiaa/obj/eq/blood_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIW"�g"HIR"��"HIC"�B"HIM"��"NOR,({"blood sword","sword"}) );
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","��");
      set("long","�ǻD���̾W�Q���C,�����C���H�L��,
       �C�����o�X�@�ѲH�H����{���C\n");
      set_weight(4000);
      set("value",30000);
      set("material","titanium");  //���� �g
      set("wield_msg", "$N�w�w���N$n��X,�@�ѩѮ��H�Y�q�C���Ǩ�$N���W,
                    �|�P���Ů��j���ۦ�{���C\n");
       set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");

   }
        init_sword(777);     //�Z�������O
 set("weapon_prop/sword",40);        //�[ enable �ޯ�40
 set("weapon_prop/parry",30);        //�[enable  �ޯ�30
setup();
}
