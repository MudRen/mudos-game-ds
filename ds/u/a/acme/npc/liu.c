#include <ansi.h>
inherit NPC;
void do_jail();
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
        set("int",100);
        // �]�w�ݩʤ��t��, �C�@�����Ȧb�t9�ܥ�10����
        // �ӥB�|�����`�M�n��n���� 20                  by shengsan
        set("guild_gifts",({2,4,9,5}));
        set("guild_skills",([
               "dodge" : ({160,2,60}),
               "parry" : ({160,2,60}),
               "sword" : ({160,2,60}),
               "godsword" : ({140,2,70}),
               "meditate" : ({160,2,20}),
               "mirage-steps" : ({150,2,50}),
        ])  );
        set("guild_spells",([
               "god-fire" : ({170,2,60}),
//               "god-benison":({170,2,50}),
               "summon_ghost" : ({170,2,50}),
        ]) );
        set_spell("god-fire",100);
        set_spell("god-benison",99);
        set_spell("summon_ghost",90);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
        set("no_check_class",1);

        set("talk_reply","�@�H�o�ˤ��ΡA���A�i�H��train�ǲߧޯ�A��learn�ǲߪk�N�C");
        set("inquiry/�Z�N","���Z�Ъ��Z�\\�i�����T���A�Ĥ@�O�u��v�B�ĤG�O�u�r�v�A�ĤT�h�O�u�s�v�C\n");
        set("inquiry/��","�u��v�O�����Z�Ъ����\\�u��a�ơv�A���H�ثe���A�O�L�k�߱o���C\n");
        set("inquiry/�r","�u�r�v�O�����Z�Ъ��k�N�����A�u�n�A���z���A�ϱN�_�ӡA�i�O�²r�L��C\n");
        set("inquiry/�s","�u�s�v�O�����Z�Ъ��������N�A����n���ܡA���i�O�L�Ҥ��઺�C\n");
        set("chat_chance", 10);
        set("chat_msg",({
		(:command("think"):),
        (:command("exert mirage-steps"):),
        (:command("exert godsword"):),
        (:command("cast god-fire"):),
        (:command("cast god-fire"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
//                 (:command("cast god-benison"):),
//                 (:command("cast god-benison"):),
                  (:command("cast god-fire"):),
                  (:command("cast god-fire"):),
                  (:command("cast god-fire"):),
        }) );
        setup();
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
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C");
             return 0;
           }
message_vision("$N���F�y�L�Τ@��"+ob->query("name")+"�C\n",who);
             obj->start_busy(10);
             obj->set_temp("addsenwu",1);
             destruct(ob);
             call_out("addsenwu",1,obj);
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
        add_action("do_kill","kill");
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
            obj->delete_temp("addsenwu");
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
        message("world:world1:vision",
CYN"\n  �Z�L�ǥX�F�@�h��H������:\n\n\t�Z�L����u�W�t�@��v�y�L�βש�ѵ��F"+ob->name(1)+"�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
        ::die();
        //destruct(this_object());
        return;
}
int do_kill(string arg)
{
        object *ob,me;
        int i;
        me=this_player();
        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        if( is_fighting(me) ) return 0;
        command("say ���D�R�x�H���b���Z�Цa�L�̰ʲʡA�h���a�I�I\n");
        command("cast god-fire on "+me->query("id"));
        ob=all_inventory(environment());
        for(i=0;i<sizeof(ob);i++)
        {
                ob[i]->soldier_assist(this_object(), me);
        }
        return 1;
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
void do_jail()
{
    command("exert mirage-steps");
    command("exert godsword");
    command("cast god-fire");
   // command("hest ghost to defend liu");
}
