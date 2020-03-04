#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
   set_name(HIR"月神" HIM"•" HIY"華舞裳"NOR,({ "goddess raiment","raiment" }) );
  set("long",@LONG
一件月神穿著於眾神舞會中，獨挑大樑，舞出全場最受歡迎
舞蹈的衣裳。以衣裳薄如蟬翼，令穿著著身裁盡現。
這件裝備為christine在2008年「鼠來寶」活動中獲得的特別獎獎品。
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "對");
    set("value", 100);
        set("wear_msg",HIM"$N穿起月神•華舞裳，驚艷四射，奪得所有人的目光。"NOR);
        set("unequip_msg",HIM"$N退去月神•華舞裳，光華依舊。\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",2);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }

