#include <ansi.h>

inherit NPC;
void create()
{
        set_name("����",({ "villager" }) );
        set("long","�@�ө~��b�y�����������A���G�`�`�X�h�y�ɪ��W�A���֥H�k�f�E\n");
        set("race","�H��");
        set("title",HIR"�y����"NOR);
        set("age",30+random(5));
        set("level",15+random(5));
        set("attitude","friendly");
        set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set("chat_chance",20);
        set("chat_msg", ({
                        (: command("say �٤��֨��I"):),
                        (: command("pk")            :),
        }));
   setup();
add_money("silver",8);           
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
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
   command("kick "+ me->query("id"));
   command("say �o��" + RANK_D->query_respect(ob) + "�A����H�K�N���J�O�H���a�̩O�H\n" ); 
}
