#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIR"�t��"HIY"���s��"NOR,({"flame turn-dragon ring","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("long","�@�u���o��"HIR"����"NOR"�������٫��A���t�������_�����@�C\n"NOR);
    set("value",10000); 
    set_weight(1000); 
    set("material","diamond");
    set("unit","�u");
  } 
    set("armor_prop/int",3);   
    set("armor_prop/dex",2);
    set("armor_prop/str",-2);
  set("armor_prop/armor",3);
  setup();
}

