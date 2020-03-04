// Write by -Acme-
// Update by -Acme- add AI

#include <ansi.h>
inherit NPC;
void normal_ai();
void combat_ai();
object liu=this_object();
void create()
{
        set_name("�y�L��" , ({ "invisible liu","liu" }) );
        set("long",@long
�L�O�i���Z�Уi���ХD�A�O�¾_�Z�L���Z�L�ѴL�A���o�ͱo�O��
���ت��A�@�Lź�ᤧ�A�C�A�i�H�M�L�@�_�Q�תZ�N���ơC
long
);
        create_family( HIC "�i���Z�Уi" NOR ,2,"�ХD");
        set("level",42);
        set("race","�H��");
        set("age",65);
        set("nickname","�t�W�@��");
        set("adv_class",1);
        set("class1","���Z��");
        set("gender","�k��");
        // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
        // �ӥB�|�����`�M�n��n���� 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("int",100);
        set("con",70);
        set("str",40);
        set("dex",75);
        set_temp("apply/hit",50);
        set_temp("apply/dodge",70);

        set("guild_skills",([
               "dodge" : ({120,3,70}),
               "parry" : ({130,2,60}),
               "sword" : ({130,3,70}),
               "godsword" : ({140,2,80}),
               "meditate" : ({120,3,80}),
               "mirage-steps" : ({140,3,80}),
        ])  );
        set("guild_spells",([
               "god-fire" : ({130,3,90}),
//               "god-benison":({170,2,50}),
               "summon_ghost" : ({130,3,90}),
        ]) );
        set_spell("god-fire",100);
        set_spell("god-shield",100);
        set_spell("god-benison",99);
        set_spell("summon_ghost",90);
        set_skill("meditate",100);
        set_skill("bloodsky-force", 90);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
        set("addition_damage",45);
        set("addition_armor",50);
        set("no_check_class",1);

        set("talk_reply","����v���L�ѤH�a�w�G�T�~���q�����A�p�������w�n.....");
        set("inquiry/�Z�N","���Z�Ъ��Z�\\�i�����T���A�Ĥ@�O�u��v�B�ĤG�O�u�r�v�A�ĤT�h�O�u�s�v�C\n");
        set("inquiry/��","�u��v�O�����Z�Ъ����\\�u��a�ơv�A���H�ثe���A�O�L�k�߱o���C\n");
        set("inquiry/�r","�u�r�v�O�����Z�Ъ��k�N�����A�u�n�A���z���A�ϱN�_�ӡA�i�O�²r�L��C\n");
        set("inquiry/�s","�u�s�v�O�����Z�Ъ��������N�A����n���ܡA���i�O�L�Ҥ��઺�C\n");
        set("chat_chance", 20);
        set("chat_msg",({
                (: normal_ai() :),
        }) );
        set("chat_chance_combat",200);
        set("chat_msg_combat", ({
                (: combat_ai() :),
        }) );
        setup();
        carry_object(__DIR__"wp/godsword.c")->wield();
        carry_object(__DIR__"eq/godneck.c")->wear();
        carry_object(__DIR__"eq/godarmor.c")->wear();
        carry_object(__DIR__"eq/godboots.c")->wear();
        carry_object(__DIR__"eq/godcloth.c")->wear();
        carry_object(__DIR__"eq/godhands.c")->wear();
        carry_object(__DIR__"eq/godhead.c")->wear();
        carry_object(__DIR__"eq/godlegging.c")->wear();
        carry_object(__DIR__"eq/godmask.c")->wear();
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
        map_skill("dodge","mirage-steps");
}

void normal_ai()
{
        /* �S�˳ƬޡA�h�ˬ� */
        if( !liu->query_temp("armor/shield") )
                command("wear all");

        /* �S��exert gosword �h,exert godsword */
        if( !liu->query_skill_mapped("sword") )
                command("exert godsword");      

        /* �ۥX���Z�� (cast god-shield) */
        if( !liu->query_temp("armor/shield") && ( liu->query("mp") > liu->query("max_mp")/2 ) )
                command("cast god-shield");

        /* ���ˮɷ|��_�� (exert bloodsky-force heal) */
        if( (liu->query("hp") + 200 < liu->query("max_hp") ) && liu->query("ap") > 50 )
                command("exert bloodsky-force heal");

        /* ��_���O (eat ap pill) */
        if( liu->query("ap") < liu->query("max_ap")/4*3 )
                command("eat ap pill");

        /* mp���֮ɷ|�߫�W�[mp (exert meditate) */
        if( (liu->query("mp") < liu->query("max_mp")/5 ) && liu->query("hp") > 1500 )
                command("exert meditate");

        return;
}
void combat_ai()
{
        int i;
        object *target;

        target = all_inventory(environment(liu));

        /* �Z���Q�����A�h�˦^�h */
        if( !liu->query_temp("weapon") ) 
                command("wield sword");

        /* �S�˳ƬޡA�h�ˬ� */
        if( !liu->query_temp("armor/shield") )
                command("wear shield");

        /* �S��exert gosword �h,exert godsword */
        if( !liu->query_skill_mapped("sword") )
                command("exert godsword");      

        /* ���ˮɷ|��_�� (eat hp pill) */
        if( liu->query("hp") + 1000 < liu->query("max_hp") )
                command("eat hp pill");

        /* ��_�]�O (eat mp pill) */
        if( liu->query("mp") + 1000 < liu->query("max_mp") )
                command("eat mp pill");

        /* ��_���O (eat ap pill) */
        if( liu->query("ap") < liu->query("max_ap")/4*3 )
                command("eat ap pill");


        /* �ĤHbusy �N���
           �Ϊ̦ۨ�ap�����L�k��godsword�S��]���
           �Ϊ̦ۨ�hp�����h�g����H�۫O
        */
        i=sizeof(target);
        while( i-- )
        {
                if( liu->is_killing(target[i]) || liu->is_fighting(target[i]) )
                {
                        if( target[i]->is_busy()
                            || (liu->query("ap") < liu->query("max_ap")/4*3)
                           || (liu->query("hp") < liu->query("max_hp")/2 ) )
                             if( userp(target[i]) ) command("cast god-fire on " + getuid(target[i]) );
                               else command("cast god-fire on " + target[i]->query("id") );
                }
        }
        return;
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="���Z�O�P")
        {
                command("? "+who->query("id"));
                command("say �b�U�ä��ݭn�o�ӪF��C");
                return 0;
        }
        else {
                if( obj->is_busy() || obj->is_fighting() || obj->query_temp("addsenwu") )
                {
                        command("whisper "+who->query("id")+" �ڥ��b���A��"+who->query("name")+"���@�U�C");
                        return 0;
                }
                message_vision("$N���F�y�L�Τ@��"+ob->query("name")+"�C\n",who);
                obj->set_temp("addsenwu",1);
                destruct(ob);
                call_out("addsenwu",1,obj);
                return 1;
        }
        return 1;
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
void addsenwu()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("addsenwu");
      switch( i ) {
          case 1:
            command("say �x�I�I�o���O�v�����O�P�ܡI�I");
            command("say �o��"+RANK_D->query_respect(me)+"�O�q��o���O�P���H");
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 2:
            message_vision(YEL"$N���G�o�O�L�v���ڥ浹�z���A�û��L�ѤH�a�p���ۦb�A�z���ξ�ߤF�C\n"NOR,me);
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 3:
            command("say ��Ӯv���w�n�A�ݨӧڬO�h��ߤF�C");
            command("smile");
            obj->set_temp("addsenwu",i+1);
            call_out("addsenwu",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 
            {
              command("say �o��" +  RANK_D->query_respect(me) + "�h�������C");
              command("bow "+me->query("id"));
              obj->delete_temp("giveplate");
            }
            else {
              command("say �ڬݧA�o"+ RANK_D->query_respect(me) + "�Z�������A�o�˧a�I�ѤҴN���A���{�I");
              obj->set_temp("addsenwu",i+1);
              call_out("addsenwu",2,me);
            }
            break;
          case 5:
            command("say �J�ڱз��L�M�q�A���j�ٮz�I");
            message_vision(YEL"$N���U�ӻ��D�G�v���I�̤l���w��Ӯv�����л��I\n"NOR,me);
            message_vision(HIY"�y�L�λ����a���$N���Y�A�û��D�G�n�I�n�I..\n"NOR,me);
            command("pat "+me->query("id"));
            me->set("adv_class",1);
            me->set("class1","���Z��");
            me->create_family("���Z��",3,"�Ю{");
        me->set("guild_rank","���Z�вĤT�N�Ю{");
            me->set("guild_gifts", ({2,4,9,5}) );

            obj->delete_temp("addsenwu");
            break;
      }
}
int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        GUILDMASTER->do_spell_list(ob,me,arg);
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
//      return 1;

}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
          if( !userp(me) ) return 0;
        if(me->query("class1")=="���Z��") return notify_fail("�A�w�O���Z�Ч̤l�F�C\n");
        if(arg!="���Z��") return notify_fail("�A�n���J���@�Ӫ���?\n");
        say("�y�L�Υ��۵o�T�A�èS���o�{�A�n�[�J�C\n");
        say("�y�L�γ��ۻy���D�G�v���L�ѤH�a�����w�n�A�w�Q�~�K�����q�����C\n");
        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
          if (me->query("level") > 25 ) return notify_fail("�A�ä��O�y�L�Ϊ��̤l�C\n");   //by tmr
        if (me->query("family/family_name")=="���Z��") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O���Z�Ю{�C\n");
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
        message_vision(HIR"\n\t\t$N�j�ܤ@�n�A�b�x�����e�ϥX�̫�@�ۡI�I\n"NOR,this_object());
        message_vision(HIW"\n$N�C�����F�A�F�@�ۡB��@�۪�����$n���ͯ}��I�I\n"NOR,this_object(),ob);
        message_vision(GRN"\t(�n��$n�߯����w�A�}�l�S�X�}��I�I)\n"NOR,this_object(),ob);
//        ob->start_busy(3);
        message_vision("$N����X�Q�A���ۻy�D�G"HIW"�u"HIG"�Ѧa�X�w�A���X���A�|�ɦX�ǡA�����X���H���ġC"HIW"�v\n"NOR,this_object());
        message_vision(HIR"\t�u��$n�{�������@�D"HIW"�y"HIR"���Z�u��"HIW"�z"HIR"����աA�Q�N�o�ֶ}�׺�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        message_vision(HIW"�b�����I�I$N���I��X�{�ƹD"HIR"���s"HIW"�A���˦ӥX�A���ĦV$n�I�I\n"NOR,this_object(),ob);
        message_vision(HIR"\t�u��$n�@�ɤ������L�ӡA�G�s�@�n�A�Q���s���]���F�I�I\n"NOR,this_object(),ob);
        ob->receive_damage("hp",ob->query("hp")*19/20);
        COMBAT_D->report_status(ob);
        message("world:world1:vision",
                CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�Z�L����u�W�t�@��v�y�L�βש�ѵ��F"
                +ob->name(1)+"�C\n\n"+NOR,users());
        ob->add("popularity", 5); //�n��
        tell_object(ob,HIW"(�]���A�����F�y�L�ΡA�ҥH�o��F 5 �I�n��C)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

void soldier_assist(object alert, object me)
{
        if( !living(this_object()) || is_fighting(me) )
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
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                        case 1: rank = "���Z�вĤT�N�Ю{"; break;
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = "���Z�вĤT�N�Ю{"; break;
                        case 1: rank = "���Z�вĤT�N�Ю{"; break;
                        case 2: rank = "���Z�Ф��P�K�}��"; break;
                }
        }
        return rank;
}
