

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()

{

  set_name(HIG"���"HIM"��"HIW"��"HIY"�C"NOR,({ "level S sword","sword" }) );

  set_weight(3000);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "��");

    set("long", "�o�O�Ԫ̭̩ҫ����ѼC�C\n");

    set("material", "iron");

    set("value",4000);

    set("volume",1);

  }

  init_sword(61);

  setup();

}
