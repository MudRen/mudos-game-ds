#include <ansi.h>
#include <path.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(RED"鐵龍血"NOR, ({"shell dragon blood","blood"}) );
  set("long", 
"脊背鐵龍的血塊，持續發出燙手的熱氣。\n"
);
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "個");
    set("volume",10);
    set("value",600);
    set("food_remaining",1);
    set("heal_hp",1000);  
    set("heal_ap",300);  
    set("heal_mp",300);  
    set("eat_msg","$N吃下一塊滾燙的血塊。");
    set("eff_msg",HIG "你覺得有一股熱流從丹田擴散到四肢，頓時神清氣爽，精力充沛。" NOR );
  }
  setup(); 
}
