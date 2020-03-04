#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "ĵ�ö���" NOR , ({ "guard leader","leader","guard"}) );
        set("title", HIW "Naboo�@�ö�" NOR);
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
       set("level",40);
        set_skill("sword", 60);
        set_skill("parry", 50);
        set_skill("dodge", 80);
        set("long",
        "�L�O�@�ӭt�d�O�@Naboo���w�����H�C\n");
        setup();
        carry_object(__DIR__"wp/hlasersword")->wield();

}
void init()
{
        ::init();
      add_action("do_kill","kill");
        if(!userp(this_player())) return;
        call_out("greeting", 0,this_player());
}
void greeting(object me)
{
  object obj;
  obj=this_object();
  if(!me) return;
  if(me->query_temp("NABOO/hatred")>0)
  {
    command("say �c��I�ǩR�ӡI�I");
         obj->kill_ob(me);
  }
}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("say ���D�Rĵ�ä]�Q��?!�h���a!!!\n");

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

          switch(random(4)) {
        case 0: command("say ���D�R�S�̡̭T�������U�o�ӥǤH�T\n"); break;
        case 1: command("say �ܹD�R�]�o�F�M�|�]���F�q�A�A�٬O�֧֧���N��a�I\n"); break;
        case 2: command("say �ޡT�A�Q�F����S"); break;
        case 3: command("say �ӤH���T���U���ӥi�ê��å�T"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}
void die()
{
  int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
  i=ob->query_temp("NABOO/hatred");
  if(ob->query_temp("NABOO/hatred")==0)
  ob->set_temp("NABOO/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}





