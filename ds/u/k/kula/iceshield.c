#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
  set_name(HIY"異能手套"NOR, ({ "ability gloves","gloves" }) );
  set("long", HIY"這是一隻用特殊材質做的手套，上面泛著一股寒氣。\n這隻看起來是左手用的。\n"NOR);
  set_weight(100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "隻");
    set("value",1);
  }
  set("armor_prop/suc",1);
set("parry_msg", ({
       "$n的身前出現了一道"+MAG"半透明"+NOR"的"+HIR"冰壁"+NOR"抵擋了$N的攻擊\n",
       "$n"+HIW"冷冷說道:「沒用的，你的攻擊對我是沒有用的．」"+NOR"\n",
}) );
set("unarmed_parry_msg", ({
       "$n的身前出現了一道"+MAG"半透明"+NOR"的"+HIR"冰壁"+NOR"抵擋了$N的攻擊\n",
       "$n"+HIW"冷冷說道:「沒用的，你的攻擊對我是沒有用的．」"+NOR"\n",
}) );
set("dodge_msg", ({
       "$n的身前出現了一道"+MAG"半透明"+NOR"的"+HIR"冰壁"+NOR"抵擋了$N的攻擊\n",
       "$n"+HIW"冷冷說道:「沒用的，你的攻擊對我是沒有用的．」"+NOR"\n",
}) );
  set("armor_prop/armor",20);
  set("armor_prop/block",10);
  setup();
}

int query_autoload() { return 1; }

