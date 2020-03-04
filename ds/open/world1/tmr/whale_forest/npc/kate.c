/* kate.c
 * �d�S �y�H
 *
 * Quest�G�s��ǲߨ����
 *
 *  -Tmr 2002/02/25
 */

#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_FIGHTER;
// �԰������S��-�M��
int dead_god = 0;

void die()
{
        object ob ;
    ob = last_damage_giver();
    if( !ob || ob==this_object() )

        {
                ::die();
                return;
        }
        
      message("system",
           HIG "�i�y�H�s�D�j" HIW "�|�@�D�W���d�S�y�H���b"+ob->name(1)+"(" + ob->query_id() + ")��W�F�I�I\n"+NOR
        ,users() );

        ::die();
        return;
}
void do_dead_god()
{
        object ob , *enemy;
        int i;
    ob = this_object();
        if( !dead_god ) return;
        dead_god = 0;
        if( !ob->is_fighting() ) {
                // �D�԰���
                message_vision(HIW "$N�⤤���I�M�o�X�@�}���������n�A����N�����F....\n"NOR , ob);
                return; 
        }
        enemy = ob->query_enemy();
        message_vision( HIR "\n$N�@�y�u��������R���v�A�⤤���I�M���}�Ů�������L�|�g���@���ͪ�....\n\n"NOR , ob);
        for( i = 0 ;i < sizeof(enemy) ; i++) {
                        message_vision( "$N" NOR "���W�Q�I�M�������X�@�D�ˤf�C\n"NOR , enemy[i] );
                        if( enemy[i]->query_stat("hp") > 1 ) {
                                enemy[i]->set_temp("damage_shield" , 0 );
                                enemy[i]->damage_stat( "hp", enemy[i]->query_stat("hp") - 1 );
                    COMBAT_D->report_status( enemy[i] );
                        } else
                                enemy[i]->damage_stat( "hp", 2 );
        }
        message_vision( "\n", ob );
        return ;
}

void do_combat_attack() 
{
        object me,ob;
        ob = this_object();
        if( ob->is_busy() ) return;
        me = ob->query_opponent();
        if(!objectp(me)) return;
                if(!dead_god && ob->query_stat("hp") <  ob->query_stat_maximum("hp")/2 && random(3) ) {
                        // ��������R��
                        dead_god = 1;   // �o��
                        message_vision(HIW"\n$N�⤤���M�X�{�@�⥨�j���I�M�A�M�`��ۦ���⪺�u2�v�A�|�g�}�l�j���_�@�����...\n\n"NOR,ob,me);
                        call_out( (: do_dead_god :) , 3 ); // 3���}��..
                } else {
                        message_vision(HIW"$N�����Ť@�A�A�H�Y�o�X�@�D�e�p�P�����M�𪽮g�V$n�I�I\n"NOR,ob,me);
                        if( random(100) > me->query_stat("nina")/15 ) {
                message_vision(HIR"�M�𬽬��A�b$n" HIR "���W�A�G�o$n" HIR"�˰h�T�B�A�y�W��������..\n"NOR,ob,me);
                me->receive_damage( 50 + random(10) , ob , ob);
                        } else
                message_vision(CYN"���O�èS����$n" CYN"�y���v�T�C\n"NOR,ob,me);
        }
}

void create()
{
        set_name("�d�S�y�H", ({ "kate hunter", "kate", "hunter" }) );
        set_race("operation");          // �ާ@�t
        set_class("hunter");            // �y�H¾�~
        set_skill("dodge", 150 );
        set_skill("unarmed", 150 );
        set_skill("blade", 150 );
        set_skill("finger-guessing fist", 150 );
        map_skill("unarmed","finger-guessing fist");     
        set_skill("psychical", 200);

    set("forect_ratio",100);
        set("title","���E�I�O�h���̤l");

        set("gender", "male");
        set("age", 28);
        set("long",@long
�b�A���e�O�@�쨭���G���A���ۤ@���n���n���k�l�A���W�I�ۤ@�Ӥp��
��]�A�ݰ_�ӴN���O�H���q�W���~���C�@�L�|�B�d�ݪ��ˤl�A���G���b��M
����F��άO�u���C
long            
                );

        set("chat_chance", 8);
        set("chat_msg", ({
                 "�d�S�Ĥf�𻡹D�G�u�Q���Ө�L���G�m�A�ݯण����@�I�u���A�窾�D�S���Y��...�v\n(�A�ߤ��t�Q���D�L�O�b��u���E�I�O�h�v�o�W��~�ӳ̰��j���y�H�H�H)\n",
                (: command("sigh") :),
                "�d�S��ۧA�ܹD�G�u�����}�o�̡I�I�o����i�O�������դO�d��I�I�v\n",
                  "�d�S�d���j�F�j�|�g���p�F��A���G�b�䤰�򪫫~...\n",
                (: random_move :),
        }) );

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                "�d�S����ۭY�A�������w�������E�_���ת���....\n",
                (: do_combat_attack :),
                (: do_combat_attack :),
        }) );

        set_temp("apply/armor" , 80);
        setup();
        set_level( 80 );
        //carry_object(__DIR__"obj/wushi-blade.c")->wield();
        carry_object(__DIR__"obj/wushi-blade.c");
        carry_object(__DIR__"obj/blue-jeans.c")->wear();
        carry_object(__DIR__"obj/ancient-belt.c")->wear();
        carry_object(__DIR__"obj/ancient-necklace.c")->wear();
        carry_object(__DIR__"obj/peaked-cap.c")->wear();
         carry_object("/d/cards/card-17")->wear();
}

int accept_fight()
{
        do_chat((: command, "?" :));
        return notify_fail("�d�S��A���欰���Y�L�@ ...�C\n");
}

void init()
{
        if( this_player()->query_learn("psychical") )
        {
                command("smile "+ this_player()->query("id"));
        }
}
int accept_object(object me, object ob)
{
        if( me->query_skill("blue-power") ) return 0;
       if( !ob->id("_BLUE_POWER_CARD_") || is_fighting() || me->query_temp("the-blue-power-quest")!=2 ) {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
          me->set_temp( "the-blue-power-quest" , 3 );
                do_chat( ({
                        "�d�S���T�j�Y�@��A�����a�⪱�o�i�d��...\n" ,
                        "�d�S���D�G�u�o�O�i�ܬöQ���d���A�h�±z�e���ڡA�o�i�d�����q�ܰ�ť���G��...�v\n" ,
                        "�d�S�I�q�F�@�U�A���G�b�^�Ф���Ʊ�...\n" ,
                        "�d�S�^�L���ӻ��D�G�u�ګ�...�ڲש�Q�_�O��˪��@�ӬG�ơA�����A�Q���Qť�O�H�v\n" ,
                        ( : destruct , ob : ),
                }) );
       return 1;
}
void relay_say(object ob, string arg)
{
            if( !ob->query_skill("blue-power")  ) {
                if( !ob->query_temp("the-blue-power-quest") && arg=="���~" ) {
                        do_chat( ({
                          "�d�S���D�G�u�O�ڡA�ڰ��F�ӳo�q�W��H���l�A�]�Q���D���@�i�d���C�v\n",
                          "�u���d�S�ĤF�f��A�����O�_�[�M����ӨӪ��P��..\n",
                          }) );
                        ob->set_temp("the-blue-power-quest",1);
                        return ;
                }
                if( ob->query_temp("the-blue-power-quest")==1 && arg=="�@�i�d��" ) {
                        do_chat( ({
                          "�d�S���D�G�u�ڦb��M�@�i�W�s�u�Ŧ��P�v�A�s��81�����d���A�p�G�A���Ū��ܡA�Ʊ�A�����ڧ��v\n",
                          "�d�S�S�C�n�ۨ��ۻy�F�X�y�ܡA�A��������ť��j��ϥ_�䪺�ˤl...\n",
                          }) );
                        ob->set_temp("the-blue-power-quest",2);
                        return ;
                }
                 if( ob->query_temp("the-blue-power-quest")==2 && arg=="�j��ϥ_��" ) {
                          do_chat( ({
                            "�d�S���D�G�u�ڤ��e��ť���L�o�d�����b�o�y�˪L���䪺�j��ϥX�{�L�A�u�O�����b����a��F...�v\n",
                            "�A�t�۷Q�۸Ӥ��|�O�p�ɭԳ����`�h���a��O...\n",
                            }) );
                }

        }
        //////////////////////////////////////////////////////////////////////////////////////////////////
        // �Ŧ⤧�O
              if( !ob->query_learn("blue-power") && ob->query_temp("the-blue-power-quest")==3 ) {

                if( arg=="�Q" ) {
                         message_vision( CYN "�d�S�Ե�$N�����@�ǧ��U�A��F�n�Ǯɶ��~�N�G������...\n" NOR , ob );
                    if(ob->query("skills_point") + 1 >  SKILL_MAX_POINT )  {
                        // �ޯ��I�Ƥ���
                                        tell_object( ob , CYN "(�Ať������S������S���Pı�A�γ\�o�G�ƨä�����l�ާA�a...)\n" NOR );
                                }
                                else {
                                        tell_object( ob , CYN "\n(�Ať���G�Ƥ���Aı�o����_�F�I�L�˪��ܤ�...)\n" NOR );
                                        tell_object( ob , HIY "\n(�A���ޯ��I�ƴ�֤@�I�F�C)\n" NOR );
                                        ob->set_skill( "blue-power" , 30 );
                                        ob->add("skills_point" , 1 );
                                        ob->improved_skill( "blue-power" , 10000 );

                                }
                                ob->delete_temp( "the-blue-power-quest" );
                                return;
                        }
                        if( arg=="���Q" ) {
                                do_chat( ({ "�d�S���D�G�u���n�A���§A���d���F...�v\n" }) );
                                ob->delete_temp( "the-blue-power-quest" );
                                return;
                        }
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////
        // ����
          if( ob->query_learn("psychical") || ob->query_skill("psychical",1) ) return;
        if( arg=="���E�I�O�h" && ob->query_temp("island_forest/kate_quest")!=1 ) {
                do_chat( ({
                "�d�S�y�H��D�G�u��H�H�A�{�ѥL�ܡH�H�v\n",
                "�A�ӲӦa�N�Ҫ��D���@�ǨƱ��A��d�S�y�H��F�_��......\n",
                  "(�ݼˤl�d�S�y�H��A�᪺�ܰ����A�A�ߤ��_�F�ө��Y�A�O�_�i�H�L���ɧA�u���ޡv�O�H)\n",
                }) );

                ob->set_temp("island_forest/kate_quest",1);
                return ;
        }
        if( arg=="����" && ob->query_temp("island_forest/kate_quest") )
        {
                do_chat((: command, "say ��...�ݦb�A���ڤ@�ǽu���A�ڴN���ɤ@�U�A�n�F�C" :));
        message_vision("$N�оɤF$n�����u��v���ޥ��C\n", this_object(),ob );
                do_chat((: command, "say �ڤ]�u�����A�_���Y�A�ѤU���N�a�A�ۤw�׽m(forge)�F�C" :));
                ob->improve_skill("psychical",50);
                ob->delete_temp("island_forest/kate_quest");    
        }

        return ;
}


