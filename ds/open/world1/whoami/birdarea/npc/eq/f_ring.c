#include <ansi.h>
#include <armor.h>
inherit FINGER; 
void create()
{
  set_name(YEL"����"NOR"����",({"fox ring","ring"}));
  set("long", @LONG
�@�ӥΪ��W���������X�Ӫ��٫��A���@����O�O�������˦b�W��
�A�ݰ_�ӥu�O�n�ݥΦӤw�E���m�O�|�]�s�@�H�����P�Ӧ��ҧ���
LONG);
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",9000);
    set("material","fur");
  }
  set("limit_lv",10);
  set("armor_prop/armor",1+random(4));
  set("armor_prop/con",-2);
  setup();
}

