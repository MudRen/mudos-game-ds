#include <armor.h>
inherit NECK;

void create()
{
  set_name("�����V��",({"seashell necklace","necklace"}) );
  set("long",@LONG
�δX�Ӭ��⨩�ߦꦨ������A��u�ä��륩�C
LONG);
  set_weight(30); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("light",0);       
    set("value",100);          
    set("volume", 1);                       
    set("material", "blacksteel");
  }
  set("armor_prop/armor",1);       
  setup();
} 
