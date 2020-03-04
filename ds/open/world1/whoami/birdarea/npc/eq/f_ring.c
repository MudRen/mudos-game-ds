#include <ansi.h>
#include <armor.h>
inherit FINGER; 
void create()
{
  set_name(YEL"狐眼"NOR"之戒",({"fox ring","ring"}));
  set("long", @LONG
一個用狐狸的眼睛做出來的戒指，有一顆血淋淋的眼睛裝在上面
，看起來只是好看用而已•防禦力會因製作人的不同而有所改變
LONG);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "個");
    set("volume",3);
    set("value",9000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",1+random(4));
  set("armor_prop/con",-2);
  setup();
}

