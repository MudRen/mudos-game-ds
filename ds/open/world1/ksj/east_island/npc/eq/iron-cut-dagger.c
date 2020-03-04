#include <ansi.h>
#include <weapon.h>
inherit DAGGER;

void create()
{
  set_name(CYN"�K�H��"NOR,({"iron-cut dagger","dagger"}));
  set("long",@LONG
�H�s�@�ӤM���覡�s�����u�M�A�۷�U�Q�ӭ@�άƦܥi�H�d�K�C
LONG);
  set_weight(1100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",25);
    set("unit", "��");        
    set("value",6000);
    set("volume",2);
    set("material","blacksteel");       
  }        
  set("backstab_bonus",40);
  init_dagger(40);
  setup();
}
