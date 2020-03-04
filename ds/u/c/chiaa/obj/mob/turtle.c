//u/c/chiaa/obj/mob/turtle.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("海龜", ({ "turtle" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age",3 );//年紀
set("long", "一隻在沙灘上曬太陽的海龜\n");//人物敘述
set("str",2 );//膂力
set("cor",0 );//膽識
set("int",0 );//悟性
set("spi",0 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",2 );//根骨
set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );//身體部位
set("verbs", ({ "bite", "crash","claw"  }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 100);//人物經驗
set("potential", 5);//潛能
set_temp("apply/attack", 6);//攻擊力
set_temp("apply/armor", 8);//防禦力
set("chat_chance",15 );//百分比動作機率
set("chat_msg",({"海龜在沙灘慢慢得爬著\n",
       (: random_move :), //隨機亂走 
}) );//動作敘述

add_money("coin",150);//得到的金錢coin silver gold
set("max_gin", 10);//精最大值
set("max_kee", 100);//氣最大值
set("max_sen", 10);//神最大值  

setup();
  
}
