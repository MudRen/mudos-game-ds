#include <weapon.h>
inherit SWORD;
void create()
{
  set_name( "���F�C" , ({ "sand sword","sword" }) );
  set_weight(1500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�o�O�Ѷ��F�K�s�������F�C�A�O��a�s��R�Τ��Z���C\n");
    set("material", "iron");
    set("value",1100);
    set("volume",1);
  }
  init_sword(23);
  setup();
}