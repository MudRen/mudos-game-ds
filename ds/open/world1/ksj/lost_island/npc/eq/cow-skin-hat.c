#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name("����ֲ�",({"cow-skin hat","hat"}) );
  set("long",@LONG
�Τ@�ؤW�������y�몺���ֻs�����Y���A���@�O�٤����C
LONG
);
  set_weight(1000); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_con",10);
    set("unit", "��");       
    set("value",5000);          
    set("volume", 3);                       
    set("material", "leather");   
  }
  set("armor_prop/armor", 8);
  set("armor_prop/damage",3);
  setup();
}
