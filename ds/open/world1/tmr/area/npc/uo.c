#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
        set_name("���W", ({ "a-uo","uo" }) );
        set("title", "�H�O����");
        set("gender", "�k��" );
        set("long",@long
���W���@�ө���ѫ��B�ɿ����H�O�����A�ݰ_�ӴN�O�@�y�ѹ�ˡC
long
        );      
        set("age",20);
        set("level",5);
        set("race","human");
        set("chat_chance", 10);
        set("chat_msg", ({
             "���W���D�G��ѫ����ѭ��ȴ̡A�u�n�@�ʤ���N���F�C\n",
             "���W�ݤF�ݧA�@���C\n",
             "���W���D�G��ɿ��D�W���¤Ѵ�A�u�n���Q����N��F�C\n",
        }));


        set("chat_chance_combat", 50 );        
        set("chat_msg_combat", ({
                "���W�s�D�R���H���T���H���T\n",
         }) );
  
        setup();
}

int accept_object(object who,object ob)
{
        
        if(ob->query("id")!="coin" ) return 0;
        if (ob->query_amount() == 50)
        {
                command("smile");
                 message_vision(HIY "$N���F���W���Q����A���W�F�H�O�����ɿ�����V�b�h�C\n" NOR ,who);
                who->receive_money(- ob->query_amount() );
                who->move(TMR_PAST+"area/square");
                this_object()->move(TMR_PAST+"area/square");
                return 1;
        }
        if (ob->query_amount() == 100)
        {
                command("smile");
                  message_vision(HIY "$N���F���W�@�ʤ���A���W�F�H�O�����ѫ�����V�b�h�C\n" NOR ,who);
                who->receive_money(- ob->query_amount() );
                who->move(ACME_PAST+"area/st");
                this_object()->move(ACME_PAST+"area/st");
                return 1;
        }
        command("say �o��x���A�A�n�쨺�O�H�H\n");
        return 1;
}

