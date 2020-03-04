inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�����]", ({ "chiao", "master"}) );
        set("nickname", "�ɵت�");
        set("gender", "�k��");
        set("class","healer");
        set("age", 60);
        set("adv_class",1);
        set("class1","�ѱ���");

        set("guild_gifts",({10,7,0,3}));
        set("long",
"�ǥX�����]�D�O��������, �������G, �֪�����@���o���M, ��껯���]�D�C\n"
"�O�����|�ئ��l, �B�S�����G, ���ަp��, �`��, �����]����N�۷���, �]\n"
"���LĹ�o�F�ɵت����ٸ��C\n"

        );
        set("attitude", "peaceful");
        set("level",41);
        set("guild_skills",([
                "dagger":({160,2,50}),
                "dodge" : ({130,2,50}),
                "parry" : ({130,2,50}),
        ])  );
        set_skill("unarmed", 90);
        set_skill("parry", 80);
        set_skill("dodge", 80);
	set_skill("sky-dagger", 80);
        set_temp("apply/armor",38);
        set("no_check_class",1);
        set("chat_chance",20);
        set("chat_msg",({
          "�����]�իջ��D�G�u�����Q�U�j�s���s�w��ɥi��?....�v\n" ,
                (:command("sigh"):),
          	(:command("think"):),
         }) );

                set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (:command("exert sky-dagger"):),
         }) );
        
        create_family("�ѱ��M��", 6, "�x���H");
        setup();
        carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/steel_dagger")->wield();
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_speak","speak");
        add_action("do_join","join");
}

int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_list(ob,me,arg);   
}

int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        message_vision("$N�Q�[�J�u"+ arg + "�v�C\n",me); 

        switch(i)
        {
        case -1: return notify_fail("�A�w�������F�C�C....^_^\n");
        case -2: return notify_fail("�A�w�������F�C�C....^_^\n");
        case -8: return notify_fail("�S���o�ت����C....:P\n");
       }
        if(me->query_temp("eight_speak") )
                command("say �o��"+ RANK_D->query_respect(me) +"�p�������y�ܡA�N�O�b�����F�T�ѤT�]�A�ڤ]�O���|�����C\n");
        else    
        {
                command("say ������A�p�A�໡�X(speak)�����Q����Ҳ��Ǫ��@�y�ܡA�ڴN���F�A�a");
                me->set_temp("eight_speak",1);                  
        }

        return 1;
}

int do_speak(string arg)
{
        object me;
        me=this_player();

        if(!me->query_temp("eight_speak") )return 0;

        if(arg != "�A���ѤK���A�^���۲���")
        {
                message_vision("$N�j�n���X�G�u"+ arg +"�C�v\n",me);
                command("shake");
              command("say ���O���O�A�A�Q�Q�a�C");
        }
        else
        {
                message_vision("$N�j�n���X�G�u"+ arg +"�C�v\n",me);
                command("say �n�A�N�O�o�y�ܡA�ڴN���A�J�u�ѱ��Сv���U�a�I�C");
                me->set("adv_class",1);
                me->set("class1","�ѱ���");
                me->create_family("�ѱ���",7,"���{");
                me->delete_temp("eight_speak");
        }       
        return 1;

}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("class1")=="�ѱ���" )
                return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("�A���O�ѱ��Ъ����{�C\n");
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIC"\n  �Z�L�ǥX�F�@�h��H������:"HIW"\n\n\t�ϤH�L�ƪ��u�ɵت��v�����]�Q"+ob->name(1)+"�����F!�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
        ::die();
        //destruct(this_object());
        return;
}
string guild_rank(object me)
{
       string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     // �N rank �������Ӽh��

        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "�ѱ�����Įv"; break;
                                // LV 10 ~ 19
                        case 1: rank = "�ѱ���L�Įv"; break;
                                // LV 20 ~ 29
                        case 2: rank = "�ѱ��C���Įv"; break;
                                // LV 30 ~ 39
                        case 3: rank = "�ѱ��M�Įv"; break;
                                // LV 40 ~ 49
                        case 4: rank = "�ѱ��j�M�Įv"; break;
                                // LV 50
                        default: rank = HIC "�ѱ��M�Ī���" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "�ѱ���ߧ���"; break;
                                // LV 10 ~ 19
                        case 1: rank = "�ѱ���L����"; break;
                                // LV 20 ~ 29
                        case 2: rank = "�ѱ��C������"; break;
                                // LV 30 ~ 39
                        case 3: rank = "�ѱ���������"; break;
                                // LV 40 ~ 49
                        case 4: rank = "�ѱ��j���Įv"; break;
                                // LV 50
                        default: rank = HIC "�ѱ��M�Ī���" NOR;
                }

        }
        return rank;
}

