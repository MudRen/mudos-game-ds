#include <ansi.h>
inherit NPC;
void create()
{
        set_name("流浪漢" , ({ "vagrant" }) );
        set("level",10);
        set("race","人類");
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                         }));
        set("age", 50);
        set("long","這個流浪漢正看著你，你頓時覺得恐怖非常，想快點離開。\n");
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

