#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIY"��糥�"NOR,({"hedgehog skin","skin"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","��糪��~�֡A�O�Ψӻs���W���֥Ҫ��n���ơC");
    set("value",500);
  }
  setup();
}