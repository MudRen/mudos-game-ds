#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�y���~" , ({ "vagrant" }) );
        set("level",10);
        set("race","�H��");
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                         }));
        set("age", 50);
        set("long","�o�Ӭy���~���ݵۧA�A�A�y��ı�o���ƫD�`�A�Q���I���}�C\n");
        setup();
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
  i=ob->query_temp("superbug/hatred");
  if(ob->query_temp("superbug/hatred")==0)
  ob->set_temp("superbug/hatred",i+1);
        ::die();
        //destruct(this_object());
        return;

}

