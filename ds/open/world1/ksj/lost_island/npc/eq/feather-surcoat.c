#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
  set_name(HIW"絨羽披風"NOR,({"feather surcoat","surcoat"}) );
  set("long",@LONG
使用不知名的羽絨編織的披風，穿在身上幾乎沒什麼感覺，防禦力很差。
LONG
);
  set_weight(300); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");       
    set("value",4000);          
    set("volume", 1);                       
    set("material", "fur");   
  }
  set("armor_prop/armor",3);       
  set("armor_prop/shield",13);
  set("armor_prop/dex",1);
  setup();
}
