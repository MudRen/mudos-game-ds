#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
   set_name(HIY"月靈"HIR"神暈圈"NOR,({ "lunar halo circle","circle" }) );
  set("long",@LONG
月神擷取月宮中長年吸取月暈神奇靈氣的特殊金屬，以月神之力歷經
千錘百鍊所造就的一圈圜狀金屬裝備。穿著者可得到月宮靈氣的保佑
以及加持。
這件裝備為godfire在2008年「鼠來寶」活動中獲得的獎品。
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
        set("wear_msg",HIY"$N穿起月神秘傳月靈神暈圜，身體四周發散出有如月暈的光環。"NOR);
        set("unequip_msg",HIY"$N退去月靈神暈圜，只覺得四周光粒漸漸散去。\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 20);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",4);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }

