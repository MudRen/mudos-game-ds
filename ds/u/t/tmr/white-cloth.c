#include <armor.h>
#include <ansi2.h>
inherit CLOTH;

void create()
{
  set_name(HIW"�կ�"NOR ,({ "white-silk cloth","cloth" }) );
  set("long",@LONG
�o�O�@��D�`�}�G���կ�§�A�A�Ů�o��A�i�H�N�k�H���ҧ�
��������{�X�ӡA�O��۷��Q��§�A�C
LONG
);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 99999999);
  } 

  setup();
}

int query_autoload() { return 1; }

