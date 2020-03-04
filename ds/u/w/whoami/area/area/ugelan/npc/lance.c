inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�Ŵ���", ({ "master lance bill", "master", "bill", "lance" }) );
        set("nickname", HIY"���t�Ϫ�"NOR);
        set("gender", "�k��");
        set("class","knight");
        set("age", 38);
        set("adv_class",1);
        set("class1","�t�M�h");
        set("guild_gifts",({7,8,0,5}));
        set("long",@LONG
�����񺸬ݰ_�Ӥ������G�A�����Q�����áA�������M�A�A���b�L�����ǴN
���@�ز��W���w���P�C�L�O�i�������ȸT�íx�j���j�N�x�A�վB�������
�����k��A���t�u�@���վB�����~�����w���A�]���S���H����L���q�E
LONG
        );
        set("max_ap",2000);
        set("attitude", "peaceful");
        set("level",40);
        set("guild_skills",([
        "sword":({110,4,80}),
        "blade":({110,4,80}),
        "dodge" : ({120,3,80}),
        "parry" : ({120,4,80}),
        "unarmed":({110,4,80}),
        "fork":({120,4,80}),
        "axe":({110,4,80}),
        "staff":({110,4,80}),
        ])  );
        set_skill("unarmed",100);
        set_skill("parry", 90);
        set_skill("dodge", 90);
        set_skill("fork",90);
        set_skill("sword",100);
        set_skill("blade",100);
        set_skill("axe",100);

        set_temp("apply/armor",40);
        set("no_check_class",1);
        set("chat_chance",20);
        set("chat_msg",({
          "�Ŵ��񺸹�A����G�u�o��p�S�̭n���n�[�J�ڭ̪��H�v\n" ,
          "�Ŵ��񺸹�A����G�u�Х���join �t�M�h���[�J�ڭ̧a�E�v\n" ,
          (:command(":D"):),
          (:command("smile"):),
        }) );
        create_family("��������", 12,"�T�íx");
        setup();
        carry_object(__DIR__"eq/holyhelmet.c")->wear();
        carry_object(__DIR__"eq/holyarmor.c")->wear();
        carry_object(__DIR__"eq/honorboots.c")->wear();
        carry_object(__DIR__"wp/lightaxe.c")->wield();
}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_swear","swear");
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
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("level") > 24 && me->query("class2")=="�t�M�h" )
        return notify_fail("�A���O�������Ȫ��T�íx�C\n");
        if(me->query("class1")=="�t�M�h" )
        return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("�A���O�������Ȫ��T�íx�C\n");
}
int do_join(string arg)
{
        int i;
        object ob, me;

        ob = this_object();
        me = this_player();

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        message_vision("$N�Q�[�J�u"+ arg+ "�v�C\n",me); 

        switch(i)
        {
        case -1: return notify_fail("�A�w�������F�C\n");
        case -2: return notify_fail("�A�w�������F�C\n");
        case -8: return notify_fail("�S���o�ت����C\n");
        }
        if(me->query_temp("knight") )
                command("say �o��"+ RANK_D->query_respect(me) +"�p�G���ֵo�}�A���N�ҩ��A�P�ڭ̵L�t�F�E\n");
        else    
        {
                command("say �p�G�A��o�}(swear)�A�A�|�û��H�^���������O���Z�����Ǵ��A���A�N�i�H�[�J�ڭ̤F�E");
                me->set_temp("knight",1);                  
        }

        return 1;
}

int do_swear(string arg)
{
        object me;
        me=this_player();

        if(!me->query_temp("knight") )return 0;

        if(arg != "�ڷ|�û��H�^���������O���Z�����Ǵ�")
        {
                message_vision("$N�j�n���ۡG�u"+ arg +"�C�v\n",me);
                command("shake");
                command("say �A�o�o�ػ}�ڬO���|�۫H�A���E");
        }
        else
        {
                message_vision("$N��ۥ��������o�}�G�u"+ arg +"�C�v\n",me);
                command("say �Ӧn�F�I���ڭ̤@�_�����o�@�W�������a�I");
                message_vision("$N�[�J�F�������Ȫ��t�M�h�ΡE\n",this_player());;
                me->set("adv_class",1);
                me->set("class1","�t�M�h");
                me->create_family("��������", 12,"�T�íx");
                me->create_rank("�����������s�@��");
                me->delete_temp("knight");
        }       
        return 1;
}
string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");

        lv = lv/10;     

        if( me->query("gender") == "�k��" )
        {
                switch( lv )
                {
                                
                        case 0: rank = "�����������s�@��"; break;
                                
                        case 1: rank = "�H����s���s�Z�h"; break;
                                
                        case 2: rank = "�ޥ����m���t�Z�h"; break;
                                
                        case 3: rank = "�Ȧu�б����t�Ԥh"; break;
                                
                        case 4: rank = "��u���q���t�M�h"; break;
                                
                        default: rank = HIW "�������ȯ�������" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                
                        case 0: rank = "���q�ѨϪ��ͩ^��"; break;
                                
                        case 1: rank = "�N�Ӱ�w���k�Z�h"; break;
                                
                        case 2: rank = "�޳N�¼����k�Ԥh"; break;
                               
                        case 3: rank = "�Ȧu�б����k�Ԥh"; break;
                               
                        case 4: rank = "�M���������k�t��"; break;
                               
                        default: rank = HIW "�������ȯ������k" NOR;
                }

        }
        return rank;
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
        HIG"\n�վB������"+HIY"�������ȯ��t�Ϫ��Ŵ���"+HIG"�������b"+ob->name(1)+"����̡I\n\n�վB�������J�@�}�d�˪������I\n\n"+NOR,users());
        ob->add("popularity",2); 
        ::die();
        //destruct(this_object());
        return;
}

