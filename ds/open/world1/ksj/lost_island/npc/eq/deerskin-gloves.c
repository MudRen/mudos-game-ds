#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
  set_name(HIC"���֤�M"NOR,({"deerskin gloves","gloves"}) );
  set("long",@LONG
�@�����Ŧ���ֻs������M�A�ݰ_���Z�n�ݪ��C
LONG
);
  set_weight(600); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");       
    set("value",2500);          
    set("volume", 2);                       
    set("material", "fur");   
  }
  set("armor_prop/armor",4);       
  set("armor_prop/str",1);
  set("armor_prop/shield",4);
  setup();
}
