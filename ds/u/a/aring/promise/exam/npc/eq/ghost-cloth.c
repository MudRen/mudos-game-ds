#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW+BLK"�c����"NOR, ({ "ghost cloth","cloth" }) );
  set("long",@long
�Y�j�v���ۦW�@�~�A��W���ԡA�U���]���ԡC
long);      
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","gold");
    set("value",1000);
  }
  set("armor_prop/int",1);
  set("armor_prop/armor", 4);
  setup();
}

