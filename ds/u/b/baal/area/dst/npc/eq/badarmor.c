#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(YEL"�}�¥֥�"NOR,({"a worn-down leather armor","armor"}));
        set("long", "�@����i���������֥ҡA�W���]���g�~�֤몺�ϥΦӥX�{�F����
�}�}�A�P�ɫp�פ]�j�j��C�A�ݨӹ�b�������A�פU�h�֧����C\n");
  set_weight(4100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

