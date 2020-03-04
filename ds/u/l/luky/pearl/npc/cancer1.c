inherit NPC;
void create()
{
set_name("小螃蟹", ({ "little cancer","cancer" }) );
set("age",6);
set("level",13);
set("long", @LONG

一隻活潑的小螃蟹正在曬太陽。
    ∪           ∪
     ＼  ☉  ☉ ／ 
     ︽╭┴─┴╮︽
     ︽│      │︽
       ╰───╯
LONG
);
set("race","野獸");
set_temp("apply/armor",130);
set("coin",260+random(130));
set("chat_chance", 6);
set("chat_msg", ({
"小螃蟹忽地吹出了一個透明的小泡泡...\n",
"小螃蟹快速的爬過你的跨下．．\n",
}));
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
setup();
}


