#include <ansi.h>
inherit ITEM;

void create()
{
  set_name( "�b�ϤH�n��" ,({ "bariour fur","fur" }) );
  set("long",@LONG
�o�O�@���q�Ϩk���g�c�����b�ϤH���Ӫ��n��C
LONG
);
  set_weight(10);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 10);
  }

  setup();
}


