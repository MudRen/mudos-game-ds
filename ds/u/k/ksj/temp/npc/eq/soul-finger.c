#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
  set_name(HIC"�M�F����"NOR,({"soul finger","finger"}));
  set("long", @LONG
�¥դ����^�b�»ȧٮy�A����u�Ϯg�ɥi�H�ݨ���������B�{�{�G��
�Q�r�[�A�o�O�j�N�Y��t�̪��򪫡C
LONG
);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "�u");
    set("volume",1);
    set("value",5000);
    set("material","stone");
  }
  set("armor_prop/armor",1);
  set("armor_prop/shield",10);
  set("armor_prop/sou",1);
  set("armor_prop/bar",-1);
  setup();
}
