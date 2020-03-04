#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name(HIW"鏡"HIC"幻"HIW"胸當"NOR ,({ "illusive-mirror corslet","corslet" }) );
  set("long",@LONG
一個鐵製的胸鎧，前面鑲嵌了不同角度的銀片，讓看的人會產生幻覺
，出現許多幻影，嚴重的還會有暈眩感。
LONG);
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "steel");
    set("volume",4);
    set("unit", "件");
    set("value",6500);
  }
  set("armor_prop/armor",25);
  set("armor_prop/dodge",10);
  setup();
}
