#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(MAG"紫玉戒"NOR,({"purple-jade ring","ring"}) );
  set("long",@LONG
一枚紫色的古戒，上面刻著看不懂的文字，泛著溫潤的光澤。
LONG
);
  set_weight(300); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",30);
    set("unit", "只");       
    set("value",30000);          
    set("volume", 2);                       
    set("material", "stone");   
  }
// 2003.3.30 新增 lv限制 by ksj
  set("limit_lv",35);
  set("armor_prop/armor",1);       
  set("armor_prop/int",2);
  set("armor_prop/con",2);
  set("armor_prop/hit",5);
  setup();
}
