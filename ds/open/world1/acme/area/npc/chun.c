#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "�`�K�M" NOR , ({ "chun lin chang","chun","lin","chang" }));
        set("title", HIG "�a�誾��" NOR );
        set("race","�H��");
        set("gender","�k��");
        set("age",43);
        set("level", 20);
        set_skill("sword", 30);
        set_skill("parry", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 45);
        set("long",
           "�L�O�a��R�x�A�u���L�K�H�H�������ۨ��Ǫ��h�Q�C\n");
        set("chat_chance_combat",30);
        set("chat_msg_combat", ({
                "�`�K�M�ܹD�G�A����x���@��A���n�R�F�O�ܡI�H\n",
                "�`�K�M�ܹD�G�ӤH�r�I�I��o�ϸ鮳�U�F�C\n",
                   "�`�K�M�ܹD�G�A�����A�ڴN�ۧA���a�B�ݧA�E�ڡC\n",
        }) );
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
  object me,guard1,guard2,guard3,obj;
  obj=this_object();
  me=this_player();
  if(me->query_temp("SKYCITY/hatred")>0)
  {
    if(me->query_temp("SKYCITY/hatred")>5)
    {
       if(obj->query_temp("callguard")==0)
       {
         obj->set_temp("callguard",1);
         command("say �c��I�ǩR�ӡI�I");
         command("kill "+me->query("id"));
         say(YEL"�`�K�M�j�n�ܹD�G�ӤH�ڡI��o�ϸ鮳�U�F�I\n");
           say("\n�b�����I�����q��«�X�F�T�W�A��áI�I\n\n"NOR);
         guard1=new(__DIR__"superguard");
         guard2=new(__DIR__"superguard2");
         guard3=new(__DIR__"superguard3");
         guard1->move("/open/world1/acme/area/hotel2f");
         guard2->move("/open/world1/acme/area/hotel2f");
         guard3->move("/open/world1/acme/area/hotel2f");
      me->set_temp("SKYCITY/hatred",1);
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
  i=ob->query_temp("SKYCITY/hatred");
  if(ob->query_temp("SKYCITY/hatred")==0)
  {
message_vision(HIC"\n  ����ǥX�F�@�h��H������:"HIW"�§ʩR�x�`�K�M�Q"+ob->name(1)+"�����F�C\n\n"NOR,ob);
message_vision(HIC"  �ѫ����x�L"HIR"�R�צa�q�ۡG�i�c��"+ob->name(1)+"�A�x���P�x���@��I�I\n"NOR,ob);
message_vision(HIC"  �ѫ����ѷ�"HIR"�j�ܡG���Nť�O�A��"+ob->name(1)+"�̡A����L��j���I�I\n"NOR,ob);
  }
        ob->set_temp("SKYCITY/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}
