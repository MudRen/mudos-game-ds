

#include <ansi.h>

#include <weapon.h>

inherit BLADE;

void create()

{

  set_name(HIG"�ЯŤѤM"NOR,({ "level B blade","blade" }) );

  set_weight(3000);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "��");

    set("long", "�o�O�W�խ̩ҫ����ѼC�C\n");

    set("material", "iron");

    set("value",4000);

    set("volume",1);

  }

  init_blade(37);

  setup();

}
