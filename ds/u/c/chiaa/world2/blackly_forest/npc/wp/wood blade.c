#include <weapon.h> //定義武器
#include <ansi.h>   //定義色碼
inherit BLADE;   //大寫

void create()
{
  set_name(YEL"木刀"NOR,({"wood blade","blade"}) );
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","把");//武器的單位
      set("long","一把用木頭刻成的刀\n");//武器敘述
      set_weight(100);//武器的重量
      set("value",15);//武器的價值
      set("material","wood");  //材質 
      }
        init_blade(5);     //武器攻擊力 
setup();
}
