#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name("�Ѫ�����"NOR,({"tengu mask","mask"}) );
  set("long",@LONG
�Ѫ��`�Ϊ�����A����W�֤��F�@�Ӫ����������l�C
LONG);
  set_weight(900); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");       
    set("value",400);          
    set("volume", 1);                       
    set("material", "gold");   
  }
  set("armor_prop/armor",3);
  set("armor_prop/int",1);
  setup();
}
