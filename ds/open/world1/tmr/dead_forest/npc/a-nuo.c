// ��-����(lock-chain) Quest
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
    set_name( "���J����" , ({ "maike a-nuo","nuo","maike" }) );
    set("long",@long
    ���J���լO�j�~�H�x�Τ��h��ѭx�H�A�����`��⪺���W�ֽ�
�W�G���j�j�p�p���u�աB�M�S�˵����P���ˤf�A�ݪ��X�Ө��g�ʾԡA
�u�O�~���w���Ӱh��i�ѡC
long
);
    set_race("strength");
    set("title", "�j�~�H�ֱN" );
    set("age", 70 );

    set("chat_chance", 5 );
    set("chat_msg", ({
        "���J���ձ�۫e��A�y�W����o���O�ܰ���...\n",
        "���J���զۨ��ۻy�D�G�u�o�b�~�H�̳̪���G�b�p�e����ԨơA�i�u���H�N���z...�v\n",
        "���J���զۨ��ۻy�D�G�u�b�o��]�u�మ�����A�u�O�����b�~�H�̦b���Ǥ�����...�v\n",
    }));

    setup();
    set_level( 5 );
}

int accept_object(object me, object ob)
{
       if( ob->query_learn("lock-chain") ) return 0;
        if( is_fighting() ) {
               do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }

       if( ob->id("_CRUSH_BONE_WAR_PLAN_") && me->query_temp("quest-lock-chain")==1 ) {
                do_chat( ({
                        "���J���ղӲӦa�\Ū�_�@�ԭp�e�A�y�W����o�O�V�ӶV����...\n" ,
                        "���J���ե��Ѫ��Ĥ@�n�G�u�o�i�O�ѭn�`�ڤ@�ڰڡA�o���ԭp�e���p���P�ԡA�ڥ��䤣�X����}��...�v\n" ,
                        (:command("cry"):) ,
                        "���J���դS�ĹD�G�u���D������H���몺����̡A�n���M�L�q��Ĺ�o���԰��C�v\n" ,
                        "(�A�ߤ��}�l�Ŷq�ۤw����O�A�����O�_�n���o�Ӧ��C)\n" ,
                        ( : destruct , ob : ),
                }) );
                me->set_temp( "quest-lock-chain" , 2 );
                return 1;
        }

       if( ob->id("_CRUSH_BONE_BLOOD_") && me->query_temp("quest-lock-chain")==2 ) 
        {
                // ��G
                do_chat( ({
                                        (:command("wacow"):) ,
                        "���J���եJ�ӺݸԤF�o�~��G�A���G���b�T�w�����ӷ�...\n" ,
                        "���J���դj���_�ӡG�u��!!���§A���ڭ̱ڤ@�Ӥj���A�N���Ӫ��ӫҵ��_�F�C�v\n" ,
                        "���J���կ���M���a��ۧA�D�G�u�ݧA����ΡA���p�ѧڨӶǧA�@�ۨ������\�ҧa�A�����A�N�U�p��H�v\n" ,
                        ( : destruct , ob : ),
                }) );
                me->set_temp( "quest-lock-chain" , 3 );
                return 1;
       }
        
        do_chat((: command, "say �A���ڳo�ӷF���H" :));
        return 0;
}

void relay_say(object ob, string arg)
{
          // �w�Ǳo���媺�H�A�h�����A�ѤF
        if( ob->query_learn("lock-chain") ) return;
        if( arg=="�b�~�H")  {
                do_chat(
                        ({
                            "���J���չ�ۧA�j�|�_�ӡG�b�~�H�O�ڱڪ����ġA�����P���Ѥ����A�A�̦n���n�A����e�̤F...\n",
                        "���J���ծ�I�I�a�@�I�]�����O�ѤH...\n",
                    })
            );
            return ;
        }
        if( arg=="�Ԩ�")  {
                do_chat( ({
                  "���J���ջ��D�G�u�ڭ̨�ڤw�g�o�ͤj�j�p�p���Ԫ����U�Ʀʦ��F�A���֤]���S���u���������C�v\n",
                  "���J���ջ��D�G�u�u�O��~�ӥb�~�H�֥ߪ��s�ӫҦ��w���~�A�N��y�H����g�窺���n����...�v\n",
                  "���J���չy�F�y�A�S�~�򻡹D�G�u�̪�Ǩ��H���륿���K�p�e�@���j�Ԫ��A���ڭ̱ڤH�o���M�����Y���A�u�O���H��~��...�v\n",
                  "(�A�߷Q�γ\�h�H���먫�@��A�γ\�ள�줰��p�e�Ѥ������]�����w)\n",
                    }) );
            ob->set_temp("quest-lock-chain" , 1);
            return ;
        }
        if( ob->query_learn("lock-chain") ) return;
        if( ob->query_temp("quest-lock-chain") == 3 ) {
        
                           if( arg=="�n") {
                                        message_vision( CYN "���J���ժ��l�F�f��A�y�W����®e�_�ӡA���۶}�l�񹺰_�@���ꪺ���...\n"  NOR , ob);
                                        if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
                                                tell_object( ob , CYN "(���O�A�����ݤ����L�Ҥ񹺪��N�q...)\n" NOR );
                                        }
                                        else {
                                                        tell_object( ob , CYN "\n(�A���G���u��-����v�o�ӧޯ঳�Ӫ�B���{�ѤF...)\n" NOR );
                                                        tell_object( ob , HIY "\n(�A���ޯ��I�ƴ�֤T�I�F�C)\n" NOR );
                                                        ob->improve_skill( "lock-chain" , ob->query_attr("cps") );
                                                        ob->add("skills_point" , 3 );
                                        }
                                        ob->delete_temp( "quest-lock-chain" );
                                        return;
                                }
                                if( arg=="���n") {
                                                do_chat( ({ "���J���չD�G�u���n�A�ڷ|�^�h�ڭ̱ڸ̫Ŵ��A�����ݪ��C�v\n" }) );
                                                ob->delete_temp( "quest-lock-chain" );
                                                return;
                                }
                }
}


