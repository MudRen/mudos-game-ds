#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�w�Դ��S�ͮ�" , ({ "kurast cain","cain" }) );
        set("long",@LONG
�w�Դ��S�ͮ��O�{���t���w�𪺻�ɪ�, �۶ǥL�O�O��
�ǧQ�@�ڱڤH, �p�G�Ǩ��ݹ�, �]���n�i�H��������L
�b��t�����]�k�譱���ޥ��p�������W, �L�C���K��H
�ۤv���O�q�E���۵M�ɪ������I�i�X�ө��N, �L�u�}��
�Ѹ����L�b�ǲߤ����]�k�����W�L�����Q, �o�]�y���F
�L���餣�α`�H���j��, ���L�N�R�������ί�����t�I
�i���j�j�k�N�O�H�̹�L�`�O�h�ۤS�q�S�Ȫ��߲z, ��
�ަb����, �L���ܵۤ@��t���⪺���O, ���O�U�O�H��
�H�ӷX�������H�ΥL��äW�Ѵc�]���Y�Ҧ�s�Ӧ�����
�N�Ҵ��o�X���C�����~�K�O�L���H�̲`�誺�L�H, ��
�ޥL���]�k�w���G�ϥL�֦��ѯ��@�몺�O�q, ���L�ܦt
�������³z�X�H�H���s�T...
LONG
);
        create_family( HIC "�t���w��" NOR ,2,"�t��");
        set("level",45);
        set("race","�H��");
        set("age",55);
        set("nickname","������t��");
        set("adv_class",1);
        set("class1","�t���w��");
        set("gender","�k��");
        set("con",45);
        set("wit",6);
        set("str",30);
        set("guild_skills",([
               "dodge" : ({120,3,70}),
               "parry" : ({130,2,60}),
               "sword" : ({130,3,70}),
               "meditate" : ({120,3,80}),
        ])  );
        set("guild_spells",([
               "god-fire" : ({130,3,90}),
               "summon_ghost" : ({130,3,90}),
        ]) );
        set_spell("god-fire",100);
        set_spell("god-benison",99);
        set_spell("summon_ghost",90);
        set_skill("bloodsky-force", 90);
        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("godsword",100);
        set_skill("mirage-steps",100);
        set("addition_damage",45);
        set("addition_armor",120);
        set("no_check_class",1);

        set("talk_reply","�A�����ڤ@�I��(help)��?");
        set("inquiry/help","�ЧA���ڴM��@�ӦW��"HIR"�����k�]"CYN"���]�l, �ڥثe�u���D�L�b�վB�����@�a, ���O���t�@�Ӥ����W���O�q���ڵL�k�T������X������m�C\n"NOR);
        set("chat_chance", 20);
        set("chat_msg",({
                (:command("think"):),
                   (:command("say"):),
        }) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("cast god-fire"):),
        }) );
        setup();
        map_skill("sword", "godsword");
        map_skill("dodge","mirage-steps");
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") != "element gem")
        {
           command("angry "+who->query("id"));
           command("say �o���O�ڷQ�n���]�l...�u!!!");
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �A���߷Q������, �ڳ����D, ���n���Z�ڤF�C");
             return 0;
           }
             message_vision("$N���F�w�Դ��S�ͮ��@��"+ob->query("name")+"�C\n",who);
             command("wahaha");
             obj->start_busy(10);
             obj->set_temp("gem",1);
             destruct(ob);
             call_out("gem",1,who);
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
void gem()
{
      int i;
      object me,obj;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("gem");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
          return;
        }
      switch( i ) {
          case 1:
            message_vision("$N�p�ߪ����_"HIR"�����k�]"NOR", �ݵ۸̭��ܤƪ���m, �o�X�g�����Į��C\n",obj);
            obj->set_temp("gem",i+1);
            call_out("gem",2,me);
            break;
          case 2:
            command(YEL"say �N�O�o�ӯ]�l...�ڪ������]�k�ש�i�H��F�������ҬɤF!!\n"NOR);
            obj->set_temp("gem",i+1);
            call_out("gem",3,me);
            break;
          case 3:
            message_vision(HIY"$N�p�ߪ��⤸���T�l���i�w���ǳƪ��_����,�A��i�潴�̪����h�C\n"NOR,obj);
            command("smile");
            obj->set_temp("gem",i+1);
            call_out("gem",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 
            {
              command("say " +  RANK_D->query_respect(me) + "�u�O���§A���ڧ�줸���k�]�C");
              command("shakehand "+me->query("id"));
              obj->delete_temp("gem");
            }
            else {
              command("say ���ѧڤ߱����n, �ڬݧA"+ RANK_D->query_respect(me) + "�����ײߤ����]�k���ѥ���, �����A�@�N�l�H���p���`�@�h�������]�k��?");
              obj->set_temp("gem",i+1);
              call_out("gem",2,me);
            }
            break;
          case 5:
            command("say �q���H��, ��t���w���@�A�ۤv���a�a, �n�n�ǲߤ����]�k������!!");
            message_vision(YEL"$N�`�`���@���`, ���L�w�Դ��S�ͮ�����$N�����N, ���������b��W\n"NOR,me);
            message_vision(HIC"�w�Դ��S�ͮ���������:�t���w�𦳨Ǧa��O�ʳ���, ����A��O���F�N�ۤv��L���ɥh�ݬݧa...\n"NOR,me);
            command("think "+me->query("id"));
            me->set("adv_class",1);
            me->set("class1","�t���w��");
            me->create_family("�t���w��",3,"����");
            me->set("guild_rank","�t���w�����");
            obj->delete_temp("gem");
            break;
      }
  return;
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
}
int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();

        if(me->query("class1")=="�t���w��") return notify_fail("�A�w�O�t���w�𪺶��̤F�C\n");
        if(arg!="�t���w��") return notify_fail("�A�n���J���@�Ӫ���?\n");
        say("�w�Դ��S�ͮ����۵o�T�A�èS���o�{�A�n�[�J�C\n");
        say("�w�Դ��S�ͮ����D:�p�G���F���ӯ]�l, �ڪ��k�N�N�i�ͪ�󧹬�, �i�O...\n");
        say("�w�Դ��S�ͮ������l�F�@�f��, �A�w�w���R�X�ӹD:�ڥΤF����h��O�h�j�M, ���M�L�k���D�T������m�C\n");
        return 1;   
}
int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(me->query("level") > 24 && me->query("class2")=="�t���w��" )
        return notify_fail("�A���O�t���w�𪺶��̡C\n");
        if(me->query("class1")=="�t���w��" )
        return GUILDMASTER->do_advance(ob,me,arg);
        else 
                return notify_fail("�A���O�t���w�𪺶��̡C\n");
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
HIC"\n  ���j���ǥX�F�@�ӥO�H��Y������:\n\n\t��t�ۥ@�ɤ�����q��"HIR"�t���w��t�� �w�Դ��S�ͮ�"HIC"���M��ͦb"+ob->name(1)+"�⤤�C\n\n"+NOR
        ,users());
        ob->add("popularity",3); 
        tell_object(ob,HIR"(�]���A�y�����j�����_��A�ҥH�o��F 3 �I�n��C)"NOR);
        ::die();
        return;
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
                                
                        case 0: rank = "��J���������Ǯ{"; break;
                                
                        case 1: rank = "�y�����Ѫ��p�k�v"; break;
                                
                        case 2: rank = "�p��ުk���G�N�v"; break;
                                
                        case 3: rank = "�ײߩG�N���G�k�v"; break;
                                
                        case 4: rank = "���a�������]�k�v"; break;
                                
                        default: rank = HIC "�t���w�𤧤j�k�v" NOR;
                }
        }
        else
        {
                switch( lv )
                {
                                
                        case 0: rank = "��J���������Ǯ{"; break;
                                
                        case 1: rank = "�y�����Ѫ��p�k�v"; break;
                                
                        case 2: rank = "�p��ުk���G�N�v"; break;
                                
                        case 3: rank = "�ײߩG�N���G�k�v"; break;
                                
                        case 4: rank = "���a�������]�k�v"; break;
                                
                        default: rank = HIC "�t���w�𤧤j�k�v" NOR;
                }

        }
        return rank;
}


