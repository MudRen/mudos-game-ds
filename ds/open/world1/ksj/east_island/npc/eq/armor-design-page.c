#include <path.h>
inherit ITEM;

void create()
{
  set_name("�}�ȱi", ({"armor design page","page"}) );
  set("long", 
      "�@�i���I�}�ꪺ�ȡA�ȤW�g�ۡi��ۯݷ�j�A�٦��K�K�³¹��O�]�p\n"
     +"�Ϫ��ϼˡC\n"
     );
  set_weight(250);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "�i");
    set("volume",1);
    set("no_sell",1);
  }
  setup(); 
}
