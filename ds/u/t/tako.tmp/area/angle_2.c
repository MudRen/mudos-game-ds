#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�B", ({ "ice" }) );
        set("gender", "�k��");
        set("level",35);
        set("age",random(100));
        set("evil",-200);
        set("title",HIW" �Z�Ѩ� "NOR);
        set("long",@LONG
�W�Ѭ��ӱo�Ϫ�,���F����[31m�E��[0m
LONG
);
        set_skill("sorgi_sword",70); 
        set_skill("fogseven",70);
        set_skill("sword",70);
        set_skill("dodge",70);   
         set("chat_chance", 12);
        set("chat_msg", ({
  "�B�����G��..��..��򪾹D��..�ڤ]�����L�h..�C\n",

}) );      set("chat_chance_combat",35);
        set("chat_msg_combat", ({
                  (: command("exert sorgi_sword") :),
                  (: command("exert fogseven") :),
                                     (: command("exert sorgi_sword") :), 
                  (: command("exert sorgi_sword") :),
         }) );
        setup(); 
        carry_object("/u/t/tako/wind sword")->wield();
}

void die()
{
        object killer;
        int last;
        if(random(7))
        {
                if(killer=this_object()->query_temp("last_damage_from"))
                {
                        last = killer->query("max_hp")/10;
                        if(last < killer->query("hp"))
                        {
                                message_vision(HIW"
  $N��:�ڸ�A�P�k���,$N�ϥX�@�� [�B] $n�F����{�N�O�פ��F�C\n"NOR,this_object(),killer);
                                last=killer->query("hp")-last;
                                killer->receive_damage("hp",last,this_object());
                        }
                }
        }
        ::die();
}





