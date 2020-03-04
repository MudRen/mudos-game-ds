#include <ansi.h>
#include <armor.h>
inherit HANDS; 
void create()
{
  set_name(HIC"七"HIG"幻"HIY"護套"NOR,({"seven-light gloves","gloves"}));
  set("long", @LONG 
一件鑲著七彩寶石的手套，十分的柔軟也非常的保暖•防禦力
、攻擊力都十分的強大•
LONG);
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",3000);
    set("material","fur");
  }
  set("limit_lv",25);
  set("armor_prop/damage",100);
  set("armor_prop/armor",100);
  set("armor_prop/shield",100); 
  set("armor_prop/dex",20); 
  set("armor_prop/str",20);
  set("armor_prop/con",20);
  set("armor_prop/int",20);
  set("armor_prop/bar",3);
  set("armor_prop/bio",3);
  set("armor_prop/tec",3);  set("armor_prop/wit",3);
  setup();
}

int query_autoload() { return 1; }

