//u/c/chiaa/obj/eq/conch_helmet.c

#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
  set_name(WHT"貝殼"HIG"之"HIC"帽"NOR ,({ "conch helmet","helmet" }));
  set("long", "這是用海底貝類生物加工而成的頭盔,可以看到有著螺旋狀的條紋\n");
    set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "頂" );
                set("material", "conch");  //材質 貝殼
                set("limit_con",12);  //限制根骨體質15
                set("armor_prop/armor",  10);  //防禦力+10
                set("armor_prop/shield", 1);   //抵抗+1
                set("value", 2000); //價值
        }
 set("weapon_prop/dodge",5);        //加 enable 技能5

        setup();
}
