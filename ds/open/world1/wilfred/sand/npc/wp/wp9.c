#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIW""BLK"���s��"NOR,({"dragon claw","claw"}) );
  set("long","�@�����ª��s���A��h�L�L�z�X�@������C\n");
  set_weight(3000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit","��");
    set("value",12000);
  set("material","leather");
    set("volume",3);
    set("wield_msg","$N�˳�$n"NOR"��Z���A�P��@�ѱ��N��W���Y�C\n" NOR);
  }
  set("limit_skill",70);
  set("weapon_prop/str",2);
  set("weapon_prop/dex",-2);
  set("weapon_prop/hit",10);
  set("beast_weapon_prop/damage",62);
  set("beast_weapon_prop/hit",10);
  init_fist(61);
  setup();
}
