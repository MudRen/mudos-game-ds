#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIW"�ջ�Ţ��"NOR,({"silver gloves","gloves"}) );
  set("long",@LONG
�»Ȼs�@���@��A�������R���Q�A���m�O�]�ܦn�C
LONG);
  set_weight(2100); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");       
    set("value",5000);          
    set("volume", 2);                       
    set("material", "silver");   
  }
  set("limit_con",30);
  set("armor_prop/armor",12);       
  setup();
}
