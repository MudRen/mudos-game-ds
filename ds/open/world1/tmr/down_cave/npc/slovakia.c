// �j���ӤH ��Ǩ� �u��-�u�ʩ��O�v
// -Tmr 2003/08/18

#include <npc.h>
#include <ansi.h>
#define QUEST_STRING "down_cave/slovakia"

inherit F_VILLAGER;

void timeto_eat();

void create()
{
        set_name("������J", ({ "slovakia"}) );
        set_race("human");
        set("age", 35);
        set("gender", "male");
        set("long",@long
������J�@�ӱM���|�B�Ȧ�A�����U�ج��_���j���ӤH�A�@�L���W��
�I�ۭӻ�j���I�]�A�������Y�˦��h�֬é_�j���C
long
        );
                set("title","�j����");
        set("chat_chance", 5);
        set("chat_msg", ({
                "������J���������æa���Y�b�@�ǡA���S���Y�鸣��ۨ��D���t�@��\n",
                "������J��F�A�@���A�N���A�@�A�F.....\n",
                "������J�L�̰�ᦳ��A�n���b������g�����q...\n",
        }));
        setup();
}

void exchange(object player,object ob)
{
    object ring;
        if(ob->id("_QUEST_ITEM_SLOVAKIA_1_") && player->query_temp(QUEST_STRING)==1 ) {
                // card 1
                command("say �z�I�I���§A�F�A���O�Хd�n����T���C...");
                        player->set_temp( QUEST_STRING , 2 );
        } 
        else if(ob->id("_QUEST_ITEM_SLOVAKIA_2_") && player->query_temp(QUEST_STRING)==2 ) {
                // card 2
                command("say ����...�u���A���A�ݯण��A�·ЧA�A���ڧ��ĤT���a�C");
                        player->set_temp( QUEST_STRING , 3 );
        }
        else if(ob->id("_QUEST_ITEM_SLOVAKIA_3_") && player->query_temp(QUEST_STRING)==3 ) {
                // card 3
                command("ya");
                command("say �ӴΤF�A�ڥi�H�������}�o�Ӱ��a��A�^�a�h�ոճo�ڹC���F�C");
                command("say �o�ӬO�ګe�}�l�ߨ쪺�٫��A�N�e���A���O��§�F�a�C");
                command("wave");
                player->delete_temp( QUEST_STRING);
                ring = new(__DIR__"obj/spider-ring.c");
                ring->move( player );
                destruct( this_object() );
        }
        else {
                command("say ���§A�F�A���M���O�ڻݭn���F��C");
        }
        destruct(ob);
}

int accept_object(object me, object ob)
{
       if( (!ob->id("_QUEST_ITEM_SLOVAKIA_1_")
        && !ob->id("_QUEST_ITEM_SLOVAKIA_2_")
        && !ob->id("_QUEST_ITEM_SLOVAKIA_3_") )
        || is_fighting() )
           {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
       do_chat(({ (: exchange,  me,ob :) }) );
       return 1;
}


/* Quest:�i�Ѩ� +int 1 gloves */
void relay_say(object ob, string arg)
{
        if( ob->query_temp( QUEST_STRING ) ) return;
        if( strsrch(arg,"�g�����q")!=-1  )  {
              command("say �N....�p�n�I�A���n���o�䪺�Hť��A�K�o�Q�L�̵o�{�ڨӳo�઺�N�ϡC");
        }
        if( strsrch(arg,"�N��")!=-1  )  {
              command("say �ڷ�M���|���X�ڪ��N�ϬO�n�ӳo���g�����q�M�Ϊ��O�Хd�C");
              command("smirk");
              return ;
        }
        if( arg=="�O�Хd" )  {
              command("say �x....�A��a���D�F�H�H");
              command("say �O�ڡA�ѹ��A���F�Ať���w���������H�b�e�}�l�ߨ�F�A��ť������N�ӬݬݤF..");
              command("say �����A�O�_�����ڧ��ݬݰڡH");
              command("wink");
              return ;
        }
        if( arg=="�i�H" || arg=="�n"  )  {
              command("say �n�A�u�O���±z�F�A�ڴN�b�o�൥�ۧA�a�C");
                  ob->set_temp( QUEST_STRING , 1 );
              return ;
        }
}
