#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW+BLK"��"HIY"��"NOR"�K��", ({ "sun-moon iron stone", "stone" }));
  set("long",@LONG
�@�����Z�����Y�A�u�����D�ַ|�Q�n�o�تF��E
LONG);
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 0);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}


