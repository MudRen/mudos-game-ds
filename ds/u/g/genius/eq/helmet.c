#include <armor.h>
#include <ansi.h>
inherit HEAD;

void create()
{
      set_name(HIB"�ǩ��Y��"NOR ,({ "strange helmet","helmet" }) );
set("long","�n�_�Ǫ��@���Y��, �]�����D�O�֥��y��\n");
      if ( clonep() )
      set_default_object(__FILE__);
      else {
      set_weight(1000);
      set("material", "gold");
      set("unit", "��" );
      set("value",0);
      set("armor_prop/armor",123);
      set("armor_prop/int",100);

      }
set("wear_msg",HIY"$N"HIY"�N"HIB"$n"HIY"���b�Y�W,�@�}�����{�L,"HIY"$N"HIY"�����z���G�W�j�F!!\n"NOR);
set("unequip_msg",HIG"$N�N"HIB"$n"HIG"��F�U��, �ݰ_�ӤS�P�`�H�L���F�C\n"NOR);
      setup();
}

int query_autoload() { return 1; }
