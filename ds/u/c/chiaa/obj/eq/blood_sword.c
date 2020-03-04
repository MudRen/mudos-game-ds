//u/c/chiaa/obj/eq/blood_sword.c

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIW"沾"HIR"血"HIC"冰"HIM"蛾"NOR,({"blood sword","sword"}) );
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","把");
      set("long","傳聞中最鋒利的劍,但此劍殺人無數,
       劍身散發出一股淡淡的血腥味。\n");
      set_weight(4000);
      set("value",30000);
      set("material","titanium");  //材質 鈦
      set("wield_msg", "$N緩緩的將$n抽出,一股戾氣隨即從劍身傳到$N身上,
                    四周的空氣瀰漫著血腥味。\n");
       set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

   }
        init_sword(777);     //武器攻擊力
 set("weapon_prop/sword",40);        //加 enable 技能40
 set("weapon_prop/parry",30);        //加enable  技能30
setup();
}
