#include <ansi.h>
inherit NPC;
void heal();
void create()
{
        set_name("�����]" , ({ "master chao","master","chao" }) );
        set("long",@long
�ǥX�����]�D�O��������, �������G, �֪�����@���o���M, ��껯���]�D�C
�O�����|�ئ��l, �B�S�����G, ���ަp��, �`��, �����]����N�۷���, �]
���LĹ�o�F�ɵت����ٸ��C
long
);
        create_family( HIC "�ѱ��M��" NOR ,17,"�x��");
        set("level",42);
        set("race","�H��");
        set("age",65);
        set("nickname","���G�ت�");
        set("adv_class",1);
        set("class1","�ѱ���");
        set("gender","�k��");
        set("int",100);
        // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
        // �ӥB�|�����`�M�n��n���� 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "dagger" : ({160,2,60}),
        ])  );
        set("guild_spells",([
               "moxibustion" : ({160,2,60}),
        ])  );
        set_skill("dagger", 90);
        set_skill("sky-dagger", 90);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set("no_check_class",1);
        set("chat_chance", 70);
        set("chat_msg",({
                (:command("think"):),
        (:command("exert sky-dagger"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert sky-dagger"):),
        }) );
        setup();
          carry_object(__DIR__"eq/steel_dagger.c")->wield();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="�O�X")
        {
           command("? "+who->query("id"));
           command("say �b�U�ä��ݭn�o�ӪF��C");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C");
             return 0;
          }
        message_vision("$N���F�����]�@��"+ob->query("name")+"�C\n",who);
             obj->start_busy(10);
             obj->set_temp("kill_bandit",1);
             destruct(ob);
             call_out("kill_bandit",1,obj);
             return 1;
        }

}
void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
}
void kill_bandit()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("kill_bandit");
      switch( i ) {
          case 1:
            command("say �x�I�I�o���O�Q�U�s�s���O�X�ܡI�I");
            command("say �o��"+RANK_D->query_respect(me)+"�O�q��o���O�X���H");
            obj->set_temp("kill_bandit",i+1);
            call_out("kill_bandit",3,me);
            break;
          case 2:
            message_vision(YEL"$N�N�o��O�X���L�{�i�D�����]�C\n"NOR,me);
            obj->set_temp("kill_bandit",i+1);
            call_out("kill_bandit",3,me);
            break;
          case 3:
            command("nod");
            command("say �o�˰�...�դU�u�O��L�M�q, �O�H�ܨذڡC");
            command("smile");
            obj->set_temp("kill_bandit",i+1);
            call_out("kill_bandit",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 

            {
              command("say �o��" +  RANK_D->query_respect(me) + ", �Ш��b�U�@���C");
              command("bow "+me->query("id"));
              obj->delete_temp("kill_bandit");
            }
            else {
              command("say �ѱ��C��, �̤l���~, �N�A���ѱ��[�@�찪�{�a!!");
              obj->set_temp("kill_bandit",i+1);
              call_out("kill_bandit",2,me);
            }
            break;
          case 5:
            command("say �J�ڱз��L�M�q�A���j�ٮz�I");
            message_vision(YEL"$N���U�ӻ��D�G�v���I�̤l���w��Ӯv�����л��I\n"NOR,me);
            message_vision(HIY"�����]�����a���$N���Y�A�û��D�G�n�I�n�I..\n"NOR,me);
            message_vision(HIY"�����]���D�G�o�O�ڬ��w�b�Ϊ��Ȱw, �p���N���A�@�ڧa!\n"NOR,me);
            p=new(__DIR__"obj/needle.c");
            p->move(this_player());
            command("pat "+me->query("id"));
            command("smile");
            me->set("adv_class",1);
            me->set("class1","�ѱ���");
            me->create_family("�ѱ���",18,"�в�");
        me->set("guild_rank","�ѱ��вĤQ�K�N�в�");
            obj->delete_temp("kill_bandit");
            break;
      }
}
int do_skill_list(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();
        me->set("no_check_class",1);    //�Ȯ�
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
        me->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
//      GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
//      this_player()->delete("no_check_class");
//        return 1;
}
int do_join(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

if(me->query("class1")=="�ѱ���") return notify_fail("�A�w�O�ѱ��бв��F�C\n");
     if(arg!="�ѱ���") 
                return notify_fail("�A�n���J���@�Ӫ���?\n");
     say("�����]�����s�w�o�T�A�L�ߦ��A���{�C\n");
     say("�����]���ۻy���D�G�����s�w��ɥi��....�C\n");
     say("�����]���ۻy���D�G�p�G��N�U�X�D���O�X....�C\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="�ѱ���") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O�ѱ��в��C\n");
}

int do_spell_train(string arg)
{
        return GUILDMASTER->do_spell_train(this_object(),this_player(),arg);

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
CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�ϤH�L�ƪ��u���G�ت��v�����]�Q"+ob->name(1)+"�������F�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
       tell_object(ob,HIW"(�]���A�����F�����]�A�ҥH�o��F 1 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
            ||      is_fighting(me) )
                return;
        kill_ob(me);
        me->fight_ob(this_object());
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
        // LV 10 ~ 19
                        case 1: rank = "��J��D������N�h"; break;
                        case 2: rank = "�p���W���ĳN�v"; break;
                        case 3: rank = "�a���٥@���ѱ��̤l"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 1: rank = "��J��D������N�h"; break;
                        case 2: rank = "�p���W���ĳN�v"; break;
                        case 3: rank = "�a���٥@���ѱ��̤l"; break;
                }
        }
        return rank;
}
void heal()
{
     object obj;
     obj=this_object();
if(obj->query("hp") < obj->query("max_hp")/2)
{
      command("exert bloodsky-force heal");
}
if(obj->query("mp") < obj->query("max_mp") /2)
{
     obj->add("mp",100+random(50));
     message_vision("$N���_���ӡA�ήi�F�����A�����صM�@�s�C\n",obj);
