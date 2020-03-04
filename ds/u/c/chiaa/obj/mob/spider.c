//u/c/chiaa/obj/mob/spider.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("蜘蛛", ({ "spider" }) );//名字
set("race", "野獸");//種族
set("gender", "雄性" );//性別
set("age",5 );//年紀
set("long", "文字\n");//人物敘述
set("str",3 );//膂力
set("cor",3 );//膽識
set("int",0 );//悟性
set("spi",3 );//靈性  
set("cps",0 );//定力
set("per",0 );//容貌
set("kar",0 );//福緣 
set("con",3 );//根骨
set("limbs", ({ "頭部", "身體", "前腳", "後腳" }) );//身體部位
set("verbs", ({ "bite", "crash" }) );
//攻擊型態 蹬hoof撞crash咬bite抓claw啄poke
set("combat_exp", 400);//人物經驗
set("potential", 12);//潛能
set_temp("apply/attack", 15);//攻擊力
set_temp("apply/armor", 10);//防禦力

add_money("coin",500);//得到的金錢coin silver gold
set("max_gin", 30);//精最大值
set("max_kee",300);//氣最大值
set("max_sen", 30);//神最大值  

setup();
  
}
