inherit NPC;
void create()
{
set_name("����",({"killer"}));
set("long", " �u���~�ӤH�A�A�H�����L���ؼФF�I\n");
set("race","�����H");
set("age", 30);
set("level", 25);
set("max_hp", 1000);
set("max_mp", 1000);
set("max_ap", 1000);
set("evil", 99);
set("combat_exp",100);
set_skill("sword", 100);
set_skill("dodge", 100);
set_skill("parry", 100);
set_skill("unarmed", 100);
set("chat_chance_combat", 100);
setup();
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
object obj,me;
  me=this_player();
obj=this_object();
  if(me->query_temp("naboo/hatred")>0)
  {
    command("say �c��I�ǩR�ӡI�I");
         obj->kill_ob(me);
  }
  else {
    command("stare "+me->query("id"));
  }
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
  i=ob->query_temp("naboo/hatred");
  if(ob->query_temp("naboo/hatred")==0)
  ob->set_temp("naboo/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}