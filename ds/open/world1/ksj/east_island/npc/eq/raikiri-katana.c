#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
  set_name(HIC"�p��"NOR,({"raikiri katana","katana"}));
  set("long",@LONG
�@��}�G�����M�A�ǻ�����_�p�q�㦳�I����B����O�C
LONG);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",60);
    set("unit", "��");
    set("weapon_prop/str",2);        
    set("value",5500);
    set("volume",3);        
    set("material","blacksteel");       
  }        
  init_blade(51,TWO_HANDED);
  setup();
}
