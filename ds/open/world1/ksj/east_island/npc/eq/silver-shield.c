#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIW"�y���Ȭ�"NOR,({"silver shield","shield"}));
  set("long", @LONG
���j���Ҳ�������A�H�軴�����K�O�W�I�[�]�O���Ȥ��A�㦳�ܦn
�����@�O�C
LONG);
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",6000);
    set("material","silver");
  }
  set("armor_prop/armor",21);
  set("armor_prop/shield",15);
  set("armor_prop/block",5);
  set("armor_prop/con",1);
  set("armor_prop/int",1);
  setup();
}
