#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"�m��"NOR,({"color ea","ea"}));
        set("long" ,
"���������ĤT�N�ǤH�A�w�g�m���_������[�����@�k]�A��O�����e�p��\n"
"�O��i�Ȫ��k�@��C\n");
        set("nickname", HIW"���N���@�k"NOR );
        set("attitude", "friendly"); 
        set("age", 25);
        set("gender","�k��");
	set("level", 25);
        set("class1","������");
        set("title",HIC"�������ĤT�N�ǤH"NOR);
        set_temp("apply/armor",15);
	set_skill("run_cloud", 75);
	set_skill("masen_whip", 80);
        map_skill("dodge","run_cloud");
        map_skill("whip","masen_whip");
        setup();
        carry_object(__DIR__"obj/whip7")->wield();
        add_money("coin",2500);
        }
void init()
{       
        object me=this_player();
        object ob=this_object();
        ::init();
      if( me->query("level") < 6  &&  !me->query("quest/love1") )
        {
  tell_object(me,ob->name()+HIG"���G�p�B�͡A���n�n�h�R��n�@�n�ܡH\n"NOR); 
  tell_object(me,ob->name()+HIG"���G�n�n�|�����S�§A���C\n"NOR);
  tell_object(me,ob->name()+HIG"���G�h�a�I�ڵ��A�C\n"NOR);                        return;
        }
      if(me->query_temp("kill_love"))
        {
      ob->kill_ob(me);
                        return;
        }
}
int accept_object(object me, object ob)
{
        object tob, herb,a;
        tob = this_object();
        if( ob->query("id")!="soft whip" ) return 0;
	if( me->query("quest/love1") ) 
	{
		command("?");
		return 1;
	}
        else {
                command("thank "+me->query("id"));
tell_object(me,NOR"("HIG"�m��"NOR"�b�A���j�N���Y�̦s�U�F3000������y�C)\n"NOR);
                me->add("bank/past",3000);
                me->set("quest/love1",1);
                destruct(ob);
        }
        return 1;
}

