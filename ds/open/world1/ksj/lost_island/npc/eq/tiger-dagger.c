#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(HIY"����P��"HIR"(S)"NOR,({"tiger dagger","dagger"}));
  set("long",@LONG
�C�����ꪺ�����s�����P���A�۷�y�U�C
LONG
);
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "��");        
    set("value",100000);
    set("volume",2);
    set("material","steel");       
  }        
  set("weapon_prop/str",1);         
  init_dagger(37);
  setup();
}

int query_autoload() { return 1; }

