#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(HIY"����M"NOR,({"tiger-tooth blade","blade"}));
  set("long",@LONG
�C�����ꪺ�������s�����j�M�A���ˤO�����C
LONG
);
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "��");
    set("weapon_prop/str",1);        
    set("value", 100000);
    set("volume",3);        
    set("material","steel");       
  }        
  init_blade(47);
  setup();
}

int query_autoload() { return 1; }

