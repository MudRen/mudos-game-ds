#include <weapon.h>
inherit BLADE;
void create()
{
  set_name( "�����M" , ({ "steel blade","blade" }) );
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�@��p����ꪺ�����M�C\n");
    set("material", "iron");
    set("value", 1500);
    set("volume",1);
  }
  init_blade(30);
  setup();
}

