#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIC "�u���x�L" NOR , ({ "garrison" }) );
        set("level", 20);
        set("race","�H��");
        set("gender","�k��");
        set("age",30);
        set("int", 25);
        set_skill("sword", 40);
        set_skill("parry", 30);
        set_skill("unarmed", 30);
        set_skill("dodge", 40);
        set("long",
   "�@��u�@�����x�L�A�u���L�������滷��A�����O�{�u�t�d�A�٬O�Q�F�Q��C\n");
        setup();
        carry_object(__DIR__"wp/longsword1.c")->wield();
        carry_object(__DIR__"eq/boots.c")->wear();
        carry_object(__DIR__"eq/armor.c")->wear();
        carry_object(__DIR__"eq/ring.c")->wear();
        carry_object(__DIR__"eq/hat.c")->wear();
}
void init()
{
        ::init();
        if(!userp(this_player())) return;
        call_out("greeting", 0,this_player());
}
void greeting(object me)
{
  object obj;
  obj=this_object();
  if(!me) return;
  if(me->query_temp("SKYCITY/hatred")>0)
  {
    command("say �c��I�ǩR�ӡI�I");
         obj->kill_ob(me);
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
	message_vision(HIR"  �Ať��@�n�a�ۼ���B�宣���H���n�T����ӤѪšC\n"NOR,ob);
	message_vision(HIC"  �ѫ����x�L"HIR"�R�צa�q�ۡG�i�c��"+ob->name(1)+"�A�x���P�x���@��I�I\n"NOR,ob);
	message_vision(HIC"  �ѫ����ѷ�"HIR"�j�ܡG���Nť�O�A��"+ob->name(1)+"�̡A����L��j���I�I\n"NOR,ob);
  }
  ob->set_temp("SKYCITY/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}
