#include <ansi.h>
#include <armor.h>
inherit ANKLE;
void create()
{
  set_name(HIY"�Ӷ����q"NOR,({"sun-song ankle","ankle"}));
  set("long", @LONG  
�Ӷ����q�O�@�ӷP�H���G�ơA�G�����z��b���䫰�����B���ȱw�W�ۦ�ʰ��֯g
�]Xeroderma Pigmentosum�A²��XP�^�A���餣��Ӯg�����C�]���o���ͬ��P���`
�H�ۤϡG��X�ɦo�����ʮɶ��}�l�F�����X�ӮɴN��ı�C�Y�ϳo�ˡA�o������o
���a�H�B�n�B�͡A�C��ּ֦a�ͬ��C���~���ֹ�o�ӻ��O��ƻ򳣭��n���F��C
�b�q�ۤ��A�n�P����ͦs���N�q�C����J�W�@��֦~�A�o���R�B�X�{�F�ܤj�����ܡC
LONG
);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 3);
    set("material","gold");
  }

    set("not_clone",1);
  set("armor_prop/int",3 );
  set("armor_prop/str",3  );
  set("armor_prop/dex",3  );
  set("armor_prop/con",3  );
  set("armor_prop/armor", 5 );
  set("armor_prop/shield", 5 );
  set("armor_prop/show_damage", 1);
  setup();
}

