#include <npc.h>
#include <ansi.h>
#include "barbarian_base.c"

void create()
{
        set_name("���Z�H", ({ "barbarian captain","barbarian","captain" }) );
        set("long",@long
�b�A���e�O�@�ӫD�`���������Z�H����A�L���εۧG���嵷�������n
�ۧA�A�L�̳��ۻy�ۧAť�������ܻy�A���G�L��A�R���ķN�C
long
);
        set_race("human");
        set("title","�j����");
        set("age", 45);
        set_skill("twohanded blunt",90);        // �����Ϊk
        set_skill("parry",80);
        set_skill("dodge",80);
        setup();
        set_level(30);
        carry_object(__DIR__"obj/monster_pants")->wear();
        carry_object(__DIR__"obj/tiger-fur-armor")->wear();
        carry_object(__DIR__"obj/monster-waist")->wear();
        carry_object(__DIR__"obj/big-blunt")->wield();
}

void exchange(object player,object ob)
{
        object item;
        destruct(ob);
        message_vision(CYN "$N�T��f�N��㰦�N�n�Y�o����F�C\n" NOR,this_object() );
        message_vision(CYN "$N�q�h�����X�@�T�٫��e���F$n�C\n" NOR,this_object(),player );
        command("smile");
        item=new(__DIR__"obj/jade-ring");
        item->move(player);
}


int accept_object(object me, object ob)
{
        object item;
       if(      !ob->id("_OBJ_ID_DUCK_")
                || is_fighting()
                || me->query_learn("finger-guessing fist") 
                || objectp( item=present("_OBJ_ID_JADE_RING_",me) ) )
           {
              do_chat((: command, "shake" :));
              return 0;
       }
       command("jump");
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}



