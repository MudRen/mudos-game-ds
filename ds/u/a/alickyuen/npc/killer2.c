inherit NPC;
void create()
{
set_name("殺手",({"killer"}));
set("long", " 只殺外來人，你以成為他的目標了！\n");
set("race","機器人");
set("age", 30);
set("level", 25);
set("max_hp", 1000);
set("max_mp", 1000);
set("max_ap", 1000);
set("attitude", "killer");
set("evil", 99);
set("combat_exp",100);
set_skill("sword", 100);
set_skill("dodge", 100);
set_skill("parry", 100);
set_skill("unarmed", 100);
set("chat_chance_combat", 100);
setup();
carry_object( __DIR__"obj/srubber.c");
}