#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name("���֤l��" ,({ "yellow-skin cloth","cloth" }) );
  set("long",@LONG
���֤l�Y�O�ҿת��u�����T�v�A�O�̦l�B���ƪ��ͪ��C�o��N�O
�ζ��֤l���֩һs�����@��֦�C
LONG
);
  set_weight(300);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("value", 1000);
    set("material", "fur");
  }
    set("armor_prop/int", 1);
    set("armor_prop/shield",10);
    set("armor_prop/armor", 5);

  setup();
}

