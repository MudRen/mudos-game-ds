#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIG"�H������"NOR,({"ningyo necklace","necklace"}) );
  set("long",@LONG
���]�l�ꦨ������A�O�H���j����������ɩһs���C
LONG);
  set_weight(700); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",5000);          
    set("volume", 2);                       
    set("material", "stone");
  }
  set("armor_prop/armor",2);       
  set("armor_prop/con",3);
  setup();
}
