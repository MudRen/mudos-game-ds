#include <ansi.h>
#include <armor.h>
inherit LEGGING; 
void create()
{
   set_name( HIG"���"HIY"�i"HIM"�^"NOR,({"moon wave fiber", "fiber", "leggings"}));
  set("long", @LONG  
�o�O�@��ѹ߮Z�Ķ���۾��ֺ��Ф�ޡЩһs�����i���@���ȡC��۾�g
�~�֤�D���d�褣�v����a���A�𨭪��˲��o�i�H�ֳt�^�СA���a��ޯ�
�_���\�ġC�߮Z��Ų�󦹡A�E�N����_�s�������i���������@���ȡA�a�۪i
���~�[�i�j�q�l�������O���\�ġA�󴣰��F���˳ƪ����@�O�C
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",1);
    set("material","silver");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
  set("wear_msg", HIC"$N��W�F��ުi�^�A�٨����A�|�P�򴲧G�۾K�H���ڭ��C\n"NOR);
  set("unequip_msg",HIC"���𴲥h�A�u��$N�N��ުi�^���_���b�y���C\n"NOR);
  set("armor_prop/bar", 1);
  set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }


