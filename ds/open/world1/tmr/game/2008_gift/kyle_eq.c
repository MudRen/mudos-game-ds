#include <ansi2.h>
#include <armor.h>
inherit LEGGING;

void create()
{
   set_name(HIR"��"HIW"��"NOR,({ "bloodtooth" }) );
  set("long",@LONG
�o���p��@���C�⪺�H�ҡA�O�Ѥ@�بu�����`�����q�۩ҥ��y�Ӧ��A
�o���q�۪��~���I�Φb�a�����U�A�l���F��ߦa��~�|�e�{�o�دS��
�����C
�o��˳Ƭ�kyle�b2008�~�u�����_�v���ʤ���o���S�O�����~�C
LONG);
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "��");
    set("value", 100);
        set("wear_msg", HIR"��$N��W����ɡA�@�����⪺���u�۵��߹M�G����"NOR);
        set("unequip_msg", WHT "�b$N��U�����A��ߤ������u���G�]���u�ӥh�C�C\n"NOR);
  }
  set("armor_prop/armor", 10);
  set("armor_prop/shield", 10);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",2);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}


int query_autoload() { return 1; }

