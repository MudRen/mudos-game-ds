#include <ansi.h>
#include <weapon.h>
// mob_lv>=74
inherit BLADE;
void create()
{
  set_name(CYN"�Ť믫�M"NOR,({"moon blade","moon","blade"}));
set_weight(58000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","�o�O�Ŭr�Ъ�����--�Ť믫�M,�ݰ_�Ӭ۷��W�Q,\n"+
               "�۶Ǧb�]�߮ɬO���¤O�̱j���ɭԡC\n");
    set("value",8085);
    set("material", "blacksteel");
    set("wield_msg","$N�q�I��ޥX�@��$n\n");
//  set("weapon_prop/parry",2);
    set("weapon_prop/attack",4);
    set("unequip_msg", "$N�⤤��$n��J�I��C\n");
	set("blade",210);
    init_blade(1470);	//�\���O
  }

  setup();

}
