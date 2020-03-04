#include <ansi.h>
#include <weapon.h>
inherit FORK;

void create()
{
  set_name(HIG"�f�M��"NOR, ({ "dragonfly-cut pike","pike" }) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_str",30);
    set("limit_skill",25);
    set("limit_lv",30);
    set("unit", "��");
    set("long", "�ڻ��f���@���b�j�y�W�N�Q������b�����A�G�o���W�A�O�����o���n\n"
                "�j�C\n");
    set("value",10000);
    set("volume",5);
    set("material","blacksteel");
  }
  set("weapon_prop/hit",5);
  init_fork(60,TWO_HANDED);
  setup();
}
