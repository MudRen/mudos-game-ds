#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����k", ({ "g" }) );
                set("level",1);
           set("gender","�k��");
setup();
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
HIC"\n  �ھڤp�H�Цt�h�Э��������G"HIW���ܡЩ{�e�Q"\n\n\t"+ob
->name(1)+"�߱�F�C\n\n"+NOR
        ,users());
        ob->add("popularity",1); //�n��
        ::die();
        //destruct(this_object());
        return;
}

