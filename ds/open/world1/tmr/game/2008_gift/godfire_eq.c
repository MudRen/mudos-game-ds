#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
   set_name(HIY"���F"HIR"���w��"NOR,({ "lunar halo circle","circle" }) );
  set("long",@LONG
�믫�^����c�����~�l����w���_�F�𪺯S����ݡA�H�믫���O���g
�d�����ҳy�N���@���G�����ݸ˳ơC��۪̥i�o���c�F�𪺫O��
�H�Υ[���C
�o��˳Ƭ�godfire�b2008�~�u�����_�v���ʤ���o�����~�C
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
        set("wear_msg",HIY"$N��_�믫���Ǥ��F���w�G�A����|�P�o���X���p��w�������C"NOR);
        set("unequip_msg",HIY"$N�h�h���F���w�G�A�uı�o�|�P���ɺ������h�C\n"NOR);
  }
  set("armor_prop/armor", 20);
  set("armor_prop/shield", 20);
  set("armor_prop/show_damage",1);
  set("armor_prop/str",4);
  setup();
}

void init() {
        if (!this_object()->query_light() )
                this_object()->start_light(1);
}

int query_autoload() { return 1; }

