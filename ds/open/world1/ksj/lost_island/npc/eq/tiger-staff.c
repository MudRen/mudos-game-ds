#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
  set_name(HIY"�갩����"HIR"(S)"NOR,({"tiger staff","staff"}));
  set("long",@LONG
�C�����ꪺ�L���s���������A���@����K�󬰰�w�C
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "��");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_staff(48);
  setup();
}

int query_autoload() { return 1; }
