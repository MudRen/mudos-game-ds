#include <ansi.h>
#include <armor.h>
inherit WAIST; 
void create()
{
  set_name(HIG"鼠來運轉帶"NOR,({"mouse-happiness belt","belt"}));
  set("long", @LONG
這是「鼠來運轉」套裝中的其中一件裝備，穿上這套鼠來運轉裝，
可以提昇您打到福袋的機率。
LONG);
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "條");
    set("volume",1);
    set("value", 100);
  }
    // 增加打福袋的機率
    set("armor_prop/happiness", 10);

  setup();
}

