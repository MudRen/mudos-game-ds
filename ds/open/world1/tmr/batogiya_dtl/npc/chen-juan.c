// �ӷ���(taiji-quan) Quest
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name( "����" , ({ "chen juan", "chen", "juan"}) );
        set("long",@long
�@�@������ۥ��e�A���������A���D�]���G�A�@���X����S�O���B
long
);
                set("title","�ӷ����̤l");
        set("age",25);
        set_skill("sword",100);
        set_skill("taiji-sword",100);
        map_skill("sword", "taiji-sword");

        set("chat_chance", 10 );
        set("chat_msg", ({
                        "�����ۦۤw���D�G�u���f�X�~�C���A�`�n���X�Ǥ���W��a�C�v\n",
                        "����̤����a�W�ۯ��F�_�ӡA���G�Q�줰��o�N���B�C\n",
                        "���驿�M�m�_�@�M�C�]�]�������A�A�@�F�b�Ѥ]�ݤ����C\n",
        }));
        setup();
          set_level( 15 );
          carry_object(__DIR__"obj/taiji-sword-book");
          carry_object("/d/obj/sword")->wield();


}

void relay_say(object ob, string arg)
{
           object card;
            if( ob->query_learn("taiji-quan") ) return;

        if( arg=="����W��" || arg == "�W��")  {
                do_chat( ({
                                "���黡�D�G�u�ҿתꦺ�d�֡A�H���d�W�A���p�ǪZ���H�A�`�O�Ʊ�঳�I�W�n�a�C�v\n",
                                "����ܤ@�����A�S�}�l�m�_������...\n",
                    }) );
            ob->set_temp("taiji-quan-quest" , 1);
            return ;
        }

        if( ob->query_temp("taiji-quan-quest") == 1 && arg=="�W�n") 
        {
                        do_chat( ({
                                        "����ĹD�G�u��....���ڳo���q�q�L�W�A�S�Z���C�L�A�u������ɤ~��X�H�Y�a�C�v\n",
                                        "(�z���b����঳����k�l�A�i�H���L���W�߸U�C)\n",
                            })     );
                    ob->set_temp("taiji-quan-quest" , 2);
                return;
                }

        if( ob->query_temp("taiji-quan-quest") == 2 && arg=="���W�߸U") 
        {
                     do_chat( ({
                                        (: command("hmm") :) ,
                                        "����C�n���G�u�ڴ�ť�B�ʹ��L�A�b���`�˪L���䦳�k�l���o�㦳�S���O���d��...�v\n",
                                        "����y�F�@�U�A�S�~�򻡡G�uť�����ണ�ɧA�b�o�ӥ@�ɪ��W�n�O�I�I�v\n",
                                        "(�z�Q�γ\�ӥh���`�˪L������a�C)\n",
                            })     );
                    ob->set_temp("taiji-quan-quest" , 3);
                return;
                }

       if( ob->query_temp("taiji-quan-quest") == 4 )
       {
                        if( arg=="�n" || arg=="�Q")  {
                                message_vision( CYN "\n����N���۫��դΤf�Z�J�ӶǱµ�$N....\n" NOR, ob );
                    if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
                                        tell_object( ob , CYN "(���O�A����ť�����L���������e...)\n" NOR );
                                } else {
                                        tell_object( ob , CYN "\n(�A�Ǩ�F�ӷ����I�I)\n" NOR );
                                        tell_object( ob , HIY "\n(�A���ޯ��I�ƴ�֤T�I�F�C)\n" NOR );
                    ob->improve_skill( "taiji-quan" , ob->query_attr("int") );
                                    ob->add("skills_point" , 3 );
                                }
                                do_chat( ({ "���餣���a���N��W���d���A���G�D�`�����C\n" }) );
                                ob->delete_temp( "taiji-quan-quest" );
                                return;
                        }
                        
                        if( arg=="���n" || arg == "���Q" ) {
                                do_chat( ({ "����D�G�u�]�n�A�ڷ|�N�A�������ʰO�b�ߡC�v\n" }) );
                                ob->delete_temp( "taiji-quan-quest" );
                                return;
                        }
                }
}

void exchange( object player, object card )
{
        destruct(card);
    if( !player || environment(player) != environment() ) return;
        player->set_temp("taiji-quan-quest", 4);
}
 
int accept_object(object me, object ob)
{
       if( !ob->id("_55_CARD_")
           || me->query_learn("taiji-quan")
           || me->query_temp("taiji-quan-quest") != 3 )
              return 0;

                do_chat( ({
                        (: command("wa") :) ,
                        "���鮳�ۥd���A���T�P�ʦa���U�Ӳ\��...\n" ,
                         "����D�G�u�u�O�����§A�F�A�ڳo�঳�@�M���k�A�Q�n�Ǳµ��A�A�H�P�§A�������A�����A�N�U�p��H�H�v\n",
                (: exchange, me, ob :) ,
                }) );
       return 1;
}


