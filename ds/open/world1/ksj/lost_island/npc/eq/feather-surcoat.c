#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
  set_name(HIW"���Щܭ�"NOR,({"feather surcoat","surcoat"}) );
  set("long",@LONG
�ϥΤ����W���е��s´���ܭ��A��b���W�X�G�S����Pı�A���m�O�ܮt�C
LONG
);
  set_weight(300); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");       
    set("value",4000);          
    set("volume", 1);                       
    set("material", "fur");   
  }
  set("armor_prop/armor",3);       
  set("armor_prop/shield",13);
  set("armor_prop/dex",1);
  setup();
}
