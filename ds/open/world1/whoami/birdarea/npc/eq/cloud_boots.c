#include <ansi.h>
#include <armor.h>
inherit BOOTS; 
void create()
{
  set_name(HIW"�b��"NOR,({"cloud boots","boots"}));
  set("long", @LONG  
�o���@��O�����J�~���ɪ��ǧ@�E�ڻ����׬O�֡A�u�n��W�F��
�ҥi�@��d���E���\�n�Ǫ��A�Ʀ��٥i�H����B�b���E
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("value",3600);
    set("material","fur");
  }
  set("limit_lv",43);
  set("armor_prop/armor",10); 
  set("armor_prop/shield",4);
  set("armor_prop/dodge",15);
  set("armor_prop/dex",3);
  set("armor_prop/int",2);
  setup();
}

