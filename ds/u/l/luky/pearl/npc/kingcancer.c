inherit NPC;
void create()
{
set_name("霸王蟹", ({ "king cancer","cancer" }) );
set("age",30);
set("level",41);
set("long", @LONG
一隻十分巨大的螃蟹, 細長的腳有著尖銳的倒刺.
LONG
);
set("race","野獸");
//set_temp("apply/armor",130);
//set("coin",260+random(130));
//set("chat_chance", 8);
//set("chat_msg", ({
//"．．\n",
//}));
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
set("verbs", ({ "bite","claw","crash" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
setup();
}

void init()
{
 if(random(20) > 17)
 {
  kill_ob(this_player());
 }
}
