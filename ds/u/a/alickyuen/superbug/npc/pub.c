#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�s��" , ({ "drunkard" }) );
        set("level",10);
        set("race","�H��");
    set("chat_chance",10);
        set("age", 50);
        set("long","�@�Ӵ��o��K�p�d���k�l�A�A�̦n�O����L�A�K�o���`�C\n");
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
