#include <weapon.h>
inherit FORK;
void create()
{
  set_name( "���F�j" , ({ "sand pike","pike" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�Ѷ��F�K�s�������F�j�A�O��a�s��R�Τ��Z���C\n");
    set("material", "iron");
    set("value",1500);
    set("volume",1);
  }
  init_fork(29);
  setup();
}