#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
  set_name(HIG"��"NOR"�b��u"NOR, ({ "cloud boots","boots" }) );
  set("long",@long
�Y�j�v���ۦW�@�~�A��W���ԡA�U���]���ԡC
long);      
  set_weight(900);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","gold");
    set("value",3000);
  }
  set("armor_prop/dodge",5);
  set("armor_prop/int",2);
  set("armor_prop/con",2);

  set("armor_prop/dex",2);
  set("armor_prop/armor", 16);
  setup();
}

