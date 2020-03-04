//u/c/chiaa/obj/mob/lizard.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("蜥蜴", ({ "lizard" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age",3 );//年紀
set("long", "一隻在樹上爬著的蜥蜴\n");//人物敘述
set("str",1 );//膂力
set("cor",0);//膽識
set("int",0 );//悟性
set("spi",1 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",1 );//福緣 
set("con",3 );//根骨
set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );//身體部位
set("verbs", ({ "bite", "claw","crash" }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 300);//人物經驗
set("potential", 8);//潛能
set_temp("apply/attack", 8);//攻擊力
set_temp("apply/armor", 8);//防禦力
set("attitude", "aggressive");//自動攻擊
add_money("coin",250);//得到的金錢coin silver gold
set("max_gin", 15);//精最大值
set("max_kee", 200);//氣最大值
set("max_sen", 15);//神最大值  

setup();
  
}

