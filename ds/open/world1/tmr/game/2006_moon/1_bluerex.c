#include <ansi.h>
#include <armor.h>
inherit ANKLE; 
void create()
{
  set_name(HIW"�믫"HIC"��"NOR,({"moon skates ankle","skates", "ankle"}));
  set("long", @LONG  
�ǻ��o�O�Ѥ믫�˦۰����@������A�O�q�믫�~���W���o�}������֡A�t�X
�Ѧa���ҽs´�Ӧ��A��P���p���l�A���@��O��O�W�W����A���H�@�����i�h
�o���_���C

[2006 ����`�b�����-�Ĥ@�W �����(Bluerex) ���~]
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("material","fur");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
  set("wear_msg", HIC"$N�b����j�W�믫���Aı�o���}�p�i���m�A�������ߧ�í�F�C"NOR);
  set("unequip_msg", HIC"$N�Ӥ߸ѤU�믫���A�uı�@�ɧ�u��C\n"NOR);
  set("armor_prop/armor", 8); 
  set("armor_prop/shield", 8);
  set("armor_prop/dex", 3);
  set("armor_prop/bar", 1);
  setup();
}

int query_autoload() { return 1; }

