#include <ansi.h>
inherit NPC;
void heal();
int talk_action();
void accept_join(object me);

void create()
{
        set_name("�����]" , ({ "master chao","master","chao" }) );
        set("long",@long
�ǥX�����]�D�O��������, �������G, �֪�����@���o���M, ��껯���]�D�C
�O�����|�ئ��l, �B�S�����G, ���ަp��, �`��, �����]����N�۷���, �]
���LĹ�o�F�ɵت����ٸ��C
long
);
        create_family( HIC "�ѱ��M��" NOR ,7,"�x��");
        set("level",42);
        set("race","�H��");
        set("age",65);
        set("nickname","���G�ت�");
        set("adv_class",1);
        set("class1","skyowl");
        set("gender","�k��");
        set("int",100);
        // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
        // �ӥB�|�����`�M�n��n���� 20                  by shengsan
        set("guild_gifts",({2,3,8,7}));
        set("guild_skills",([
               "dodge"  : ({160,2,60}),
               "parry"  : ({160,2,60}),
               "dagger" : ({160,2,60}),
               "unarmed": ({160,2,60}),
        ])  );
        set("guild_spells",([
               "moxibustion" : ({999,1,5}),
        ])  );
        set_skill("dagger", 90);
        set_skill("sky-dagger", 90);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set("no_check_class",1);
        set("chat_chance", 10);
        set("chat_msg",({
                (:command("think"):),
        (:command("exert sky-dagger"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (: command("exert sky-dagger") :),
                  (: command("acupuncture attack") :),
        }) );
        set("talk_reply",(: talk_action() :));
        setup();
        carry_object(__DIR__"eq/steel_dagger.c")->wield();
}

int talk_action()
{
     object me = this_player(), ob = this_object();
     int x = random(5);
     string *SkyPill =({"���ߤ�(Red heart pill)","���P��(Purple star pill)","���s��(Blue dragon pill)",
                        "��M��(Green pill)","�ٻ(Resurrect pill)",});
     string *SkyPillID = ({"red heart pill","purple star pill","blue dragon pill",
                        "green pill","resurrect pill",});
     if( !me->query("class1") && !me->query_temp("skyowl/SkyPillID") ){
     command("hmm");
     command("say �o��"+RANK_D->query_respect(me)+"�O�����ϤH������ܡH");
     command("say �o�˧a..�p�G�A����"+SkyPill[x]+"..�ç⥦���ӵ���..");
     command("say �ڴN���A���{�A�N�ڲ��ͩҾǲb�¤��A�C"); 
     me -> add_temp("skyowl/SkyPillID", SkyPillID[x]);
     return 1;
     } else if( me->query("class1") == "skyowl" && me->query("level") == 25 ){
            command("say ...�ѤҤw�g�S�������ѯ���Ǳµ��A�F");
            command("say �p�G�A�ٷQ�M����Ǥ��Ĥ��N�A�N�h��ǻ�������P�r���a..");
            me -> add_temp("skyowl/skyowl_med", 1); 
            return 1;
            }
     return 0;
}

int accept_object(object who,object ob)
{
        string msg = who->query_temp("skyowl/SkyPillID");
        
        if( ob->query("id") != msg ) {
           command("? "+who->query("id"));
           command("say �b�U�ä��ݭn�o�ӪF��C");
           return 0;
        } else {
        if(this_object()->is_busy() || this_object()->query_temp("no_give") ) {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C");
             return 0;
        } 
        message_vision("$N���F�����]�@��"+ob->query("name")+"�C\n",who);
             this_object()->set_temp("no_give",1);
             destruct(ob);
             accept_join(who);
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
        add_action("do_check_mark","apply");
}


void accept_join(object me)
{     
            command("hmm");
            command("say ���N�ӧڭ̪����w�A���Ѱ_�A�N�O�ѱ��̤l�F�C"); 
            message_vision(YEL"$N���U�ӻ��D�G�v���I�̤l���w��Ӯv�����л��I\n"NOR,me);
            message_vision(HIY"�����]�����a���$N���Y�A�û��D�G�n�I�n�I..\n"NOR,me);
            message_vision(HIY"�����]���D�G�o�O�ڬ��w�b�Ϊ��Ȱw, �p���N���A�@�ڧa!\n"NOR,me);
            new(__DIR__"obj/needle.c")->move(me);
            command("pat "+me->query("id"));
            command("smile");
            me->set("adv_class",1);
            me->set("class1","skyowl");
            me->create_family("�ѱ���", 8, "�в�");
            me->set("guild_rank","�ѱ��вĤK�N�в�");
            me->delete_temp("skyowl/SkyPillID");
}

int do_skill_list(string arg)
{
        this_player()->set("no_check_class",1);    //�Ȯ�
        GUILDMASTER->do_skill_list(this_object(), this_player(), arg);
        GUILDMASTER->do_spell_list(this_object(), this_player(), arg);
        this_player()->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(), this_player(), arg);
        return 1;
}

int do_join(string arg)
{
     if(this_player()->query("class1")=="skyowl") return notify_fail("�A�w�O�ѱ��бв��F�C\n");
     if(arg!="skyowl") return notify_fail("�A�n���J���@�Ӫ���?\n");
     talk_action();
     return 1;   
}

int do_advance(string arg)
{
        if (this_player()->query("family/family_name")=="�ѱ���") return GUILDMASTER->do_advance(this_object(), this_player(), arg);
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
        if(!living(this_object()) || is_fighting(me) ) return;
        kill_ob(me);
        me->fight_ob(this_object());
}

string guild_rank(object me)
{
        string rank;
        int lv = me->query("level")/10; // �N rank �������Ӽh��
        if( me->query("gender") == "�k��" ) {
                switch( lv ) {
        // LV 10 ~ 19
                        case 1: rank = "��J��D������N�h"; break;
                        case 2: rank = "�p���W���ĳN�v";   break;
                        case 3: rank = "�a���٥@���ѱ��̤l"; break;
                }
        } else {
                switch( lv ) {
                        case 1: rank = "��J��D������N�h"; break;
                        case 2: rank = "�p���W���ĳN�v";   break;
                        case 3: rank = "�a���٥@���ѱ��̤l"; break;
                }
        }
        return rank;
}

void heal()
{
//     if(this_object()->query("hp") < this_object()->query("max_hp")/2)
//        command("exert bloodsky-force heal"); �n�O�o�� XD 
        
     if(this_object()->query("mp") < this_object()->query("max_mp") /2){
        this_object()->receive_heal("mp",100+random(50));
        message_vision("$N���_���ӡA�ήi�F�����A�����صM�@�s�C\n", this_object());
        } 
}

int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class1")!="skyowl") return notify_fail("�A���O�ѱ��в��C\n");
        if(mark=present("silver needle",me)) return notify_fail("�A�w�g���u�Ȱw�v�F�C\n");
        ob=new(__DIR__"obj/needle");
        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("�A�����ᱼ�@�ǪF��~�����ʳ�I\n");
        }
        ob->move(me);
        message_vision("$N���F�@"+ob->query("unit")+ob->name()+"��$n�C\n",this_object(),me);
        me->save();
        return 1;
}
