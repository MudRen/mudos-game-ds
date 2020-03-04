//u/c/chiaa/obj/mob/hermit crab.c

#include <ansi.h>
inherit NPC;
void create()
{
set_name("寄居蟹", ({ "hermit crab" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age", 5 );//年紀
set("long", "一隻在沙灘上爬來爬去的寄居蟹\n");//人物敘述
set("str",1 );//膂力
set("cor",1 );//膽識
set("int",0 );//悟性
set("spi",0 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",0 );//根骨
set("limbs", ({ "頭部", "身體", "前足" }) );//身體部位
set("verbs", ({ "bite", "crash" }) );
//攻擊型態蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 100);//人物經驗
set("potential", 10);//潛能
add_money("coin",100);//得到的金錢
set_temp("apply/attack", 5);//攻擊力
set_temp("apply/armor", 5);//防禦力
set("chat_chance",10 );//百分比動作機率
set("chat_msg",({"寄居蟹撿起沙灘的沙子來吃\n", 
       (: random_move :), //隨機亂走 
}) );//動作敘述

set("max_gin", 10);//精最大值
set("max_kee", 100);//氣最大值
set("max_sen", 10);//神最大值 

    setup(); 
}

