inherit NPC;
void create()
{
set_name("鯊魚", ({ "shark" }) );
set("age",12);
set("level",35);
set("long", @LONG
一隻飢餓的鯊魚, 正不懷好意的盯著你看...
LONG
);
set("race","野獸");
//set_temp("apply/armor",130);
//set("coin",260+random(130));
set("chat_chance", 8);
set("chat_msg", ({
"鯊魚在你身邊盤旋著．．\n",
 (:command("go south"):),
 (:command("go east"):),
}));
set("limbs", ({ "頭部", "身體", "背鰭", "尾巴","腹部"})); //受攻部位
set("verbs", ({ "bite" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
setup();
}

void init()
{
 if(random(10) > 7)
 {
  kill_ob(this_player());
 }
}
