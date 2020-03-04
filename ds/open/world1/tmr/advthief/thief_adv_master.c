/*  advanced thief master
 *
 *  By Tmr 2002/04/04
 */
#include <ansi.h>
#include <guild_mark.h>

inherit NPC;
varargs int receive_damage(string type, int damage, object who);

void combat_ai();

void create()
{
         set_name("���", ({ "zei shuai master", "zei", "shuai", "master"}) );
        set("title", "�ƴ��E�d��");
        set("gender", "�k��");
        set("age", 40);
        set("long",@long
    ��ӬO����W���W�w�[���s�������A����ŪŤ��ޤw�F�X���J�ƪ�
�ҬɡA���n�����{�p�Y���@��²��A�ӥL���t���ޥ���O�`���i���A�b
�d�x�U���������H���šA���p�ϴx�C��ӫT�����y�e�A�a�ۤ@���a�᪺
�����A��K�W�L�X���y�O�C
long
        );
        set("attitude", "peaceful");
        set("level",60);
        set("evil",50);
        set("race","evil");
        
        set_skill("unarmed", 95);
        set_skill("parry", 90);
        set_skill("dodge", 100);
        set_skill("dagger",100);
        set_skill("perception",100);
         set_skill("constant-virtue",50);
          set_skill("free_action",100);

        set_skill("aerial-dagger", 100);
        map_skill("dagger","aerial-dagger");
            set_skill("nine-waterfall", 100);
          set_skill("reachcloud-steps", 100);
          map_skill("dodge","reachcloud-steps");

        
        set_temp("apply/armor",150);
        set_temp("apply/dodge",50);
            
        set("chat_chance", 10);
        set("chat_msg", ({
                   (: command("wield dagger") :),
           }));

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ( {
                   (: combat_ai :),
                } ));

        //���|�]�w
        
        set("adv_class",2);
        set("class2","thief");
          set("class1","thief");
          set("guild_gifts",({3,7,0,10}));

        set("guild_skills",([
              "nine-waterfall":     ({100, 3, 30}),
              "stillhunt":     ({110,4,60}),
              "aerial-dagger":     ({110,4,90}),
              "reachcloud-steps":     ({110,3,80}),
              "free_action":     ({100,3,100}),
               "pick_lock":     ({100,3,100}),
                "perception":     ({100,3,100}),
        ])  );

        setup();
      carry_object(__DIR__"wp/cloud-together-dagger")->wield();
          carry_object(__DIR__"eq/dragon-shield")->wear();
    receive_money(5000);
}

void combat_ai() {
        // �ͩR�����A�ǳưk�R.
        if( query("hp") < query("max_hp") /3 
           && !is_busy() && random(100) > 70 ) {
                this_object()->remove_all_killer();
                message("world:world1:vision",
        HIY"\n\n\t�ƴ��E�d�� ��Ӵ����a�n������A���D�G�u�p�l�F�`�A������Ӥ����F�C�v\n\n"NOR
          HIG"\t��ӻ������a�D�W�ƤQ�V�����b�šA�@�Ӳ��δ����A�����b���誺�ѻڡC\n\n"NOR

                ,users());

                destruct(this_object());
        } else {
                command("wield dagger");
                command("exert nine-waterfall");
        }
}


// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

       if(random(100)<40)
        {
                damage/=3;
                message_vision(HIM "\n�X�T�����q��e���ӨӪ��ɹ��צ�o�������F�I�I" NOR,this_object());
        }


        if(objectp(who) )
                ::receive_damage(type,damage,who);
        else
                ::receive_damage(type,damage,who);


        return damage;
}

void init()
{
        ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
        add_action("do_join","join");
        add_action("do_check_mark","apply");
}

// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
        int cost=0;
        switch(argx)
        {
        // �S��ޯ� cost 3
                case "aerial-dagger":
                case "reachcloud-steps":
                case "stillhunt":
                case "nine-waterfall":
                case "free_action":
                case "pick_lock":
                case "perception":

                cost=3;
                me->add("popularity",-cost);
        break;
        }
        return;
}

// advance  ���\�� GUILDMASTER�|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost;
        /* ���ɵ���(level)���n��p�� */
        if(!arg || arg=="level") {
                  cost=(me->query("level")-21)*(me->query("level")-21);
                me->add("popularity",-cost );
                me->save();
                return;
        }
        else {
         if( me->query("popularity") < 3 ) {
                 me->set("popularity",0 );  
                 me->save();
         }
         else {
              me->add("popularity",-3);
              me->save();
              return;
         }
        }
}

int do_check_mark(string arg)
{
        object me,ob,mark;
        me=this_player();
        if(me->query("class2")!="thief")
                return notify_fail("�A�ä��b��Ӫ����U�C\n");
        if(mark=present("advanced thief dagger",me))
                return notify_fail("�A�w�g���u�s�骺���P�v�F�C\n");

        ob=new("/open/always/thief_adv_mark");

        if(!ob->can_move(me))
        {
                destruct(ob);
                return notify_fail("�A�����ᱼ�@�ǪF��~�����ʥ����|�H���C\n");
        }
        ob->move(me);
        message_vision("$N���F�@"+ob->query("unit")+ob->name()+"��$n�C\n",this_object(),me);
        me->save();
        return 1;
}

int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);     
}

int do_skill_train(string arg)
{
         int j, cost;
        object ob,me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");

        if(me->query("class2") != "thief" )
                return notify_fail("�A�ä��b��Ӫ����U�C\n");
        switch(arg)
        {
                // �S��ޯ� cost 3
              case "aerial-dagger":
              case "money-dart":
              case "reachcloud-steps":
              case "free_action":
              case "pick_lock":
              case "nine-waterfall":
                cost=3;
                // �@��ޯ� cost 0
                default:
                        cost=0;
        break;        
        } // end switch

        if( j < cost)
                return notify_fail("�ݨӸ�Ӥ��Q�A���ɧA�F�C(���D�A��"+cost+"�I�n��)\n");
        return  GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        object ob, me,mark;
        int i;
  string guild_rank, title;

        ob = this_object();
        me = this_player();

        if(!arg) arg="thief";
        message_vision("$N�Q�[�J��Ӫ����U�C\n",me);

        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
               case 0: break;
               case -1: notify_fail("�A�w�g�b��Ӫ����U�F�C\n");break;
               case -2: notify_fail("�A�w�g�[�J��L���|�F�C\n");break;
               case -8: notify_fail("���ɦ��ɨèS���o�Ӫ����C\n");break;
            }
        if(me->query("class2")=="thief")
                return notify_fail("�A�w�b��Ӫ����U�F�C\n");
        if( me->query("class1")=="thief" 
                        && me->query("level")==25 
                        && me->query("adv_class")==1 )
             {
                if( me->query_skill("stealing")<60 )
                        return notify_fail("�ѩ�A�����s��O�����A��Өä��Q���A�C\n");
                if( me->query_skill("backstab")<60 )
                        return notify_fail("�ѩ�A���ĭI����O�����A��Өä��Q���A�C\n");
                                
//        ob=new("/open/always/thief_adv_mark"); ob->mark by -alick
        mark = new("/open/always/thief_adv_mark");
                if(!mark->can_move(me))
                        return notify_fail("�A�����ᱼ�@�ǪF��~�����ʥ����|�H���C\n");
                if( !guild_rank = this_object()->guild_rank(me) || guild_rank=="")
                        guild_rank = "�٫ܵ檺�s��p��";
                me->set("guild_rank",guild_rank);
                if( !(title=me->query("title")) || title == "�ɪź}�y��" )
                        me->set("title", "�ǻ������ĤT����"); // ps�o�O�h�[��, luky �O�o�n�令�A�n����I�I
                mark->move(me);
                me->command("kneel shuai");
                message_vision(YEL "$N�����q�q�a�V��ӥn�F�X���T�Y�A�[�J�F�L�����U�C\n" NOR,me);
                tell_object(me,ob->name()+"�q�h�����X�F�@��"+mark->name()+"���A�C\n");
                me->set("class2","thief");
                me->set("adv_class",2);
                return 1;
                }
        else return notify_fail("�ݰ_�Ӹ�Өä��Q���A�C\n");

        return 1;
}



int do_advance(string arg)
{
        object ob, me;
        int j,tot;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        //�s�ץ��Aadv level ���n�� (lv-20)^2
        tot=(me->query("level")-20)*(me->query("level")-20);
        if( me->query("class2") != "thief") 
                return notify_fail("�A�ä��b��Ӫ����U�C\n");
        if( (!arg || arg=="level")
            && j < tot )
                return notify_fail("�A�����n��"+tot+"�I�n��~��ɯšC\n");
        return GUILDMASTER->do_advance(ob,me,arg);

}
string guild_rank(object me)
{
        string rank;
        if( me->query("gender") == "�k��" )
        {
                switch( me->query("level")/5 )
                {
                        case 0: rank = "�¤�¸}���p�k��"; break;
                        case 1: rank = "�|�B�y«���p�k��"; break;
                        case 2: rank = "�޳N�¼����k����"; break;
                        case 3: rank = "���H���N���k�s��"; break;
                        case 4: rank = "����Q�D���k�j�s"; break;
                        case 5: rank = "���X���S���k����"; break;
                        default: rank = "���X���S���k����";
                }
        }
        else
        {
                switch( me->query("level")/5 )
                {
                        case 0: rank = "�¤�¸}���¤p��"; break;
                        case 1: rank = "�ʧ@�F�����p�s��"; break;
                        case 2: rank = "�ޥ����m���p����"; break;
                        case 3: rank = "�e��ֲ֪��ѺD��"; break;
                        case 4: rank = "����Q�D����j��"; break;
                        case 5: rank = "���X���S��������"; break;
                        default: rank = "���X���S��������";
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
        HIG"\t�Z�L�ֳ��G"HIW"�ƴ��E�d���u��ӡv���b"+ob->name(1)+"���⤤�F�I�I\n"+NOR
        ,users());

        ob->add("popularity", 5); //�n��
        ::die();
        tell_object(ob,"  �A�o�줭�I�n��C\n");
        //destruct(this_object());
        return;
}

