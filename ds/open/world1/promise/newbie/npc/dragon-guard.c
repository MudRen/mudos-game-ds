#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�u���s"NOR, ({ "dragon guard","dragon","guard" }));
        set("long","�޲z���s�𪺦u�áC\n");

        set("race","���~");
        set("level", 1);
        set("no_kill",1);
        set("no_fight",1);
        set("age", 100);

        set("limbs", ({ "�s�Y","����","���","Ĳ��","�e�}","��}","�I�_" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",1000);
}

void init()
{

       ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg, object me)
{ 
        if( (arg!= "enter") || me->query("level") > 15 || !this_player()->visible(this_object()) ) return 0;
        write( name() + "�N�A�d�F�U�ӡC\n");
      command("gan");
           say("�u���s���G"HIR"�o�̤��A�X�A�h�A�ЧA�d�U�I�I\n"NOR);
        return 1;
}


