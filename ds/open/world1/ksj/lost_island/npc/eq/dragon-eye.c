#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(HIY"地龍眼"NOR,({"dragon eye","eye"}) );
  set("long",@LONG
獨眼地龍的眼睛，戴上後能讓視野變得廣闊，並且看得更清楚，即使
在黑暗中也能如同白晝。
LONG);
  set_weight(800); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_level",20);
    set("unit", "顆");       
    set("value",5000);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",1);
  setup();
  set("armor_prop/hit",10);
  set("armor_prop/dodge",10);  
}
