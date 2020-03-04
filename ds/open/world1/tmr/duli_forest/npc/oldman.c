// ���˪��ѤH ��Ǩ� �u��-�q�ʩ��O�v
// -Tmr 2002/03/10

#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_VILLAGER;

void timeto_eat();

void create()
{
        set_name("���˪��ѤH", ({ "old man","man"}) );
        set_race("human");
        set_class("variation");

                map_skill("dodge", "lightswift");

        set("age", 75);
        set("gender", "male");
        set("long",@long
�@�Ө��W���ƳB�M�˪��ѤH�A��A�W����񦭤w�y�U�F�A�ݨӨ��ˮɤ餣�u�C
long
                        );
        setup();
        carry_money("coin", 1);
}

void init()
{
        ::init();
        if( is_fighting() || is_chatting() 
                        ||  this_player()->query_learn("electric nina")
                        ||  this_player()->query_temp("duli_forest/old-man") )
                        return;
        do_chat((: command, "say �y...�y....�ڨ��F���ˡA�����A���S���į��ϧڤ@�R�O�H" :));
}

private void exchange(string food_name, object player)
{
        set_stat_current("food", 0);
        command("eat " + food_name);
        if( !player || environment(player) != environment() ) return;
       if( player->query_learn("electric nina") ) {
       command("say �u�O���§A�F�C");
       return;
        }

                command("say ��F�A���ӥզY�A���F��A�����ǹq�ǡA�����A�O�_������n�ǡH");
                player->set_temp("duli_forest/old-man",1);
}

int accept_object(object me, object ob)
{
       if( !ob->id("_OBJ_ID_WHALE_PELLET_")
                   || me->query_temp("duli_forest/old-man")  )
           {
              do_chat((: command, "say �y...�y...�A���ڳo�ӷF���H" :));
              return 0;
       }
       command("smile");
       command("say �y... ..�u�O�Ӧn�F�T�u���§A�T ...");
       do_chat(({ (: exchange, ob->query("id"), me :) }) );
       return 1;
}

void relay_say(object ob,string arg)
{
        if( ob->query_learn("electric nian") ) return;

        if( ob->query_temp("duli_forest/old-man")==1  ) {
        if( strsrch(arg,"�Q")!=-1 ||
                        strsrch(arg,"�n")!=-1 )
                        {
                message_vision(CYN"���˪��ѤH���_�믫�A�J�Ӧa�оɤF$N�q�Ǫ��������ѡC \n"NOR,ob);
                message_vision(CYN"���˪��ѤH�b�ФF�@�q����A�S�@�P�y�F�_��...\n"NOR,ob);
                                /* �ǲߧޯ��I�Ƥ��� ||  Ū���Ѧr����  */
                                if(ob->query("skills_point")+3>SKILL_MAX_POINT
                                || ob->query_skill("literate") < 10 ) {
                                        tell_object(ob,CYN"(�A����ť�����A�ݼˤl�]�u���o��F�C)\n"NOR);
                                        ob->delete_temp("duli_forest/old-man");
                                        return;
                                }
                                tell_object(ob,CYN"(�A�ߤ�����~�ҾǪ��A�٬O���Ǥ��F�ѡA�����O�_�n�A�бФ@�U...)\n"NOR);
                                ob->set_temp("duli_forest/old-man",2);
                }       
                return;
        }
        if( ob->query_temp("duli_forest/old-man")==2  ) {
        if( strsrch(arg,"�бФ@�U")!=-1  )
                        {
                  message_vision(CYN"���˪��ѤH��F$N�@���A���D�G�u��...�A�٦����F�Ѫ��a��A���ڦA���ɧA�@�ǧa�C�v \n"NOR,ob);
                message_vision(CYN"���˪��ѤH�S�}�l�о�$N�@�ǹq�Ǫ��������ѡC \n"NOR,ob);
                                message_vision(CYN"���˪��ѤH�b�ФF�@�q����A�S�@�P�y�F�_��...\n"NOR,ob);
                                /* �ǲߧޯ��I�Ƥ��� ||  Ū���Ѧr����  */
                                if(ob->query("skills_point")+3>SKILL_MAX_POINT
                                || ob->query_skill("literate") < 10 ) {
                                        tell_object(ob,CYN"(�A����ť�����A�ݼˤl�]�u���o��F�C)\n"NOR);
                                        ob->delete_temp("duli_forest/old-man");
                                        return;
                                }
                                tell_object(ob,CYN"(�bť���o�@�q����A�A�w�g�F�ѹq�Ǫ���z�A���O�n�p��N���O�ন�q�O�H)\n"NOR);
                                ob->set_temp("duli_forest/old-man",3);
                        }       
                return;
        }
        if( ob->query_temp("duli_forest/old-man")==3  ) {
        if( strsrch(arg,"�n�p��N���O�ন�q")!=-1  )
                        {
                message_vision(CYN"���˪��ѤH��F$N�@���A���D�G�u�o�i�O���`���ǰݤF�A���L���F�����A���٬O�ЧA�a�C�v \n"NOR,ob);
                message_vision(CYN"���˪��ѤH�}�l�о�$N�@�Ǭ��������ѡC\n"NOR,ob);
                                /* �ǲߧޯ��I�Ƥ��� ||  Ū���Ѧr����  */
                                if(ob->query("skills_point")+3>SKILL_MAX_POINT
                                || ob->query_skill("literate") < 10 ) {
                                        tell_object(ob,CYN"(�A����ť�����A�ݼˤl�]�u���o��F�C)\n"NOR);
                                        ob->delete_temp("duli_forest/old-man");
                                        return;
                                }
                                message_vision(CYN"���˪��ѤH�b�ФF�@�q����A���M�Ⲵ�o���A���G����I�l�F...\n"NOR,ob);
                                tell_object(ob,CYN"(�ݼˤl�A�u���ǵ۳o�ǲL�������ѡA��k�l�ۭפF�C)\n"NOR);
                                ob->delete_temp("duli_forest/old-man");
                                ob->add("skills_point",3);
                ob->improve_skill("electric nina",100);
                tell_object(ob,HIG"(�A���ޯ�ǲ��I�ƪᱼ�T�I�C)\n" NOR);
                                die();
				destruct(this_object() );
                        }       
                return;
        }

}

