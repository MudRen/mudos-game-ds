#include <weapon.h>
inherit BLADE;
void create()
{
    set_name( "�j�M" , ({ "broad blade","blade" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�@��p�����j�M�C\n");
    set("material", "iron");
    set("value", 500);
    set("volume",1);
  }
  init_blade(20);
  setup();
}

