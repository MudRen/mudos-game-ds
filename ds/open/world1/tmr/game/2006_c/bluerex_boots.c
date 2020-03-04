#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
  set_name( HIC"月羽"HIW"玄"HIB"幻"NOR,({"Illusion feather","feather"}));
  set("long", @LONG  

        月下蒼柏迎客松，羽落丹心滅極鐘；
        玄外豈是花飛絮，幻做輕雪卻勝空。

這是參賽者第一名的獎品：
第  一名 ---- bluerex 獵殺積分 四十一萬二千九百七十六 人斬
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "雙");
    set("volume", 1);
    set("value", 0);
    set("material","gold");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
        set("wear_msg",HIC "$N吟誦詩詞，雙腳輕踏月羽玄幻，令人感到亦夢亦幻。\n" NOR);
        set("unequip_msg",HIC "只見$N雙腳緊扣，月羽玄幻已然化作一縷\輕煙。\n" NOR);
  set("armor_prop/bar",1 );
  set("armor_prop/armor", 5 );
  setup();
}

int query_autoload() { return 1; }

