
#include <weapon.h>
// �ݸ˳Ʀb lv64 �H�W��mob
inherit WHIP;
void create()
{
  set_name("���D�@",({"golden whip","golden","whip"}));
set_weight(32000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long","�o�O�@�����D�@,���g�b�Ŭr�ХX�{�L�C\n");
    set("value",4140);		// value = damage*5 + damage*5*0.15
    set("material", "leather");
    set("wield_msg","$N�q�y�����X�@��$n\n");
//  set("weapon_prop/parry",2);
    set("weapon_prop/attack",4);
    set("unequip_msg", "$N�⤤��$n���^�ܸy�ڡC\n");
set("whip",180);
    init_whip(720);	// damage = skill*n
  }

  setup();

}
