#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIW"�p�ۦ���"NOR ,({ "diamond earring","earring" }) );
  set("long",@LONG
�@��{ģ�۽A����~�������A�^�b�����W���p�۶W�L�Q�J�ԡA����
�D�Z�C
LONG);
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("light",1);
    set("unit", "��");
    set("value",160000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",1);
  setup();
}
