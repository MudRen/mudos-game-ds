#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIR"�t��"HIW"�ּ֨���"NOR,({"christmas ankle","ankle"}));
  set("long", @LONG  
�o�O�@��t�ϦѤH�R�Ϊ�����A²²��檺�u���A�f�t���_�۪��]�p�A
��y�X�t�ϸ`���w�֮�^�A�f�t����A�˳��D�`�n�ݡC
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("value", 50000);
    set("material","gold");
  }
  set("armor_prop/int",1 + random(3) );
  set("armor_prop/str",1 + random(3) );
  set("armor_prop/dex",1 + random(3) );
  set("armor_prop/con",1 + random(3) );
  set("armor_prop/armor", 5 + random(20) );
  setup();
}

