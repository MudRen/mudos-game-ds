a
inherit NPC;
#include <ansi.h>
void create()
{
 set_name("�w�Դ��S�ͮ�",({"Kurast Cain","Cain"}));
 set("long","�w�Դ��S�ͮ��O�{���t���w�𪺻�ɪ�, �۶ǥL�O�O��
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
set("max_ap",900);
        set("guild_skills",([
        "sword":({110,4,80}),
        "blade":({110,4,80}),
        "dodge" : ({120,3,80}),
        "parry" : ({120,4,80}),
        "unarmed":({110,4,80}),
        "staff":({110,4,80}),
        ])  );
 set("attitude","peaceful"); 
 set("age",55);
 set("gender","�k��");
 set("level",45);
 set("title",HIW"������t��"NOR);
 set("nick",HIR"�t���w��t��"NOR);
 set_skill("staff",45);
 set_skill("dodge",35);
 set_skill("parry",40);
 set("guild_gifts",({6,4,0,10}));
 set("chat_chance",10);
 set("chat_msg", ({"�w�Դ��S�ͮ����D:�p�G���F���ӯ]�l, �ڪ��k�N�N�i�ͪ�󧹬�, �i�O...\n",
                   "�w�Դ��S�ͮ������l�F�@�f��, �A�w�w���R�X�ӹD:�ڥΤF����h��O�h�j�M, ���M�L�k���D�T������m�C\n",
                   (:command("think"):),
                   (:command("say"):),
 }));
 set("chat_chance_combat",200);
 set("chat_msg_combat",({(:command,"cast stone shield":),
                    (:command,"say �ݨӧA�C���F�@�ӽG�z���k�v...�K�K ":),
 }));
 set("talk_reply","�A�����ڤ@�I��(help)��?\n");
 set("inquiry/help","�ЧA���ڴM��@�ӦW��"�����k�]"���]�l, �ڥثe�u���D�L�b�վB�����@�a, ���O���t�@�Ӥ����W���O�q���ڵL�k�T������X������m�C\n");
 setup();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->query("id") != "element-pearl")
        {
           command("angry "+who->query("id"));
           command("say �o���O�ڷQ�n���]�l...�u!!!");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �A���߷Q������, �ڳ����D, 
���n���Z�ڤF�C\n");
             return 0;
           }
    message_vision("$N���F�w�Դ��S�ͮ��@�� "+ob->query("name")+"�C\n");
             command("smile");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
      object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
            command("say ��H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"�w�Դ��S�ͮ��p�ߪ����_�����k�], �ݵ۸̭��ܤƪ���m, �o�X�g�����Į��C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say �N�O�o�ӯ]�l...�ڪ������]�k�ש�i�H��F�������ҬɤF!!�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            message_vision(HIY"�w�Դ��S�ͮ��p�ߪ��⤸���T�l���i�w���ǳƪ��_����,�A��i�潴�̪����h�C\n"NOR);
            command("whaha");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            if(me->query("class1")  ) 
            {
              command("say " +  RANK_D->query_respect(me) + "�u�O���§A���ڧ�줸���k�]�C");
              command("shakehand "+me->query("id"));
              obj->delete_temp("givehat");
            }
            else {
command("say ���ѧڤ߱����n, �ڬݧA"+ RANK_D->query_respect(me) + "�����ײߤ����]�k���ѥ���, �����A�@�N�l�H���p���`�@�h�������]�k��?");
              obj->set_temp("givehat",i+1);
              call_out("givehat",2,me);
            }
            break;
          case 5:
            command("say �q���H��, ��t���w���@�A�ۤv���a�a, �n�n�ǲߤ����]�k������!!");

            message_vision(YEL"$N�`�`���@���`, ���L�w�Դ��S�ͮ�����$N�����N, ���������b��W\n"NOR,me);
            command("nod "+me->query("id"));
            message_vision(HIC"$�w�Դ��S�ͮ���������:�t���w�𦳨Ǧa��O�ʳ���, ����A��O���F�N�ۤv��L���ɥh�ݬݧa...\n"NOR,me);
            me->set("adv_class",1);
            me->set("class1","�����k�v");
            me->create_family("����",3,"�k�v");
        me->set("guild_rank","��J���������Ǯ{");
            obj->delete_temp("givehat");
            break;
      }
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
	
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIC"\n  ���j���ǥX�F�@�ӥO�H��Y������"HIC"\n\n\t��t�ۥ@�ɤ�����q��HIR�t���w��t�� �w�Դ��S�ͮ�HIC���M��ͦb"+ob->name(1)+"�C\n\n"+NOR,users()��W);
        ob->add("popularity",1);
        ::die();
        return;
}
