#include <ansi.h>
#include <armor.h>
inherit MASK;

void create()
{
  set_name(HIC"�����@��"NOR,({"leviathan mask","mask"}) );
  set("long",@LONG
�j���D  �Q���ȴ��B�W����ֻs��������A��ƭ���e�{���Ŧ�A��
�ƪ����ť��y��A�N��������{�{�i���C
LONG);
  set_weight(500); 
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_level",25);
    set("unit", "��");       
    set("value",20000);          
    set("volume", 2);                       
    set("material", "gold");   
  }
// 2003.3.30 �s�W lv���� by ksj
  set("limit_lv",40);
  set("armor_prop/armor",4);
  set("armor_prop/shield",10);
  set("armor_prop/hit",5);
  set("armor_prop/dodge",5);       
  set("armor_prop/int",2);
  set("armor_prop/dex",2);
  set("armor_prop/tec",1);
  set("armor_prop/bar",-1);
  setup();
}
