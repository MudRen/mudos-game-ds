

#include <ansi.h>

#include <weapon.h>

inherit SWORD;

void create()

{

  set_name(HIG"Ｓ級"HIM"夢"HIW"幻"HIY"劍"NOR,({ "level S sword","sword" }) );

  set_weight(3000);

  if( clonep() )

    set_default_object(__FILE__);

  else

  {

    set("unit", "把");

    set("long", "這是忍者們所持的天劍。\n");

    set("material", "iron");

    set("value",4000);

    set("volume",1);

  }

  init_sword(61);

  setup();

}
