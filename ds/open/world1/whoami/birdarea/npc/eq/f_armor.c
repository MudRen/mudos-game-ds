#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(YEL"����"NOR"�����",({"fox armor","armor"}));
  set("long", @LONG  
�@��γ\�h���W�֩һs�����ԥҡA�~�Y�S�[�W�F����H���ɥ���
���֩Ҥ��������m�O�E���m�O�|�]�s�@�H�����P�Ӧ��ҧ��ܡE
LONG);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",10000);
    set("material","fur");
  }
  set("limit_lv",15);
  set("armor_prop/armor",38+random(4));
  set("armor_prop/shield",10); 
  set("armor_prop/dex",-1);
  set("armor_prop/str",3);
  setup();
}

