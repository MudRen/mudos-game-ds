inherit ITEM;
#include <ansi.h>

void create()
{
  set_name("�\\��K", ({ "holly"}));
  set("long",@LONG
�Ѿ��ѩҳy�A�i�������V�F���X���q(fly)�C
LONG);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 1000);
    set("no_sell", 1);
    set("no_sac", 1);
  }
  setup();
}

