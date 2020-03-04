#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("���p��", ({ "jiang grass","grass" }) );
        set_race("human");
        set("age", 10);
        set("long", "�@�Ӧ~�����X���A�y�W���G�d�ۨ���\���A���G����L�A�����L�o�ͤF����ơC\n");
        set("chat_chance", 5);
        set("chat_msg", ({
                "���p����S���F�y�W���\�w�C\n",
                (: command("sigh") :),
                (: command("cry") :),
        }));

        setup();
}

int accept_fight(object ob)
{
        return 0;
}

void exchange(object player,object ob)
{
        destruct(ob);
        command("say �u�O���§A�A���ڥi�H��ߦ^�a�F�C");
        command("wave");
        player->set_temp("duli_village/lost_child",1);
        destruct( this_object() );
}

int accept_object(object me, object ob)
{
       if(      !ob->id("_OBJ_ID_QUEST_JAWEI_")
                || is_fighting()
                || me->query_temp("duli_village/lost_child")
                || me->query_learn("isolate sword")  )
           {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
       command("smile");
       command("say ��....�A���ڧ��F�H�H�A�u�O�F�`�C�I�I");
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:�i�Ǩ� �k���B���� �C�k */
void relay_say(object ob, string arg)
{
        if( ob->query_learn("isolate sword") ) return;
        if( ob->query_temp("duli_village/lost_child") ) return;
        if( strsrch(arg,"��")!=-1
        || strsrch(arg,"�����")!=-1
        )  {
              command("say ��.....�ڤ����^�a�F�A�ڧ⪺�ݷݪ��F��Τ����F...���");
              return ;
        }
        if( arg=="�ݷݪ��F��"  )  {
              command("say ��..��...�ڬQ�ѤU�ȱa�h���䪱�ɡA���p�߱��b���̤F..");
              command("sigh grass");
              return ;
        }
}

