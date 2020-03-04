//��P�ȴ̪��}�G�f�f��I
#include <ansi.h>
inherit NPC;
void create()
{
   set_name("�C�p��",({"yen-lu-yu","yen"}));
   set("long","�@�쨭�����n�A�y�J�}�G�����k�����b�o�̡A�o���G�ߤ�\n"
                    "���ۤ@�ǭW�o�A����۵��~�Į�C\n");

   set("level",27);
   set("title",MAG"�ȴ̦���"NOR);
   set("gender","�k��");
   set("age",23);
   set("adv_class",1);    
   set("class1","�K�P��"); 
   create_family( MAG "�K�P��" NOR ,21,"�N�z���D");

   set("guild_skills",([  
             "dodge":({110,2,100}),  
             "dagger":({120,2,70}),   
             "unarmed":({170,2,50}),
             "parry":({110,2,70}),  
        ]) );

   set("guild_gifts",({-2,-2,7,17}));

   set("dex", 77);
   set("evil",27);

   set("chat_chance",9);
   set("chat_msg",({(:command, "unwield dagger":),
                    (:command, "sigh":),
                    (:command, "say �L....�{�b�����D���ˤF...":),
                    
}));

   set("inquiry/name", "�W�r�ܡH�p�G�L�ٰO�o�ڪ��W�r�N�n�F.....��......
            �C�p�ɤ��O�ڪ����W�A���O�j�a���o�˥s�A�ȭ�
            �N�o�˺٩I�p�k�l�a�C\n ");
  set("talk_reply","�ȭ��A�u�n�ߡA�i�O�o�O�p�k�l���p�ơA�٬O���·ФF�C");

  set("chat_chance_combat", 17);
  set("chat_msg_combat", ({
      "�C�p�ɭ��ۤj�ۡG�u�A�̳��ۭt�ڡI�I�v\n",
      command("wield dagger")
     }) );

        setup();
        add_money("coin", 700);
        carry_object(__DIR__"wp/stonedragon_d.c");
        carry_object(__DIR__"eq/sky-walk_b.c")->wear();
        carry_object(__DIR__"eq/soft_dress.c")->wear();
}
void init()
{
        ::init();
        add_action("do_kill","kill");
        add_action("do_say","say");
        add_action("do_inquiry","inquiry");
        add_action("do_skill_list","check");
        add_action("do_spell_train","learn");
        add_action("do_skill_train","train");
        add_action("do_advance","advance");
}
int do_kill(string arg)
{
  object obj;
  obj=this_object();
  if(arg != "yen" && arg !="yen-lu-yu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;

     command("slap "+this_player()->query("id"));
     say(HIG"�C�p�ɫs�誺���D�G�u�ڳQ�H�a�ۭt�F�A�L�]���ӱϧڡC�v\n"NOR);
     command("angry");
     command("wield dagger");
     say(HIR"�C�p�ɲ������~���j�s�G�u�n�I�A�̳��ۭt�ڡA��..�ڸ�A�̫��F�I�I�v\n"NOR);

     obj->kill_ob(this_player());
}
int do_inquiry(string arg)
{
    if(arg != "�K�P��" ) return notify_fail("�A�n��ť(inquiry)����H�H\n");    
    else{
	if (this_player()->query("class1")=="�K�P��") 
	{
        tell_object(this_player(),"�C�p�ɤp�p�n����A���D�G�u�b���Y���a�U���K�ǡA�u�n�H�ڱЪ���k����(push)�a�O�N�i�H�i�h�F�C�v\n");
        return 1;
}
    
     else{
    say("�C�p��ť��o�T�Ӧr�n���Y�F�@��I\n");
    command("whisper "+this_player()->query("id")+" �o��ȭ��A�Q���D�K�P�����ơH");
    command("hmm");
    command("whisper "+this_player()->query("id")+" �K�P���b�ƭӤ�e�G�D����....");
    command("whisper "+this_player()->query("id")+" �ڭ̬O���n�U�s�ĶR�A�~�ݦs�U�Ӫ��K�P���̤l�C");   
    command("whisper "+this_player()->query("id")+" �q���ڭ̴N�b�o�̤@���w������@��۶ҤH�~�C");
    command("whisper "+this_player()->query("id")+" �����դU�O�_�@�N�U�ڭ̤@�u���O�C");      
    command("whisper "+this_player()->query("id")+" �[�J(join)�ڭ̺K�P���n�ܡH");
    add_action("do_guild_join","join");
    return 1;
    }
}  
}
int do_say(string arg)
{
    if(arg != "���L�v" && arg !="������" )  return 0;
    else{
    say("�C�p��ť��o�ӦW�r�A��M����y�����F�C\n");
    command("say �o��ȭ�....�A�����쭷...��...��......��...?");
    add_action("do_nod","nod");
    return 1;
    }
  
}    
int do_nod(string arg)
{
       if(arg == "yen" && arg =="yen-lu-yu" )  
    {
     command("smile");
     command("say ��..��..����...����....�����....?"); 
     if(this_player()->query_temp("quest/eight")== 0) return 0;  
     message_vision("( $N�⭷�L�v���ܥ����i�D�F�C�p�ɡC )\n",this_player());
     command("blush");
     command("say ��ӭ������٩��ۧ�.....�`���٨S�ѤF�K�P��.....");
     say ("�C�p�ɤ@�y���֪��ҼˡA�C�Y�����D�b��Ǥ���...");
     
     return 1;
    }
      
}

int accept_object(object who,object ob)
{
       int gain;
        if(ob->name()!="�j�Ѫ����J")
                return 0;

          else {

           say("�C�p�ɬݨ�o�F���M�y��@�ܡC\n");
           command("say �o�A�o��ȭ��A�O�q���̮��ӳo�F�誺�H\n");
           if(this_player()->query_temp("quest/story")== 0) return 0;
           message_vision("( $N���C�֪��Ƥ@���@�Q���i�D�F�C�p�ɡC )\n",this_player());
           command("sigh");
           command("say ��ӬO����....�������@�w���N���D�F....�ҥH�~����ڳ��v������.....");
           destruct(ob);
         gain=this_player()->query("level")*1000+5000+random(1000);
           this_player()->add("exp", gain);
           tell_object(this_player(),HIR"�A�o�� "+gain+" �I�g��ȡC\n"NOR);
           say("�C�p�ɻ����N�ݵۻ��誺�ѪšA�����Q���d�s�C\n");
           this_player()->delete_temp("quest/story");

        message("world:world1:vision",
      HIC"\n  �Z�L���a�X�H�[���K�P�����������ש�Q"+this_player()->name(1)+"�Ѷ}�F�T�T\n\n"+NOR
        ,users());
           return 1;
           }

}
void relay_emote(object ob, string verb, object me)
{
        if( !userp(ob) ) return 0;
        switch(verb) {
        case "sex":
                command("slap "+ob->query("id") );
                command("say �ȭ��I�A�ӹL���F�I");	
                break;
        case "kiss":
                command("slap "+ob->query("id") );
                command("say �ȭ��I�A�ӹL���F�I");	
                break;
        default:
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
        me->delete("no_check_class");
        return 1;
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

        GUILDMASTER->do_advance(ob,me,arg);
        return 1;
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
                        case 0: rank = HIC"�K�P�������p�f"NOR; break;
                        case 1: rank = HIY"�i�R���K�P���k�̤l"NOR; break;
                        default: rank = HIM"�K�P���v���Ѫe"NOR;
                }
        }
        else
        {
                switch( lv )
                {
                        case 0: rank = HIC"�K�P�������p��"NOR; break;
                        case 1: rank = HIY"���쪺�K�P���k�̤l"NOR; break;
                        default: rank = HIM"�K�P�����ۯ}��"NOR;
                }
        }
        return rank;
}
int do_guild_join(string arg)
{

        object ob, me;
        int i;

        ob = this_object();
        me = this_player();
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
                case -1: command("whisper "+me->query("id")+"  ��ӡA�դU�w�g�O"+me->query("class1")+"�����{�F...�u�O�i���C");break;
                case -2: command("say �ڡI�A�O"+me->query("name")+"�j�L�I�p�f�����������s�A�u�O��§....");break;
                case -3: command("say �o....��ӻդU�ëD�P�D���H...�٬O�O�I�o�y�V���a...");break;
                case -4: command("say ��....�դU���Ť���....����?");break;
                case -5: command("say ���a�� termstr �èS���j�� termnum �ȡC");break;
                case -6: command("say ���a�� termstr �èS������ termnum �ȡC");break;
                case -7: command("say ���a�� termstr �èS���p�� termnum �ȡC");break;
                case -8: command("whisper "+me->query("id")+" �դU...�ڭ̳o�̬O�u�K�P���v...�ЧO�}�����F..");break;
                default: command("whisper "+me->query("id")+" �Ӧn�F�I�p�G�n�ǪF�辨�ްݧ�(check)�A���ΫȮ�C");
        }
        
        return 1;
}
