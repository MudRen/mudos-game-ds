#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
   set_name(HIR"�믫" HIM"�E" HIY"�ػR�n"NOR,({ "goddess raiment","raiment" }) );
  set("long",@LONG
�@��믫��۩󲳯��R�|���A�W�D�j�١A�R�X�����̨��w��
�R�Ъ���n�C�H��n���p���l�A�O��۵ۨ����ɲ{�C
�o��˳Ƭ�christine�b2008�~�u�����_�v���ʤ���o���S�O�����~�C
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
        set("wear_msg",HIM"$N��_�믫�E�ػR�n�A���A�|�g�A�ܱo�Ҧ��H���إ��C"NOR);
        set("unequip_msg",HIM"$N�h�h�믫�E�ػR�n�A���ب��¡C\n"NOR);
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

