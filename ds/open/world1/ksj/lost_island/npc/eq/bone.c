#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name(HIW"�@��հ�"NOR, ({"bone"}));
  set("long",@LONG
�@��ʪ����հ��A��b�@�ǹ��p�g�C�@�˰��A�ݤF�O�H���o��C
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("unit", "��");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
