#include <path.h>
inherit ITEM;

void create()
{
  set_name("�s���y�ҶǧK�\\�L��", ({"master credential","credential"}) );
  set("long", 
"�ӻ{�C�N�׽m�F��̰��Ҭɪ��ҩ��ѡC\n"
);
  set_weight(100);
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
