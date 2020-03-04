//u/c/chiaa/obj/mob/toad.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("癩蛤蟆", ({ "toad" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age",3 );//年紀
set("long", "一隻在地上慢慢跳著的癩蛤蟆\n");//人物敘述
set("str",3 );//膂力
set("cor",3 );//膽識
set("int",0 );//悟性
set("spi",0 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",3 );//根骨
set("limbs", ({ "頭部", "身體", "前腳", "後腳" }) );//身體部位
set("verbs", ({ "bite", "claw", "hoof"}) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 350);//人物經驗
set("potential", 6);//潛能
set_temp("apply/attack", 7);//攻擊力
set_temp("apply/armor", 7);//防禦力
add_money("coin",200);//得到的金錢coin silver gold
set("max_gin", 15);//精最大值
set("max_kee", 150);//氣最大值
set("max_sen", 15);//神最大值  

setup();
  
}

