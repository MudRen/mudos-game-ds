#include <weapon.h>
inherit BLADE;
void create()
{
  set_name( "���F�M" , ({ "sand blade","blade" }) );
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�Ѷ��F�K�s�������F�M�A�O���a�s��R�Τ��Z���C\n");
    set("material", "iron");
    set("value",1200);
    set("volume",1);
  }
  init_blade(25);
  setup();
}