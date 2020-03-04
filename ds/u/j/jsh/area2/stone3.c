#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"���]���H"NOR, ({ "evil man-stone","stone" }) );
        set("race","beast");
        set("gender", "�k��");
        set("level",40);
        set("age",2014);
        set("evil",-20); 
        set("title",MAG"�g�c�u�@��"NOR); 
        set("long",@LONG
 ���]���H�A�O���F���J�I�j�ӸT�a���H�ҳ]�p���A���j
 �A�e�ӡA�������ۤl��K�a���X�A�����@�j�Ӫ����Ū�
 ���n�\�ڡC
LONG
);
        set_skill("bagi_fist",80); 
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set_skill("combat",90);
        set("attitude","aggressive");
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                  (: command("exert bagi_fist") :), 
                  (: command("exert bagi_fist") :), 
       }) );
        setup(); 
        carry_object(__DIR__"stone-armor")->wear();
        carry_object(__DIR__"stone-fist")->wield();
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
                                message_vision(HIW"  $N��������G���ǲ��`..."HIR"�I"HIW"���@�n...$n�Q�z�g�}�Ӫ��ۤl���o�����O�ˡC\n"NOR,this_object(),killer);
                                last=killer->query("hp")-last;
                                killer->receive_damage("hp",last,this_object());
                        }
                }
        }
        ::die();
}

