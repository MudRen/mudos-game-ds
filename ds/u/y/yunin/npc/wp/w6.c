

#include <ansi.h>

#include <weapon.h>

inherit DAGGER;

void create()

{

  set_name(HIG"Ａ級天刺"NOR,({ "level A dagger","dagger" }) );

  set_weight(3000);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "把");

    set("long", "這是恐怖人們所持的天刺。\n");

    set("material", "iron");

    set("value",4000);

    set("volume",1);

  }

  init_dagger(22);

  setup();

}
