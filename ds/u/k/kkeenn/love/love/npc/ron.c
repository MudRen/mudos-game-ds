#include <ansi.h>
inherit NPC;
void create()
{
        set_name(MAG"���k�P�L"NOR,({"mu fu ron","ron"}));
        set("long" ,
"����������N�Ϫ̡A�_������[�����@�k]�K�O�Ѧo�ӳСA��O�����e�p��\n"
"�O��i�Ȫ��k�@��C\n");
        set("nickname", RED"�����@"NOR );
        set("attitude", "friendly"); 
        set("age", 120);
        set("gender","�k��");
        set("level", 60);
        create_family("������",15,"��~����");
        set("adv_class",1);
        set("combat_exp", 150000);
	set("class1", "������");
        set("guild_skills",([
  "dodge" : ({ 100,3,90 }),
  "whip" : ({ 110,3,80 }),
  "parry":({ 130,2,60 }),
 "masen_whip" : ({ 150,3,80 }),
  "force" : ({ 135,3,85 }),
  "unarmed" : ({ 100,3,80 }),
"run_cloud" : ({ 140,3,80 }),
]));

        set("title",HIW"��������~����"NOR);
        set_temp("apply/armor",35);
        set_skill("run_cloud",100);
        set_skill("masen_whip",100);
        set_skill("seven-love",100);
        set_skill("force",100);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        set("chat_chance_combat",40);
        set("chat_msg_combat",({
  (:command("exert seven-love love"):),
  (:command("exert masen_whip"):),
  (:command("exert masen_whip"):),
}));
	set("chat_chance", 40);
	set("chat_msg", ({
		(: command,"wield whip" :),
	}));

        setup();
        carry_object(__DIR__"obj/ghost_whip")->wield();
        add_money("coin",5000);
        }
void init()
{
        object me=this_player();
        object ob=this_object();
        ::init();
      if(me->query_temp("kill_love"))
        {
  if(me->query("combat_exp") > 150000) {
      ob->set("combat_exp",me->query("combat_exp") + 10000);
  return;
}
      ob->kill_ob(me);
                        return;
        }
        add_action("do_letter","say");
      if(me->query("class1") == "������" )
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
                        return;
        }
}
int do_letter(string arg)
{
        object me,ob,obj;
        me = this_player();
        ob = this_object();
 if(arg == "�z�̪�n��?" && me->query_temp("ljoin"))
     {
tell_object(me,ob->name()+HIG"���ѹĤF�@�f��A�S�Q��ڳo�{�]�ٺ�������..\n"NOR);
tell_object(me,ob->name()+HIG"�L���x�_�@���L���C\n"NOR);
tell_object(me,ob->name()+HIG"���D�G�Q�H���ߪ��Pı�u�n....\n"NOR);
tell_object(me,ob->name()+HIG"���D�G�B�͡A�����ڧ�o�ʫH�浹�s���A�o�|���ժ��C\n"NOR);     
       obj = new(__DIR__"obj/letter.c");
       obj->move(me);
      me->delete_temp("ljoin");
        return 1;

} else
{
tell_object(me,ob->name()+HIG"�κôb�������ݵۧA...@@\n"NOR);
}
return 1;
}

void die()
{
        object ob,me;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
                me=this_object();
                message_vision(
                HIG "\n$N�p�f�@�i�A���M�ϥΨ��Ъ��i"HIR"���]����j�k"HIG"�j�A�A�״��@�ۤv����O�I�I\n\n"
           +HIC "$N���_�⤤�@�l�A��t�ۥX�E�E�K�Q�@�Ӱ�l�K�K�³ª��]���$n\n�A�b$n�Q�઺���Ἲ�ä��ڡA$N���Ѥj�s�@�n�G�y\n"HIR"�r�Q����A���Ԧ��@�A���@�X�A���ΤƵL"HIC"�z�y�����K�Q�@�Ӱ�l�����M���X�@�ѩ_���L�񪺦��A\n����$nı�o�_�Ǥ��ڡA�@�ѱj�P����l�q$N���W��t�ĥX�V$n�����ӨӡI�I\n\n"NOR,me,ob);
                 if( random(10)>4) {
                        message_vision(HIR "�b$N�Q�n�{�����ڡA�Q���Ǫ��@��������H��k�A�רs�Q���Ѯ�l�����a�Q�����ƤV�����I�I\n" NOR,ob );
 ob->apply_condition("poison", ob->query_condition("poison")+(ob->query("hp")+random(ob->query("con"))) );
                        ob->set("hp",ob->query("max_hp")/100);
                COMBAT_D->report_status(ob);
                        tell_room(ob,CYN +"(" + ob->query("name")+"�f���A��g�Q���~�����F�L�h...)\n" NOR,ob);
                        ob->move(__DIR__"../room25.c");                   tell_room(environment(ob),ob->query("name")+"�����O�媺�����F�L�ӡA�u�I�v���@�n�L�b�A���}����Ÿ�ݤ��C\n",ob);
                        ob->start_busy(2);
                } else {
                        message_vision(HIW "$N�j�j�a���פF�o�P�R�@���A���]�y���~�o�a��...\n" NOR,ob );
                }

        message("world:world1:vision",
HIR"\n  �m�ʤѺ]�n:\n\n\t"HIC"�ѤU�Q�j���� "MAG"�����@ "HIC"���k�P�L���Q�@�W�L�W�p��"+ob->name()+HIC"���ѤF�I\n\n"+NOR
        ,users());
        ob->add("popularity", 5); 
        ::die();
        return;
}
int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}
int do_skill_train(string arg)
{
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}
