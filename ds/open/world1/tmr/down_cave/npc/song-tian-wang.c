#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_BANDIT;

void die()
{
        object ob ;
    ob = last_damage_giver();

        if( !ob || ob==this_object() )
        {
                ::die();
                return;
        }
        
          message( "system",
        HIG "�i�y�H�s�D�j" HIW "�G�w�����\�@���ǧ��Ѥ��G���b"+ob->name(1)+"(" + ob->query_id() + ")��W�F�I�I\n"+NOR
        ,users() );

        ::die();
        return;
}
void create()
{
        set_name("���Ѥ�", ({ "song tian wang" ,"song","wang" }) );
        set("long",@long
�@�@���Ѥ������D�`��靈�O�A�֦��@�I�u��`�H�������A�U�Q�������g
�X�����H�����O�C�ǻD�L���Z�\�u�a�s�|���Z�v�����H�A�i�Q�C���_�\
�����]�W���W�����ޡC���O�@�L�Ⲵ�L���A���G���b������Ʊ��дo�C
long
);
        set_race("operation");
        set("age", 45);
        set_attr("operation" , 80);
        set("force_ratio",10);
        set_skill("twohanded blade" , 120);
        set_skill("dragon four feat" , 150);
        set_skill("parry",120);
        set_skill("psychical",50);
        set_skill("dodge",120 );
        map_skill("twohanded blade","dragon four feat");
        set("title","�w��������");
	set_temp("apply/armor" , 40 );
        setup();
        set_level(40);
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/gold-snow-armor")->wear();
        carry_object(__DIR__"obj/feather-boots")->wear();
        carry_object(__DIR__"obj/sacrifice-blade")->wield();
}

private void exchange(string food_name, object player)
{
        if( !player || environment(player) != environment() ) return;
                if( player->query_stat_maximum("nina") >= 100
// ���ӬO�n <= �~��A�o�˦p�G point �O 7, +3 = 10, �N����ѤF..fix by -Acme-
//                          && player->query("skills_point")+3<SKILL_MAX_POINT
                          && player->query("skills_point")+3 <= SKILL_MAX_POINT
                         && !player->query_learn("dragon four feat") ) 
                {
                        command("say ���@�A�����ޤ]��F�@�w�\�ҡA�����A�O����ǨӪ��H");
                player->set_temp("duli_forest/song-tian-wang",1);
                } else {
                        command("say �u�O���§A�F�A�H�ᦳ������D�A�ڷ|�ɶq���A�����C");
                }
}
 
int accept_object(object me, object ob)
{
       if( !ob->id("_OBJ_ID_WOLF_BELT_")
                   || me->query_learn("dragon four feat")
           || me->query_temp("duli_forest/song-tian-wang")  )
           {
              return 0;
       }
       command("smile");
       command("say ������....�Q����A���ڱ��F�o�ӲV�b�F�C");
       do_chat(({ (: exchange, ob->query("id"), me :) }) );
       return 1;
}
 
void relay_say(object ob,string arg)
{
        if( ob->query_learn("dragon four feat") ) return;
        if( strsrch(arg,"�дo")!=-1 ) {
                do_chat( ({"���Ѥ���F�A���D�G�u��..������X�~���X�F���֤j���D�A���G�O�����l�@�R�C�v\n" }) );
                        return ;
                }
        if( strsrch(arg,"���l")!=-1 ) {
                do_chat( ({ "���Ѥ��N��D�G�u�n���O�U�ΥS�̹D�q�A�ڦ��N��L�����F�C�v\n" ,
                        (: tell_object , ob , CYN"(�A�t���ۤw�����O�_����O���L�ѨM�o���D�@)\n" NOR :),
                }) );
                return ;
         }
        if( ob->query_temp("duli_forest/song-tian-wang")==1  ) {
          if( arg=="�d�S" )
          {
                do_chat( ({"���Ѥ��@���D�G�u��ӬO�L�A���ǧA����¦�\�ҳo��Ϲ�C�v\n" ,
                        "���Ѥ��y�F�f��A�S���D�G�u�کM�L�]�ᦳ�t�����A�A������ШD�A�ɺ޻��a�A�ڷ|�ɤO���A���a�C�v\n" ,
                        (: tell_object , ob , CYN"(�A�Q�짺�Ѥ������W���ޡA�n�O��V�L�Ǩ�A�@�w�i�H���W���~�C)\n" NOR :) ,
                 }) );
                 ob->set_temp("duli_forest/song-tian-wang",2);
                  return ;
                }
             }
        if( ob->query_temp("duli_forest/song-tian-wang")==2  ) {
        if( arg=="�a�s�|���Z") {
                        /* �ǲߧޯ��I�Ƥ��� */
// �p�G�ޯ��I�� 7 +3 ���ܦ�10, ���ӬO�P�_ > �~��A fix by -Acme-
//                         if(ob->query("skills_point")+3>=SKILL_MAX_POINT )
                         if(ob->query("skills_point")+3>SKILL_MAX_POINT )
                        {
                                message_vision(CYN"���Ѥ��N���D�G�u�A���ǬƼs�A���ݭn�b�U�o�J�Τp�ާa�C�v\n"NOR,ob);
                }
                        else {
                                message_vision(CYN"���Ѥ������j���D�G�u�s�A�]�ʨ�ڪ����W���ޤW�F�A�@�A��跥�ΡA�N�Ǳ§A�a�C�v\n"NOR,ob);
                do_chat( ({
                        "���Ѥ��B�_��W���M�A�����L�񪺨ϥX�F���W���ޡA�u���A�@���تA���w...\n" , 
                        (: tell_object , ob , CYN"(�A����q�O�A���M�u�ǲߨ�֤�A���Τ߭W�m�A�٬O�i�H�j�����C)\n"NOR  :) ,
                        (: tell_object , ob , HIG"(�A���ޯ��I�ƪᱼ�T�I�F�C)\n" NOR  :) ,
                }) );
                ob->add("skills_point",3);
                ob->improve_skill("dragon four feat",100);
                           }
                        ob->delete_temp("duli_forest/song-tian-wang");
                        return ;
                }
                }
}


