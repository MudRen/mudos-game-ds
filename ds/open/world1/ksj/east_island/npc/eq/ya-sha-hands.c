#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIW"�ڮg���"NOR,({"ya-sha hands","hands"}) );
  set("long",@LONG
�K�s����ҡA���æ������i�H�o�g�X�p�b�C
LONG);
  set_weight(1100); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");       
    set("value",2500);          
    set("volume", 2);                       
    set("material", "steel");   
  }
  set("limit_dex",15);
  set("armor_prop/armor",8);       
  set("armor_prop/damage",3);
  setup();
}
