#include <ansi.h>
#include <armor.h>
inherit ANKLE; 
void create()
{
  set_name(HIW"月神"HIC"輪"NOR,({"moon skates ankle","skates", "ankle"}));
  set("long", @LONG  
傳說這是由月神親自做的一條足鍊，是從月神獸身上取得稀有的毛皮，配合
天地精氣所編織而成，質感輕如薄翼，防護能力更是上上之選，為人世間不可多
得的寶物。

[2006 中秋節奔月比賽-第一名 文泰來(Bluerex) 獎品]
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "雙");
    set("volume",2);
    set("material","fur");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
  set("wear_msg", HIC"$N在足踝綁上月神輪，覺得雙腳如履雲彩，全身重心更穩了。"NOR);
  set("unequip_msg", HIC"$N細心解下月神輪，只覺世界更真實。\n"NOR);
  set("armor_prop/armor", 8); 
  set("armor_prop/shield", 8);
  set("armor_prop/dex", 3);
  set("armor_prop/bar", 1);
  setup();
}

int query_autoload() { return 1; }

