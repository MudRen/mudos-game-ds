#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIR"聖誕"HIW"快樂足鍊"NOR,({"christmas ankle","ankle"}));
  set("long", @LONG  
這是一串聖誕老人愛用的足鍊，簡簡單單的線條，搭配著寶石的設計，
塑造出聖誕節的歡樂氣氛，搭配任何服裝都非常好看。
這是參賽者第三名的獎品：
第  三名 ----         ayumi 獵殺積分 十六萬二千七百七十三 人斬
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "串");
    set("volume", 3);
    set("material","gold");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }

  set("armor_prop/int",1 );
  set("armor_prop/str",1  );
  set("armor_prop/dex",1  );
  set("armor_prop/con",1  );
  set("armor_prop/armor", 5 );
  setup();
}

int query_autoload() { return 1; }

