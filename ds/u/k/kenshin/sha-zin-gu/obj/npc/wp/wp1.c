#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIW"���"NOR,({"sAnG Li","sang","li"}) );
  set("long","�_�L����M�ҫ������@�Z���C\n");
  set_weight(3300);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit","��");
    set("value",10000);
    set("material","leather");
    set("volume",3);
    set("wield_msg",HIG"$N�˳ư_���Z���A�K�Pı�X�M������q���ƥX�C\n" NOR);
  }
  set("limit_skill",70);
  set("weapon_prop/str",3);
  set("weapon_prop/dex",-1); 
  set("weapon_prop/sou", 1);    init_fist(68);
  setup();
}

