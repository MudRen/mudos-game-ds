#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
      set_name(HIR"���s���C"NOR, ({ "fire sword","sword" }) );
      set_weight(1000);
      if( clonep() )
      set_default_object(__FILE__);
      else {
             set("unit","��");
             set("value",10000);
             set("material","steel");
        }
       init_sword(100);
       set("wield_msg",HIR"$N�N$n���b�⤤�A$N�|�P�z�X�h�h���K�A�N$N�ιΥ]��I\n"NOR);
       set("unwield_msg",HIW"$N�@��U$n�A���Ǫ��P����M�����L�ܡI\n"NOR);          
       setup();
}    
