#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
  set_name( HIC"���"HIW"��"HIB"��"NOR,({"Illusion feather","feather"}));
  set("long", @LONG  

        ��U�a�f��ȪQ�A�и����߷������F
        �ȥ~�Z�O�᭸���A�۰������o�ӪšC

�o�O���ɪ̲Ĥ@�W�����~�G
��  �@�W ---- bluerex �y���n�� �|�Q�@�U�G�d�E�ʤC�Q�� �H��
LONG);
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume", 1);
    set("value", 0);
    set("material","gold");
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
        set("wear_msg",HIC "$N�u�w�ֵ��A���}�����ХȤۡA�O�H�P���ڥ�ۡC\n" NOR);
        set("unequip_msg",HIC "�u��$N���}�򦩡A��ХȤۤw�M�Ƨ@�@�\\���ϡC\n" NOR);
  set("armor_prop/bar",1 );
  set("armor_prop/armor", 5 );
  setup();
}

int query_autoload() { return 1; }

