#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name( "�ͥP��" ,({"unquiet ring","ring"}));
  if( clonep() ) set_default_object(__FILE__);
  else
  {
    set("long",@LONG
�o�O�@�T�ѵL��ͥP�����W���o���ͥP�١A�o�٫��O���ν�
�����Ӧ��A���]�N�O�ͥP�����Ҧb�C
LONG
);
    set("value",5000); 
    set_weight(1000); 
    set("material","diamond");
    set("unit","�u");
  } 
  set("armor_prop/int", 3);
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  setup();
}

