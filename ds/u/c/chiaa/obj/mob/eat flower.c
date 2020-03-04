//u/c/chiaa/obj/mob/eat flower.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("食人花", ({ "eat flower" }) );//名字
set("race", "野獸");//種族
set("age",1 );//年紀
set("long", "一朵看起來有點恐怖的花\n");//人物敘述
set("str",1 );//膂力
set("cor",3 );//膽識
set("int",0 );//悟性
set("spi",0 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",0 );//根骨
set("limbs", ({ "頭部", "身體","葉子" }) );//身體部位
set("verbs", ({ "bite", "claw" }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 500);//人物經驗
set("potential", 10);//潛能
set_temp("apply/attack", 15);//攻擊力
set_temp("apply/armor", 15);//防禦力
set("attitude", "aggressive");//自動攻擊
add_money("coin",500);//得到的金錢coin silver gold
set("max_gin", 20);//精最大值
set("max_kee", 300);//氣最大值
set("max_sen", 20);//神最大值  

setup();
  
}

