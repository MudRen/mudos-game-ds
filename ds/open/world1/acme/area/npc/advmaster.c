// ���Z�жi���v��        1999.10.17      by Acme
#include <ansi.h>
inherit NPC;
void heal();
void quick_cast_fire();
void create()
{
        set_name("����s",({"sau zi san master","master","sau","san"}));
        set("gender", "�k��");
        set("long",@LONG
�L�N�O���Z�бХD���v�S�u�b���@��v����s�A�L���o�@�ܤj��
�A���v�ܪӡA�@����ۤѮv�D�T�A��o�Q�����Y�A�L���b����
�¤O�󬰱j�l���k�N�A�u���L���b�۴ȤW�A���ذ�۩G�y�C
LONG
        );
        set("level",60);
        set("race","celestial");
        set("age",65);
        set("adv_class",2);
        set("class1","���Z��");
        set("class2","���Z��");
        set("title","���Z�дx�Юv�S");
        set("nickname","�b���@��");
        set("addition_damage",60);
        set("addition_armor",140);
        set_temp("killbandit",1);
        set_spell("god-fire",100);
        set_spell("god-benison",100);
        set_skill("bloodsky-force", 100);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
         set_skill("constant-virtue",50);
        set("chat_chance", 1);
        set("chat_msg",({
                (:command("hmm"):),
        }) );
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
                  (:command("cast god-fire"):),
                         (:quick_cast_fire:), 
                          (:quick_cast_fire:), 
        }) );
// ========================================================================
//      �u�|�ɮv�i�H�бª��k�N�C��
// ========================================================================
        set("guild_skills",([ 
            "force":({130,2,80}),
            "bloodsky-force":({140,2,90}),
        ]) );

// ========================================================================
//      �u�|�ɮv�i�H�бª��k�N�C��
// ========================================================================
        set("guild_spells",([ 
            "summon_ghost":({110,4,100}),
            "god-shield":({110,2,100}),
            "god-kill" : ({110,3,80}),
            "god-benison" : ({110,3,80}),
        ]) );

// ========================================================================
//      �ɮv���ݩʤ��t��(�v��) �� more /doc/wiz/�ݩʻP����.txt
//      �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
//      �ӥB�|�����`�M�n��n���� 20
//      ********************* �����n�M���¾�~�@�� **********************
// ========================================================================
        set("guild_gifts",({2,4,9,5}));

        setup();
          carry_object(__DIR__"eq/zhu-rong_mask")->wear();
          carry_object(__DIR__"wp/sunsword")->wield();
        carry_object(__DIR__"eq/godneck.c")->wear();
        carry_object(__DIR__"eq/godarmor.c")->wear();
        carry_object(__DIR__"eq/godboots.c")->wear();
        carry_object(__DIR__"eq/godcloth.c")->wear();
        carry_object(__DIR__"eq/godhands.c")->wear();
        carry_object(__DIR__"eq/godhead.c")->wear();
        carry_object(__DIR__"eq/godlegging.c")->wear();
//        carry_object(__DIR__"eq/godmask.c")->wear();
        carry_object(__DIR__"eq/godpants.c")->wear();
        carry_object(__DIR__"eq/godring.c")->wear();
        carry_object(__DIR__"eq/godsurcoat.c")->wear();
        carry_object(__DIR__"eq/godwaist.c")->wear();
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_hp.c");
        carry_object(__DIR__"obj/pill_mp.c");
        carry_object(__DIR__"obj/pill_mp.c");
        carry_object(__DIR__"obj/pill_ap.c");

        add_money("coin",1000);
        map_skill("sword", "godsword");
        map_skill("dodge", "mirage-steps");
}

/* �W�ֳt�o��  -Tmr */
void quick_cast_fire()
{
        object me=this_object();
        object* target;
        int i;
        int SK=120,INN=150; // god-fire ���� �M ����(int)��
        if(me->is_busy() ) return;
        target=query_enemy();
        message_vision(
        HIG "$N�C�Y�ֳt�a��F�M�u����ë-�����g�v�A�K�ɾ�Ӱ��x�|�g���_�F�@�D����I�I\n" NOR
	+ HIR "\n�|�P�����K���t�Ӿ��ʦa�E���F�@�Ӧ�������������A�L�C�b$N�Y�W\n" NOR,
        me);



	for(i=0;i<sizeof(target);i++)
		SPELL_D("god-fire")->cast_fire(target[i],me,SK,INN);
        message_vision(
        HIG "$N�����@�}�F�O�A���W�������]�����F�C\n" NOR,me);
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage/=2;
			message_vision(HIY "\n$N����@�ޡA�a�ۼƹD���l���h�F��աC\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}


void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
        add_action("do_spell_train","learn");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
        if(this_player()->query_temp("canadd_senwu")==1) call_out("senwuquest",1);
}
// train skill  ���\�� GUILDMASTER�|�۰ʩI�s
void train_skill_cost(object me,string argx)
{
   me->add("popularity",-2);
   return;
}
// train spell  ���\�� GUILDMASTER�|�۰ʩI�s
void train_spell_cost(object me,string argx)
{
  me->add("popularity",-2);
  return;
}
// advance  ���\�� GUILDMASTER�|�۰ʩI�s
void advance_cost(object me,string arg)
{
        int cost;
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

        return;
}

}

int do_spell_train(string arg)
{
        object me;
        me=this_player();
        if(this_player()->query("class2") != "���Z��") 
           return notify_fail("�A�èS���J���Z�i�������@�C\n");
        if( this_player()->query("popularity") < 2 ) 
           return notify_fail("�A���n�椣���A�ݨӿ���s�ä��Q�ЧA�C");
        GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
        return 1;
}

int do_skill_list(string arg)
{
        if(this_player()->query("class2") != "���Z��") 
           return notify_fail("�A�èS���J���Z�i�������@�C\n");
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // �קK�C�X�ˬd¾�~���T��
        write("\n");
        GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
        this_player()->delete("no_check_class");
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(this_player()->query("class2") != "���Z��") return notify_fail("�A�èS���J���Z�i�������@�C\n");
        if( this_player()->query("popularity") < 2 ) return notify_fail("�A���n�椣���A�ݨӿ���s�ä��Q�ЧA�C");
        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}

int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();

// ========================================================================
// join �[�J¾�~, �����n�ϥ� do_guild_join(),
// �p�G�Ův�n�ϥΦۤv���^���覡, �Х� do_guild_join_with_no_message()
// �Ǧ^�ƭ�, �A�ϥγo�Ǽƭȧ@�z�Q�����^���覡.
// ========================================================================
        //if(me->query("race") != "human" ) return 0;
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
               case -1: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
               case -2: notify_fail("�A�w�O��L�̬����{�̤F\n");break;
                case -8: notify_fail("�S���o�Ӫ����a");break;

        }

if(me->query_temp("canadd_senwu") > 1 && me->query("class1")=="���Z��" && me->query("level")==25)
         {       
            command("say �ܦn�I�ܦn�I�A�O�ڮv�̪��{�̡A��Ӥ]�O�ڪ��{����C");
            command("say �H�ᦳ����Z�N�������A�N�ӧ�ڡA�ڵ��A���I���I�C");
            command("pat " + me->query("id") );
message("world:world1:vision",HIY "\n\t�m�Z�L�ֳ��n�G�@�N�v�v ����s���F"+me->name(1)+HIY "�����Z�Ч̤l�C\n"NOR,users() );
            me->set("class2","���Z��");
            me->create_family("���Z��",3,"�Ю{");
            me->set("adv_class",2);
            me->delete_temp("canadd_senwu");
          }
          else    
          {
            command("say �o��"+ RANK_D->query_respect(me) +"�ڨä��Q���A���{�C\n");
          }
        return 1;
}

int do_advance(string arg)
{
        int j;
        object ob, me;
        ob = this_object();
        me = this_player();
        j=me->query("popularity");
        if(me->query("class2") != "���Z��") 
            return notify_fail("�A�èS���J�i�����Z�СC\n");


        if(me->query("popularity") < 3 ) 
            return notify_fail("�A���n�椣���A�L�k�A�ɤW�h�@�C\n");
        //�s�ץ��Aadv level ���n�� (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("�A���n�椣���C\n");
        else return GUILDMASTER->do_advance(ob,me,arg);

}

// ========================================================================
// �ϥ� advance �ɯŮɷ|�ѦҨ� guild_rank() �o�Ө��, �o�Ө�ƥi�H����
// ���a��¾�~rank.
// ========================================================================
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
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                                // LV 10 ~ 19
                        case 1: rank = "���Z�вĤT�N�Ю{"; break;
                                // LV 20 ~ 29
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                                // LV 30 ~ 39
                        case 3: rank = "���Z�Ф����C����"; break;
                                // LV 40 ~ 49
                        case 4: rank = "���Z�Ф����k�C�L"; break;
                                // LV 50
                        default: rank = HIR"���Z�Ф����ѷ��a"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                        case 1: rank = "���Z�вĤT�N�Ю{"; break;
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                        case 3: rank = "���Z�Ф����C����"; break;
                        case 4: rank = "���Z�Ф������C�L"; break;
                        default: rank = HIR"���Z�Ф����ѷ��a"NOR;
                }
        }
        return rank;
}
int accept_object(object who,object ob)
{
        object me,obj,newmob;
        me=this_player();
        obj=this_object();
        newmob=new(__DIR__"advmaster");
        if(ob->name()!="�ȱ�") return notify_fail("����s�i�D�A�G�ڤ��ݭn�o�تF��C\n");
        else {
        message_vision("$N���F$n�@��"+ob->name()+"�C\n",me,obj);
          say("����s�J�Ӫ��ݤF�ݳo�i�ȡA��M�宣���j�s�C\n");
          say("�A�u������s�W�W�i�i�����}�F�C\n"); 
        newmob->move("/open/world1/acme/area/f5");
        me->set_temp("canadd_senwu",1);
        destruct(ob);
        destruct(obj);
        return 1;
        }
}
void senwuquest()
{
      destruct(this_object());
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
message("world:world1:vision",HIW"\n  �Z�L�ǥX�F�@�h��H������:"HIW"\n\n\t���Z�дx�Юv�S�@����s���b"+ob->name(1)+"�⤤�C\n\n"+NOR,users());
        ob->add("popularity",3); //�n��
        tell_object(ob,HIW"(�]���A�����F����s�A�ҥH�o��F 3 �I�n��C)"NOR);
    "/open/world1/acme/area/senwu4.c"->open_skypool();
        ::die();
        return;
}
void heal()
{
     object obj;
     obj=this_object();
     if( obj->query("hp") < obj->query("max_hp")/4 )
     {
         command("exert bloodsky-force heal");
     }
     if(obj->query("mp") < obj->query("max_mp")/2 )
     {
         obj->receive_heal("mp",100+random(50));
         message_vision("$N���_���ӡA�ήi�F�����A�����صM�@�s�C\n",obj);
     }
}
