#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
  set_name(GRN"八歧"MAG"鱗披"NOR,({"orochi cloak","cloak"}));
  set("long", @LONG
八歧大蛇的背鱗製成的披風，披風上還帶有一排背刺，整件披風閃耀
著深綠的邪光。
LONG);
  set_weight(1300);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "件");
    set("volume",3);
    set("value",7000);
    set("material","fur");
  }
  set("limit_lv",40);
  set("armor_prop/armor",20);
  set("armor_prop/shield",20);
  set("armor_prop/dodge",10);
  set("armor_prop/dex",1);
  set("armor_prop/con",2);
  set("armor_prop/int",1);
  setup();
}
