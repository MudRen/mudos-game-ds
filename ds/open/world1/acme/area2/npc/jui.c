#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "�R��", ({ "chong jui","chong","jui", "__GUARD__" }) );
        set("level",15);
           set("combat_exp",1500);
        set("long" ,
            "�L�O�խߦa�������ըϡA�q�p�N�ߴժk�A���b�@���ԧФ��A�������F����\n"
            "�q���Z�\\�j�h�A�u��_�H���\\�O���T���A�q�L�������i�ݨ��@�������C\n"
           );
        set("age",30);
        set("gender","�k��");
           set("attitude","killer");
       set("evil",45);
        set_skill("dagger",30);
//    set_skill("darkdagger",30);
        set_skill("dodge",30);
        set_skill("parry",30);
     set("chat_chance_combat",70);
        set("chat_msg_combat", ({
           (:command("exert darkdagger"):),
        }) );
        setup();
        carry_object(__DIR__"wp/dagger.c")->wield();
     carry_object(__DIR__"eq/finger.c")->wear();
}
