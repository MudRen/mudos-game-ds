#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIY"�j����"NOR,({"gold coin","coin"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�j�N�s�@�������A�«׵y�t�F�I�C");
    set("unit", "��");
    set("volume",1);
    set("value",5000);
  }
  setup();
}
