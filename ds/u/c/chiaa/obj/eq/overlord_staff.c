//u/c/chiaa/obj/eq/overlord_staff.c
#include <ansi.h>
#include <weapon.h>  //定義是武器

inherit STAFF;

void create()
{
   set_name( RED "霸" HIB "王" HIW "槍" NOR, ({ "overlord_staff", "staff" }) );
        set_weight(35000);
        if( clonep() )    //設定參數
                set_default_object(__FILE__);
        else {
  set("unit", "根");
  set("long", "霸王橫千秋的隨身武器,在前端有三個尖刺,看起來霸氣十足,
               但是它非常沈重,普通人是無法拿起來。\n");
  
  set("value", 10000);
  set("material", "steel");  //材質 鋼
  set("limit_str",25);  //限制臂力25
  set("wield_msg", "$N將背上的$n抽出往地上一插,地面頓時多個窟隆。\n");
  set("unwield_msg", "$N將手中的$n放回背上,背上感覺一沉。\n"); 
  //$N指玩家$n指武器
        }

        init_staff(999); //攻擊力
 set("weapon_prop/staff", 30);      //加 enable 技能30
 set("weapon_prop/dodge", -10);     //減 enable 技能10
        setup();
}
