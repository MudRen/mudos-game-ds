#include <armor.h>
inherit NECK;

void create()
{
  set_name("�K���@�V",({"iron-cloth neck","neck"}) );
  set("long",@LONG
�@���K�s���@�V�A�a���l�����h�β��K�u´���A�~�h�h�O�O���p�K
���A�����V���ܦn�����@�C
LONG);
  set_weight(1500); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value",3000);          
    set("volume", 2);                       
    set("material", "steel");
  }
  set("limit_con",20);
  set("armor_prop/armor",10);       
  setup();
}
