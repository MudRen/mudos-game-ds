#include <armor.h>
#include <ansi.h>
inherit SHIELD;
void create()
{
  set_name(HIY"�����M"NOR, ({ "ability gloves","gloves" }) );
  set("long", HIY"�o�O�@���ίS����谵����M�A�W���x�ۤ@�ѴH��C\n�o���ݰ_�ӬO����Ϊ��C\n"NOR);
  set_weight(100);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "��");
    set("value",1);
  }
  set("armor_prop/suc",1);
set("parry_msg", ({
       "$n�����e�X�{�F�@�D"+MAG"�b�z��"+NOR"��"+HIR"�B��"+NOR"��פF$N������\n",
       "$n"+HIW"�N�N���D:�u�S�Ϊ��A�A��������ڬO�S���Ϊ��D�v"+NOR"\n",
}) );
set("unarmed_parry_msg", ({
       "$n�����e�X�{�F�@�D"+MAG"�b�z��"+NOR"��"+HIR"�B��"+NOR"��פF$N������\n",
       "$n"+HIW"�N�N���D:�u�S�Ϊ��A�A��������ڬO�S���Ϊ��D�v"+NOR"\n",
}) );
set("dodge_msg", ({
       "$n�����e�X�{�F�@�D"+MAG"�b�z��"+NOR"��"+HIR"�B��"+NOR"��פF$N������\n",
       "$n"+HIW"�N�N���D:�u�S�Ϊ��A�A��������ڬO�S���Ϊ��D�v"+NOR"\n",
}) );
  set("armor_prop/armor",20);
  set("armor_prop/block",10);
  setup();
}

int query_autoload() { return 1; }

