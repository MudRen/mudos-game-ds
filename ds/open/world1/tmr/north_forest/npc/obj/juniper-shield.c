#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name( "�̤��",({"juniper shield","shield"}));
  set("long", @LONG
�̤쬰�Q�f���f��A�`���쪺�@�ءA�ͪ�����ެ��@�d���ʤ���
�ܨ�d���ʤ��������C�̤�t���j�q��o�Y�ҿת���h��A�u���L
�����A���ʰ�w�A�@���O�������G�k�Τ��ȳE�ΫI�k���S�ʡA��
�Ӱ����޵P�A�Ʀܤ��K���٭n�Ӫ���T�@�ΡC
LONG);
  set_weight(2400);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value", 3000);
    set("material","wood");
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 10);
  set("armor_prop/con", 2);
  set("armor_prop/dex", -1);
  setup();
}
