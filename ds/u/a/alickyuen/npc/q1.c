#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�L��", ({"lam sze","lam","sze"}) );
	set("long", "�@�Ӳפ�L�Ҩƨƪ��H,���H�M�پK�~�C\n");
            set("nickname",RED"�K�~"NOR);
	set("race", "�H��");
	set("age", 40);
	set("level", 25);
	setup();
        carry_object( __DIR__"wp/moon_clip");
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
  object me,guard1,guard2,guard3,obj;
  obj=this_object();
  me=this_player();
  if(me->query_temp("naboo/hatred")>0)
  {
    if(me->query_temp("naboo/hatred")>5)
    {
       if(obj->query_temp("callguard")==0)
       {
         obj->set_temp("callguard",1);
         command("say �c��I�ǩR�ӡI�I");
         command("kill "+me->query("id"));
         say(YEL"�L��j�n�ܹD�G�ӤH�ڡI��o��Ȯ��U�F�I\n");
           say("\n�b�����I��M�X�{�F�T�W����I�I\n\n"NOR);
         guard1=new(__DIR__"npc/killer");
         guard2=new(__DIR__"npc/killer");
         guard3=new(__DIR__"npc/killer");
         guard1->move("/u/a/alickyuen/workroom2");
         guard2->move("/u/a/alickyuen/workroom2");
         guard3->move("/u/a/alickyuen/workroom2");
      me->set_temp("naboo/hatred",1);
       }
    }
    else {
      command("say �c��I�ǩR�ӡI�I");
      command("kill "+me->query("id"));
  }
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