

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()

{

  set_name(HIG"�үŤѼC"NOR,({ "level D sword","sword" }) );

  set_weight(1500);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "��");

    set("long", "�o�O���L�̩ҫ����ѼC�C\n");

    set("material", "iron");

    set("value",2000);

    set("volume",1);

  }

  init_sword(30);

  setup();

}
