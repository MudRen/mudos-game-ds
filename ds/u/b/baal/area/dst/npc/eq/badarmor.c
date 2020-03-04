#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(YEL"破舊皮甲"NOR,({"a worn-down leather armor","armor"}));
        set("long", "一件表面磨痕斑斑的皮甲，上面因為經年累月的使用而出現了不少
破洞，同時厚度也大大減低，看來實在不能幫你擋下多少攻擊。\n");
  set_weight(4100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "件");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

