
#include <ansi.h>
#include <weapon.h>
inherit HAMMER;

void create()
{
  set_name("�_���K��",({"bone hammer","hammer"}) );
  set("long","�@�K���j���K�ΡA�M�O�y�z�̡A�ڥ��s���������_�ӡC\n");
  set_weight(30000);
  if (clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit","�K");
    set("volume", 4);
    set("value", 3000);
  }
  init_hammer(50);
  set("material","iron");
  set("weapon_prop/con", 1);
  set("weapon_prop/str", 1);
  setup();        
}
