#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"�B���n��"NOR ,({ "frost-troll fur","fur" }) );
  set("long",@LONG
�o�O�@���q�_��j�˪L���B�����]���o���n��C
LONG
);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 1000);
  }

  setup();
}

