#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("�A��O", ({"tower"}));
  set("long",@LONG
�@�y�Τ��Y�f�ئ������O�A�i�H�ݨ컷�B�����p�C
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
