#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("�j�D��", ({"bath pool","pool"}));
  set("long",@LONG
�@�ӫܤj����y�D���A���l���|�P�����˪��Ŭu�����_�a�`�J�����A
�D�������X�ӫȤH���b�ΪA�a�w���C
LONG
  );
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "�y");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
