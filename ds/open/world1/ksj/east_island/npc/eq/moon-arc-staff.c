#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create() 
{
  set_name("�����",({"moon-arc staff","staff"}));
  set("long",@LONG
���Y��������K�b�������C
LONG
);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",30);
    set("unit", "��");        
    set("value",2000);
    set("volume",5);
    set("weapon_prop/str",1);         
    set("material","steel");       
  }        
  init_staff(50);
  setup();
}
