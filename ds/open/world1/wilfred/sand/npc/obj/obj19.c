#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIY"���Ȱ]�_"NOR,({"gold"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","����᪺���l�Υժ�᪺�Ȥl�A�u�O�H���H�R�C");
    set("value",10000);
  }
  setup();
}
