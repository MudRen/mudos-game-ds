#include <ansi.h>
#include <armor.h>
inherit ANKLE; 
void create()
{
   set_name(HIY"�����}��"NOR,({"tmr's golden ankle", "ankle"}));
  set("long", @LONG  
�o�O�ڤۤC�쪺�j���_(Tmr)�ζ������y�X�Ӫ��j�}��A
�쥻�_(Tmr)�O�N���ذe���y�v(Acme)������
���O�S�Q��y�v(Acme)�a�~�M�D�p�����U
��n�o�ɭԪ�BYRON�b�B�F�������r���E
�ݨ�o���}��{�{�o�G�@�ɦn�_�K�N���R�F�^�h 
(�P�� byron �O�߾�z�˳Ƹ�ơC -Tmr 2007/01/22)
LONG);
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",2);
    set("material","gold");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
    set("wear_msg", HIY"$N��_�������}��M�b����W�Aı�o���}�ܪ��ܨI���C\n"NOR);
  set("unequip_msg", HIY"$N��_�������}��ѤU�Aı�o���}�۷����P�C\n"NOR);
  set("armor_prop/armor", 5); 
  set("armor_prop/shield", 5);
  set("armor_prop/dex", -2);
  set("armor_prop/bar", 2);
set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }


