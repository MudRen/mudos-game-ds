#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
  set_name(HIY"������@"HIR"(S)"NOR,({"tiger whip","whip"}));
  set("long",@LONG
�C�����ꪺ���ڻs�������@�A�j���ӭ@�ΡC
LONG
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "��");        
    set("value",100000);
    set("volume",3);
    set("weapon_prop/str",1);         
    set("material","fur");       
  }        
  init_whip(43);
  setup();
}

int query_autoload() { return 1; }
