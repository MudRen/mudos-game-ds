#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
  set_name(HIG"��"NOR ,({ "leaf" }) );
  set("long",@LONG 
�@�������Y���W���𸭡A�ǻD�����ߪk�O���ӷ��N�O�o�����l�A���M
�����ണ�ѫܦn�����@�A���O�o�൹�P�j�j���k�N�O�q�E

LONG
);
  set_weight(10);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",1);
    set("unit", "��");
    set("value",0);
  }
  set("armor_prop/armor",0);
  set("armor_prop/shield",15);
  set("armor_prop/int",3); 
  set("armor_prop/wit",1); 
  set("beast_armor_prop/armor",30);
  setup();
}

