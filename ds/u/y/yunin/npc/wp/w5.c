

#include <ansi.h>

#include <weapon.h>

inherit BLADE;

void create()

{

  set_name(HIG"Ｂ級天刀"NOR,({ "level B blade","blade" }) );

  set_weight(3000);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "把");

    set("long", "這是上校們所持的天劍。\n");

    set("material", "iron");

    set("value",4000);

    set("volume",1);

  }

  init_blade(37);

  setup();

}
