#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
    set_name(HBK"夜禍遺骨面甲"NOR,({"nightbane mask","mask"}) );
  set("long",@LONG
這是一張從骨龍夜禍取下的遺骨面甲，夜禍是一條巨大的骨龍，渾身散發著黑色的
死亡氣息。而這張面具也是被股黑色濃霧包住，似乎有莫名的力量。
LONG);
  set_weight(1200); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "張");       
    set("value",12000);
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("armor_prop/armor",10);
  set("armor_prop/shield",10);
  set("armor_prop/bio", 1);
  set("armor_prop/con", 2);
  setup();
}

