#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIW"�p�۶���"NOR ,({ "diamond necklace","necklace" }) );
  set("long",@LONG
�@��{ģ�۽A����~������A�ժ��s��������W���ۤ@���j�p�ۡA��
�ȫD�Z�C
LONG);
  set_weight(700);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",1);
    set("light",1);
    set("unit", "��");
    set("value",180000);
  }
  set("armor_prop/armor",1);
  set("armor_prop/con",1);
  setup();
}
