#include <ansi.h>
#include <armor.h>
inherit PANTS; 
void create()
{
  set_name(HIB"雷"HIR"。"HIC"蒼流"NOR+CYN"褲"NOR,({"flow pants","pants"}));
  set("long", @LONG 
一條畫著蒼天鳴雷的圖案的褲子，圖案散發一股灑脫超然的吸引力•看來栩栩如生
製作人應該不是個簡單人物•
LONG);
  set_weight(1100);
  if( clonep() ) set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",4500);
    set("material","fur");
  }
  set("armor_prop/armor",30); 
  set("armor_prop/shield",100);
  set("armor_prop/dex",20);
  set("armor_prop/int",20);
  set("armor_prop/str",20);
  set("armor_prop/con",20);  
  setup();
}
int query_autoload()
{
      return 1;
}


