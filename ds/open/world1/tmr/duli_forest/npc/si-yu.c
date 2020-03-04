#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name("����", ({ "si-yu","yu" }) );
        set("long",@long
���ɪ����D�`�G�B���B�@����h�{�p���O�֥]�����u�\�A���۫D�`��
�Q�H���w�A���O�o���k��M�k�ϱo�ᬰ�뮫�A�M�k�Ԥh�p��]�O���f����
�A�M�`�H���Q�n�M�o�̻��W�ӥy�ܡA�ˤ]���e���C
long
);
        set_race("strength");
        set("gender","female");
        set("age", 40);
        set_attr("str",25);
        set_skill("blade",50);
        set_skill("secondhand blade",50);
        set_skill("dodge",50);
        set_skill("parry",50);
        set("title","�k�M��");

        set_attr("str",25);
        setup();
        advance_stat("hp",200);
        set_level(10);                 
        carry_object("/d/obj/blade")->wield();
        carry_object("/d/obj/kris")->wield("secondhand blade");
        carry_object(__DIR__"obj/black-bodysuit")->wear();
}

void relay_say(object ob, string arg)
{
        if( arg=="�Z�\\"
         && ob->query_temp("quest_finger_guessing")==2 )
        {
              command("say ��..�ڦ��M�u�����v�A���M�ۦ���²�A���O�¤O�Q���A�A�n�ǶܡH");
              ob->set_temp("quest_finger_guessing",3);
              return ;
        }

        if( arg=="�n" && ob->query_temp("quest_finger_guessing")==3 )  {
              if( ob->query("skills_point")+1 > SKILL_MAX_POINT 
                 || ob->query_learn("finger-guessing fist")
              ) {
                      command("sigh");
                      command("say ���@�z�O�Ǥ��_�Ӫ��A���L�٬O���±z�o���������C");
                      ob->delete_temp("quest_finger_guessing");
                      return;
              }
              message_vision(CYN"$N�N�������f�Z�M�ۦ��ԲӦa�е��F$n�C\n"NOR,this_object(),ob );
              tell_object(ob,HIG"(�A���ޯ�ǲ��I�ƪᱼ�@�I�C)\n" NOR);
              ob->add("skills_point", 1 );
              ob->delete_temp("quest_finger_guessing");
              ob->improve_skill("finger-guessing fist",100);
              return ;
        }
        if( arg=="���n"
        && ob->query_temp("quest_finger_guessing")==3
         )  {
              command("say �n�a�A���L�٬O���±z�������C");
              ob->delete_temp("quest_finger_guessing");
              return ;
        }
}

void init() 
{
        object me=this_player();
        if(me->query_temp("quest_finger_guessing")==2) {
		command("say ��ӬO�z���F�ڦp��j�f�����@�A�z�O�ӾǪZ�\\���ܡH");
        }
}


