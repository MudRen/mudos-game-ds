#include <npc.h>
#include <ansi.h>

void create()
{
        set_name("�p��", ({ "ru hua","hua" }) );
        set("long",@long
�p��O�o�@�a���W���Ԥh�A���o���y��סA�|�ϵo�F�A�H���t�Z�O��
�X�W�A�M�`�����~�]���H��˦o�a�C�@�o�����⾮�������G�b�|�B�M�䤰
��F��C
long
);
        set_race("strength");
        set("gender","female");
        set("age", 40);
        set_attr("str",25);
        set_skill("twohanded axe",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set("title","�k�Ԥh");
        set("chat_chance", 20);
        set("chat_msg", ({
                "�p����ۻy�D�G���r...���R�F���ڪ��ɧ٫����M�d��F�A�����b���̰�...�C\n",
                (: command("sigh") :),
                (: command("search") :),
        }));
        set_attr("str",15);
        setup();
        advance_stat("hp",200);
        set_level(10);                 
        carry_object("/d/obj/axe")->wield("twohanded axe");
        carry_object(__DIR__"obj/purple-hairpin")->wear();
}

void exchange(object player,object ob)
{
           destruct(ob);
           tell_object(player,GRN"�p��b�A�����仡�D�G�z�n�O�����󪺸ܡA�ڥi�H�Чڪ��n�j�f�Ǳ§A�X�۪Z�\�C\n"NOR);
           player->set_temp("quest_finger_guessing",1);
}

int accept_object(object me, object ob)
{
        object item;
       if(      !ob->id("_OBJ_ID_JADE_RING_")
                || is_fighting()
                || me->query_learn("finger-guessing fist") 
                || me->query_temp("quest_finger_guessing") )
           {
              do_chat((: command, "shake" :));
              return 0;
       }
       command("wa");
       command("say �o�o.....�o�N�O�ڧ�F�n�[���q���٫��ڡA�u�O���§A�ڡC");
       do_chat(({ (: exchange,  me,ob :) }) );

       return 1;
}

void relay_say(object ob, string arg)
{
        if( arg=="�n"
        && ob->query_temp("quest_finger_guessing")==1
         )  {
              command("say ��A���N�бz���r��˪L�~��ڪ����ɩj�f�a�C");
               ob->set_temp("quest_finger_guessing",2);
              return ;
        }
        if( arg=="���n"
        && ob->query_temp("quest_finger_guessing")==1
         )  {
              command("say �n�a�A���L�٬O�����§A�������C");
               ob->delete_temp("quest_finger_guessing");
              return ;
        }
}

