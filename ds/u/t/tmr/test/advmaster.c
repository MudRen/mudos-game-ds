//�K���� �i��Master 
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�d��",({"wu chung master","master","wu","chung"}));
        set("gender", "�k��");
        set("long",@LONG
�d�����K�������N���l���A�~�֮ɫi��X���A�W�ޥX�s�A��Z���Ѥ@
�W�u���v���D�h�ҶǱ¡A��j�j�Z�q�����{�̡��}�A�Ҳ߱o�A�ܦ�������
�]�A�ײߪZ���A�󤭤Q���ɤj���A���~�ФK�����A�C�Q���j���j���A�h�~
�s�L�A�y�C�۱o�C
LONG
        );
        set("level",60);
        set("age",80);
        set("adv_class",2);
        set("class1","�K����");
        set("class2","�K����");
        set("title","�K�����}�s���v");
        set_temp("exert_mark/bagi-power",5000);
        set("apply/armor",30);
        set("apply/damage",30);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("fork",100);

        set_skill("da-fork",100);
        set_skill("bagi_fist",100);
        set_skill("horse-steps",100);

        set("chat_chance", 10);
        set("chat_msg",({
        }) );
                set("chat_chance_combat", 80);
                set("chat_msg_combat", ({
                         (:command("exert da-fork"):),
                         (:command("exert bagi_fist"):),
                }) );
        
        set("guild_skills",([           // ����, ����1�i��, �W��
                "force":({300,3,100}),
                "bagi_force":({300,3,100}),
        ]) );

        set("guild_gifts",({10,7,0,3}));

        setup();
}

int accept_object(object who,object ob)
{
        if(!ob->id("quest-bagi-book") ) return 0;

        message_vision("$N���F�d���@���U�l�C\n",who,ob);
        destruct(ob);
        if(who->query("adv_class")==2 
        && who->query("class2")=="�K����" 
        && !who->query_skill("bagi_force") )
        {
                command("say �@�A�]�O�������H�A���p�ڶǧA�����ߪk�a�C");
                message_vision("�d���J�Ӧa�ФF$N�K���ߪk���f�Z�C\n",who);
                who->set_skill("bagi_force",5);
        }
        else 
                command("smile "+who->query("id") );
        return 1;
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_guild_join","join");
        add_action("do_advance","advance");
        add_action("do_say","say");
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
        int cost;
        cost=(me->query_skill(argx)-1)*2;
        me->add("popularity",-cost);
        return;
}

// advance  ���\�� GUILDMASTER�|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost;
        if(!arg || arg=="level") {
                cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                return;
        }
     else {
         if( me->query("popularity") < 3 )
                 tell_object(me,"�A���n�椣���F!!\n");
         else {
              me->add("popularity",-3);
              return;
         }
        }
}

int do_skill_list(string arg)
{
        return  GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
        int j,lv,cost;
        object ob,me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(this_player()->query("class2") != "�K����")
                return notify_fail("�A�ä��O�K�����̤l�C\n");
        
        if(arg=="force")
                lv=me->query_skill("force");
        if(arg=="bagi_force")
                lv=me->query_skill("bagi_force");

          if(arg=="force" || arg=="bagi_force")
        {
        if(lv < 5) //�å��Ǩ�bagi_force
                return notify_fail("�ݨӧd���ä��Q�ЧA�C\n");
        cost=lv*2;
        if(lv==100)
                return notify_fail("�A�w�g��F�n�p�y�����ҬɤF�C\n");
        if( j < cost)
                return notify_fail("�ݨӧd���ä��Q�ЧA��`�@�h�C\n");
        }
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

        message_vision("$N�Q�[�J"+arg+"�C\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -2: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -8: notify_fail("�S���o�Ӫ����a");break;

        }
        if(me->query("class2")=="�K����")
                return notify_fail("�A�w�O�K�������̤l�F�C\n");
        if(arg!="�K����" )
                return notify_fail("�o�̨S���o�Ӫ����C\n");
        if( me->query("class1")=="�K����" && me->query("level")==25 
        && me->query("adv_class")==1 && me->query_temp("adv-bagi-quest")==0 )
                {
                command("say �A�w�O���Ѥ媺�̤l�A��a�٨ӧ�ڳo�D���Y�C");
                me->set_temp("adv-bagi-quest",1);
                }
        else return notify_fail("�ݰ_�ӧd���ä��Q���A���{�C\n");

        return 1;
}


int do_advance(string arg)
{
          int j;
        object ob, me;

        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(me->query("class2") != "�K����")
                return notify_fail("�A�ä��O�K�����̤l�C\n");
   //�s�ץ��Aadv level ���n�� (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) 
                return notify_fail("�A���n�椣���C\n");
      if(j < 3 ) 
          return notify_fail("�A���n�椣���C\n");
        return GUILDMASTER->do_advance(ob,me,arg);
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
                        case 0: rank = "�K��������X�TĪ"; break;
                                // LV 10 ~ 19
                        case 1: rank = "�K�����������p�W"; break;
                                // LV 20 ~ 29
                        case 2: rank = "�K�������M�q����"; break;
                                // LV 30 ~ 39
                        case 3: rank = "�K�������L�𻷼�"; break;
                                // LV 40 ~ 49
                        case 4: rank = "�K���������W�ѤU"; break;
                                // LV 50
                        default: rank = HIC "�K�������@�N�v�v" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                // LV 1 ~ 9
                        case 0: rank = "�K��������X�|��"; break;
                                // LV 10 ~ 19
                        case 1: rank = "�K�����������^�W"; break;
                                // LV 20 ~ 29
                        case 2: rank = "�K�������M�q�|��"; break;
                                // LV 30 ~ 39
                        case 3: rank = "�K�������^�𻷼�"; break;
                                // LV 40 ~ 49
                        case 4: rank = "�K���������W�ѤU"; break;
                                // LV 50
                }

        }
        return rank;
}

int do_say(string arg)
{
        object me,ob;
        int i;
        me=this_player();
        ob=this_object();

        i=me->query_temp("adv-bagi-quest");
        if(arg!="��")           return 0;
        if(i!=1)                return 0;

        message_vision("$N���D�G��\n",me);
        message_vision("$N���⤧����o�Q�������A�W�U�a����F�A�X���C\n",ob);
        message_vision("$N���D�G�u�A�N�J�ڪ��U�A���ڦn�n�Ǳ§A�Z���A���~�԰O�u�L�q�v�G�r�C�v\n",ob);
        ob->command("pat "+me->query("id") );
        message("world:world1:vision",
        HIY "\n\t�Z�L�ֳ��G�@�N�v�v �d�����F"+me->name(1)+HIY "���K�����ĤG�N�̤l�C\n"NOR
        ,users() );

        me->command("kneel "+ob->query("id") );
        me->set("class2","�K����");
        me->create_family("�K����",2,"�L��");
        me->set("adv_class",2);
        me->delete_temp("adv-bagi-quest");

        return 1;
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
HIW"�Z�L�ǥX�F�@�h��H������:"HIW"�K�����}�s���v�@�d�����b"+ob->name(1)+"�⤤�C\n"+NOR
        ,users());
        ob->add("popularity",3);
        ::die();
        return;
}


