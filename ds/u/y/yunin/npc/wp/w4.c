

#include <ansi.h>

#include <weapon.h>

inherit FORK;

void create()

{

  set_name(HIG"�ѯŤѺj"NOR,({ "level C spear","spear" }) );

  set_weight(1500);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "��");

    set("long", "�o�O�u�í̩ҫ����ѼC�C\n");

    set("material", "iron");

    set("value",3100);

    set("volume",1);

  }

  init_fork(35);

  setup();

}
