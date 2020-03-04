#include <ansi.h>
#include <armor.h>
inherit BOOTS;
void create()
{
  set_name(HIY"美神詩曲"NOR,({"afolodina shoes","shoes"}));
  set("long", @LONG  
嬌美的花朵配上起舞的蝴蝶，於微小處體現出自然和獨特，蘊涵著
自然典雅，清新中透著華美，絢爛高貴卻無比親切。充滿古典優雅
氣息的鞋子，配上柔和浪漫的花朵，宛如童話中的公主，輕盈俏麗
，翩翩欲飛。 
LONG
);
  set_weight(1800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "雙");
    set("volume", 2);
    set("material","leather");
    set("value", 7300);     
  }
  set("armor_prop/int", 2);
  set("armor_prop/str", 2);
  set("armor_prop/con", -2);
  set("armor_prop/sou", 1);
  set("armor_prop/wit", -1);
  set("armor_prop/armor", 11);
  set("armor_prop/shield", 26);
  setup();
}

