//u/c/chiaa/obj/mob/boa.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("蟒蛇", ({ "boa" }) );//名字
set("race", "野獸");//種族
set("gender", "雌性" );//性別
set("age",3 );//年紀
set("long", "一條捲軀的蟒蛇\n");//人物敘述
set("str",2 );//膂力
set("cor",0 );//膽識
set("int",0 );//悟性
set("spi",0 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",3 );//根骨
set("limbs", ({ "頭部", "身體", "尾巴" }) );//身體部位
set("verbs", ({ "bite", "crash" }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 300);//人物經驗
set("potential", 9);//潛能
set_temp("apply/attack", 8);//攻擊力
set_temp("apply/armor", 8);//防禦力
set("attitude", "aggressive");//自動攻擊
add_money("coin",250);//得到的金錢coin silver gold
set("max_gin", 10);//精最大值
set("max_kee", 200);//氣最大值
set("max_sen", 10);//神最大值  

setup();
  
}

