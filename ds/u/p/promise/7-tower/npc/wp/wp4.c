#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(NOR+GRN"����"HIW"���b�M"NOR , ({ "nether six blade","blade" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "���򲱶Ǥw�[�����������������b�۩ҫ����Q�M�A���M�����F���A�A�X�F�����H�ϥΡC\n"NOR);
    
    set("material", "sliver");
    set("value",10000);
    set("weapon_prop/str",-2);
    set("weapon_prop/dex",2);
    set("weapon_prop/int",1);
    set("weapon_prop/con",-2); 
    set("limit_lv",40);
    set("limit_dex",50);
    set("limit_int",50);  
  }
    set("wield_msg",HIC"$N���_�������b�M��A���P�몺�F���L��I�I\n"NOR);
    set("unwield_msg", CYN"$N��U�F���M��A�K���b�F���I�I\n"NOR);
  init_blade(63);
  setup();

}


