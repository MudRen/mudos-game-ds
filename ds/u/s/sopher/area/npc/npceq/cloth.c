#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
     set_name(CYN"�����t��"NOR, ({ "cloth" }) );
     set_weight(500);
     if ( clonep() )
          set_default_object(__FILE__);
          
     else {   
              set("unit", "��");
              set("material", "steel");
              set("value", 20000);
              set("armor_prop/armor", 5500);
              set("armor_prop/dodge", 1000);
           }
           setup();
}    

