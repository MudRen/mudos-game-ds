#include <weapon.h>
inherit BLADE;
void create()
{
  set_name( "�x�M" , ({ "military blade","blade" }) );
  set_weight(2600);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�Ѻ���s�����x�M�A�D�O���x���Τ@�t���C\n");
    set("material", "iron");
    set("value",1800);
    set("volume",1);
  }
  init_blade(37);
  setup();
}
