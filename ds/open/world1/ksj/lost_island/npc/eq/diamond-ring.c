#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIW"�p�ۧ٫�"NOR ,({ "diamond ring","ring" }) );
  set("long",@LONG
�@�u�{ģ�۽A����~���٫��A�٫��W���p�ۦ��Q�X�J�ԡA���ȫD�Z�C
LONG);
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("light",1);
    set("unit", "�u");
    set("value",150000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",1);
  setup();
}
