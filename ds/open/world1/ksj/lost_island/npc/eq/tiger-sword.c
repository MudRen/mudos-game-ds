#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
  set_name(HIY"����C"HIR"(S)"NOR,({"tiger sword","sword"}));
  set("long",@LONG
�C�����ꪺ�k�����s�������C�A���@����C�����ˤO�C
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_dex",20);
    set("limit_skill",60);
    set("unit", "��");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_sword(45);
  setup();
}

int query_autoload() { return 1; }
