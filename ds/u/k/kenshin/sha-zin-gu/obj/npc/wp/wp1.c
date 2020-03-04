#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name(HIW"桑栗"NOR,({"sAnG Li","sang","li"}) );
  set("long","奇俠寧采和所持的絕世武器。\n");
  set_weight(3300);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("unit","隻");
    set("value",10000);
    set("material","leather");
    set("volume",3);
    set("wield_msg",HIG"$N裝備起此武器，便感覺柔和的氣體從裡飄出。\n" NOR);
  }
  set("limit_skill",70);
  set("weapon_prop/str",3);
  set("weapon_prop/dex",-1); 
  set("weapon_prop/sou", 1);    init_fist(68);
  setup();
}

