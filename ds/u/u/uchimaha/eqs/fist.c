#include <weapon.h>
#include <ansi.h>
inherit FIST;

void create()
{
    set_name(HIW"�K�K"HIC"��"NOR,({"shit fist","fist"}) );
   set("long","�K�K���������M, �]�O�Q���ܶª��M�ή��M�C\n");
        set_weight(3000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("value",1000);
        set("armor_prop/str", 10);
        set("armor_prop/int", 10);
        set("armor_prop/dex", 10);
        set("armor_prop/con", 10);
        set("material","iron");
        set("wield_msg", "$N���_�⤤��"HIW"�K�K"HIC"��"NOR", �äj�s�T�n: "HIR"�Q���ܶ�"NOR"!! "HIR"�U��"NOR"!!\n");
        set("unwield_msg", "$N�N��W��"HIW"�K�K"HIC"��"NOR"�p�ߪ����ð_�ӡC\n");
      init_fist(2500);
   }
setup();
}
