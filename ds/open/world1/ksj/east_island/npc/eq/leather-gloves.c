#include <armor.h>
inherit HANDS;

void create()
{
  set_name("���U",({"leather gloves","gloves"}) );
  set("long",@LONG
�֭��s������M�A�X�n�ӥB�����������@�O�C
LONG);
  set_weight(600); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");       
    set("value",500);          
    set("volume", 2);                       
    set("material", "leather");   
  }
  set("armor_prop/armor",4);       
  setup();
}
