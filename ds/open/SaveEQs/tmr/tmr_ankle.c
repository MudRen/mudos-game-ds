#include <ansi.h>
#include <armor.h>
inherit ANKLE; 
void create()
{
   set_name(HIY"黃金腳鐐"NOR,({"tmr's golden ankle", "ankle"}));
  set("long", @LONG  
這是夢幻七域的大神奇(Tmr)用黃金打造出來的大腳鐐，
原本奇(Tmr)是將它贈送給流影(Acme)當做紀念
但是沒想到流影(Acme)家居然遭小偷光顧
剛好這時候的BYRON在步靈城的正字當舖
看到這條腳鐐閃閃發亮一時好奇便將它買了回去 
(感謝 byron 費心整理裝備資料。 -Tmr 2007/01/22)
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume",2);
    set("material","gold");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
    set("wear_msg", HIY"$N把奇的黃金腳鐐套在足踝上，覺得雙腳變的很沉重。\n"NOR);
  set("unequip_msg", HIY"$N把奇的黃金腳鐐解下，覺得雙腳相當的輕鬆。\n"NOR);
  set("armor_prop/armor", 5); 
  set("armor_prop/shield", 5);
  set("armor_prop/dex", -2);
  set("armor_prop/bar", 2);
set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }


