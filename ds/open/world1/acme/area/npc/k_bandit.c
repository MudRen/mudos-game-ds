#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���L�P", ({ "gin kore ya","gin","ya" }) );
        set("level", 15);
        set("race","�H��");
        set("gender","�k��");
        set("title","��L�j�s");
        set("age",40);
set("nokill",1);
        set_skill("blade", 30);
        set_skill("parry", 20);
        set_skill("dodge", 20);
        set("long","�L�������ˡA�y�W�@�����]�S���C\n");
        set("chat_chance", 10);
        set("chat_msg",({
              "���L�P�V�_�䪺�s�}�s�D�G��p�l�A�ڬݧA����줰��ɭԡI\n",
        }) );
        set("chat_chance_combat",50);
        set("chat_msg_combat", ({
              "���L�P�V�_�䪺�s�}�s�D�G��p�l�A�ڬݧA����줰��ɭԡI\n",
        }) );
        setup();
        carry_object(__DIR__"wp/blade3.c")->wield();
}
void init()
{
        object ob;
        ::init();
        call_out("greeting", 3, ob);
if(this_player()->query("nokill")<1)
{
     this_object()->kill_ob(this_player());
}
}
void greeting(object ob)
{
  object me;
  me=this_player();
  if(me->query("evil") > 0 && me->is_fighting() )
  {
     message_vision("���L�P���D�G�o��"+ RANK_D->query_respect(me) +"�A��ӬO�P�D���H�A�Ю��p�̥��e���L§�C\n",me);
     message_vision("���L�P���D�G�j�a����a�I\n",me);
     me->remove_all_killer();
  }
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->set_temp("killbandit",1);
        ::die();
        //destruct(this_object());
        return;

}
