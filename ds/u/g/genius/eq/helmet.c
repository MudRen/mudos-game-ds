#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
      set_name(HIB"怪怪頭盔"NOR ,({ "strange helmet","helmet" }) );
set("long","好奇怪的一個頭盔, 也不知道是誰打造的\n");
      if ( clonep() )
      set_default_object(__FILE__);
      else {
      set_weight(1000);
      set("material", "gold");
      set("unit", "頂" );
      set("value",0);
      set("armor_prop/armor",123);
      set("armor_prop/int",100);

      }
set("wear_msg",HIY"$N"HIY"將"HIB"$n"HIY"戴在頭上,一陣炫光閃過,"HIY"$N"HIY"的智慧似乎增強了!!\n"NOR);
set("unequip_msg",HIG"$N將"HIB"$n"HIG"脫了下來, 看起來又與常人無異了。\n"NOR);
      setup();
}

int query_autoload() { return 1; }
