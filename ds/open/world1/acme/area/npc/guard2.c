#include <ansi.h>
inherit NPC;
void create()
{
        set_name("神武護衛" , ({ "guard" }) );
        set("level",12);
        set("race","人類");
        set("gender","男性");
        set("age",25);
        set("int",5);
        set("str",20);
        set_skill("godsword",20);
        set_skill("sword", 30);
        set_skill("parry", 18);
        set_skill("mirage-steps",15);
        set_skill("dodge", 20);
        set("long","他是守護神武大門的護衛，看來武功\並不弱。\n");
        set("chat_chance_combat",100);
        set("chat_msg_combat",({
            "神武護衛喝道：兄弟們！把這傢伙給宰了！\n",
            (:command("exert godsword"):),
            (:command("exert mirage-steps"):),
        }) );
        setup();
        carry_object(__DIR__"wp/longsword.c")->wield();
           carry_object(__DIR__"eq/surcoat.c")->wear();
}
void init()
{
       object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("神武護衛對你喝道：走開！走開！這裡豈是你能來的！\n");
               break;
        }
}

