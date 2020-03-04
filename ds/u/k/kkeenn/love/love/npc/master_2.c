#include <ansi.h>
inherit NPC;
void auto_load();
void create()
{
        set_name(HIY"����"NOR,({"master sen","master","sen"}));
        set("gender", "�k��");
        set("long",@LONG
    ���������Ь����v�A�Z�\�`���i���I
(���������H�ѥ[����Х�exam�C)
LONG
        );
        set("level",55);
        set("age",50);
        set("adv_class",2);
        set("class1","������");
        set("class2","������");
        set("title","�m�������n�}�����v");
        set("nickname",HIM"�����P�L"NOR);
        set("addition_damage",60);
        set("addition_armor",140);
        set("MKS",150);
        set_skill("seven-love", 100);
        set_skill("masen_whip",100);
        set_skill("run_cloud",100);
        set_skill("force",100);
        map_skill("whip", "masen_whip");
        map_skill("dodge", "run_cloud");
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
  (:command("exert masen_whip"):),
  (:command("exert masen_whip"):),
}));

        set("chat_chance", 40);
        set("chat_msg",({
               (:auto_load:), 
                (:command("hmm"):),
	(:command("wield whip") :),
        }) );
        set("guild_skills",([ 
            "force":({130,2,80}),
            "seven-love":({140,2,90}),
        ]) );
        set("guild_gifts",({4,6,4,6}));
        setup();
          carry_object(__DIR__"obj/dragon_whip")->wield();
        add_money("coin",4000);
}
void init()
{
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
        add_action("do_skill_list","list");
        add_action("do_exam","exam");
        add_action("do_skill_train","train");
        if(!query("no_join") || query("no_join")!=1)
                add_action("do_guild_join","join");
        if(!query("no_advance"))
                add_action("do_advance","advance");
 }
void train_skill_cost(object me,string argx)
{
   me->add("popularity",-1);
   return;
}
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
int do_skill_list(string arg)
{
        if(this_player()->query("class2") != "������") 
           return notify_fail("�A�ä��O�������i���̤l�@�C\n");
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); 
        write("\n");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(this_player()->query("class2") != "������") return notify_fail("�A�ä��O�������i���̤l�@�C\n");
        if( this_player()->query("popularity") < 2 ) return notify_fail("�A���n�椣���A�ݨӭ����ä��Q�ЧA�C");
        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}
int do_guild_join(string arg)
{
        object ob, me;
        int i;

        ob = this_object();
        me = this_player();
if(me->query("race") != "human" ) return 0;
if(me->query("class2") == "������" ) return notify_fail("�A�w�g�O���������i���̤l�F�a�H\n");
        i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
        switch(i)
        {
                case 0: break;
               case -1: notify_fail("�A�w�O��L�������{�̤F\n");break;
               case -2: notify_fail("�A�w�O��L�������{�̤F\n");break;
                case -8: notify_fail("�S���o�Ӫ����a");break;
        }

if( me->query("class1")=="������" && me->query("level")==25)
         {       
            command("say �ܦn�I�ܦn�I�A�O�ڮ{�̪��{�̡A��Ӥ]�O�ڪ��{�]�C");
            command("say �H�ᦳ����Z�N�������A�N�ӧ�ڡA�ڵ��A���I���I�C");
            command("pat " + me->query("id") );
message("world:world1:vision",HIY "\n\t�m�����ֳ��n�G�����P�L �����������F"+me->name(1)+HIY "���u�ǧ̤l�C\n"NOR,users() );
            me->set("class2","������");
            me->create_family("������",2,"�̤l");
            me->set("guild_rank","���������i���̤l");
            me->set("adv_class",2);
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
        if(me->query("class2") != "������") 
            return notify_fail("�A�èS���J�i���������C\n");
        if(me->query("popularity") < 3 ) 
            return notify_fail("�A���n�椣���A�L�k�A�ɤW�h�@�C\n");
        //�s�ץ��Aadv level ���n�� (lv-20)^2
        if( (!arg || arg=="level") && j < (me->query("level")-20)*(me->query("level")-20) ) return notify_fail("�A���n�椣���C\n");
        else return GUILDMASTER->do_advance(ob,me,arg);

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
                        case 0: rank = HIM"���������u�ǧ̤l"NOR; break;
                                // LV 10 ~ 19
                        case 1: rank = HIM"���������u�ǧ̤l"NOR; break;
                        case 2: rank = HIM"���������u�ǧ̤l"NOR; break;
                                // LV 30 ~ 39
                        case 3: rank = HIC"�����A�{�@������"NOR; break;
                                // LV 40 ~ 49
                        case 4: rank = HIW"���������ʦ~�_�~"NOR; break;
                                // LV 50
                        default: rank = HIW"�i"HIM"���� "HIC"�E"HIR" ���D"HIW"�j"NOR;
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
message("world:world1:vision",HIW"\n  ����W�A�Ǿ_��:"HIW"\n\n\t�������������P�L�������b"+ob->name(1)+"��W�N�~�a�ѥ_�F�I\n\n"+NOR,users());
        ob->add("popularity",3); 
        tell_object(ob,HIW"(�]���A�����F�����P�L�A�ҥH�o��F 3 �I�n��C)"NOR);
        ::die();
        return;
}
int do_exam(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if(this_player()->query("class1") != "������") return notify_fail("�A�ä��O�������̤l�@�C\n");
	if( !this_player()->query("class2") )
	{
		command("yawn "+this_player()->query("id"));
		return 1;
	}
       command("say ��A�A�u���T�w�n�ѥ[����ܡH[answer yes or no]");
       add_action("do_answer", "answer");
        return 1;
}
int do_answer(string arg)
{
        object me,b;
        me=this_player();
  if(!arg) return notify_fail("�A�쩳�ӳo�̭n�F�ª� ?\n");
 if(arg=="yes")
 {
//mark by -Acme- message("world:world1:vision",HIM"\n�m�����ֳ��n�G\n\t"HIW"�������̤l"HIW+me->name()+HIM"�A�ѥ[�F�������X�v�j����A�ЦU�����L�[�o�I\n"NOR,users() );
 write("�����v��������F�@�T���ĵ��A�A��A�n�n�Q�ΡC\n");
 new(__DIR__"obj/pill10.c")->move(me);
            me->set_temp("kill_love",1);  
      me->move(__DIR__"../room1.c"); 
if( sizeof(filter_array( children(__DIR__"killer"), (: clonep :) )) < 2 )
{
     b = new(__DIR__"killer")->move(__DIR__"../room8");
     b = new(__DIR__"killer")->move(__DIR__"../room9");
}
 message_vision(HIR+me->query("name")+"���y���𪺽Ķi�ӡI\n"NOR,me); 
              return 1;
 }
 if(arg=="no")
 {             
        return notify_fail(HIW"�q�A���ѥ[���窺���|�C�r\n"NOR);
 }
 return notify_fail("�A�쩳�n���n�ѥ[��(yes),(no) ?\n");
}
void auto_load()
{
        object me=this_object();
        if(me->query("auto") > 0)
        {
 message_vision(HIG+me->query("name")+HIG"���������"HIW"�Ѥs��"HIG"���Y�C\n"NOR,me); 
 message_vision(HIG+me->query("name")+HIG"�C�C���V�W�@�a�A�����b���H�����e�C\n"NOR,me); 
        me->move(__DIR__"../room30");
    me->delete("auto");
        }        
        return;
}
