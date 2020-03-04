// ����ɶ�(the-time) Quest 2004/05/27
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name( "�w�Զ뺸" , ({ "kulasaier" }) );
        set("long",@long
    �w�Զ뺸�O�����G�z���k�l�A���ۻᬰ�^���T�q�A���H���F�N
�����T���n�P�C�M�ӥL�o�㪺�{�{���w�A���G���L����d�G���L�h��
�H���h�C�A�`�N��L�֦��@���D�`�����A�R�����Ⲵ�]�A�V�ݶV�O�g
�ĳo�@�ɤW��|���o����R���C��C
long
);
        set_race( "special" );
        set("title", "�]�c���" );
        set("age", 45 );
        set("chat_chance", 5 );
        set("chat_msg", ({
                        "�w�Զ뺸�`�`�ĤF�f��A���T�y�S�X�@�ѷ��״d�˫s�誺����...\n",
        }));
        setup();
        set_level( 20 );
}

int accept_object(object me, object ob)
{
           if( ob->query_learn("the-time") ) return 0;
       if( !ob->id("_THE_TIME_QUEST_") || is_fighting() ) {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
        me->set_temp( "the-time-quest" , 1 );
                do_chat( ({
                        "�w�Զ뺸���ۤ��������A���T�éæa�y�U��沴�\......\n" ,
                        "�w�Զ뺸�C�|�a���D�G�u�u�O���§A�������A�����ٯ�A����ڤH����...�v\n" ,
                        "�w�Զ뺸�w�F�f��A�S�~�򻡹D�G�u�ڷQ�γ\�A��ڭ̱ڤH�]�O���t�a�A�ڦ��@�M�ѯ��v�ǤU�Ӫ����k...�p�G...�v\n" ,
                        "�w�Զ뺸�����S��A�S�~�򻡹D�G�u�p�G�A�@�N���ڭ̱ڤH�������ܡA���@�N�ǧA�o�M���k...�v\n" ,
                        ( : destruct , ob : ),
                }) );
       return 1;
}
void relay_say(object ob, string arg)
{
           object letter;
           // �w�Ǳo����ɶ����H�A�h�����A�ѤF
            if( ob->query_learn("the-time") ) return;

        if( arg=="�]�c���")  {
                do_chat(
                        ({
                                "�w�Զ뺸�n�F�n�Y���D�G�u�o�ӱڦW�H��N�u�|�A�X�{�b���v�W�F�A�Ҧ����ڤH�������F...�v\n",
                    })
            );
            return ;
        }
            if( !ob->query_temp("the-time-quest") ) return;  

                        if( arg=="�@�N") {
                                message_vision( CYN "�w�Զ뺸���b$N����A�C�n�a���z�@�s�꦳�p�G��몺���e....\n" NOR , ob );
                    if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
                        // �ޯ��I�Ƥ���
                                        tell_object( ob , CYN "(���O�A����ť�����L���������e...)\n" NOR );
                                }
                                else {
                                        tell_object( ob , CYN "\n(�Aı�o������鳤յo�X�K���`�h�P�A���ٺ�O�ԭ@����...)\n" NOR );
                                        tell_object( ob , HIY "\n(�A���ޯ��I�ƴ�֤T�I�F�C)\n" NOR );
                    ob->improve_skill( "the-time" , ob->query_attr("int") );
                                    ob->add("skills_point" , 3 );
                                }
                                ob->delete_temp( "the-time-quest" );
                                return;
                        }
                        if( arg=="���@�N") {
                                do_chat( ({ "�w�Զ��¹D�G�u���]�n�A�o�بƬO����j�j��...�v\n" }) );
                                ob->delete_temp( "the-time-quest" );
                                return;
                        }
}


