#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����" , ({ "killer" }) );
        set("level",40);
 set("race", "�H��");
        set("age", 30);
        set("long","�@�ӱ���A�L���b���������a�ݨӬݥh�C\n");
    set("chat_chance",10);
        set("chat_msg",({
    // (: random_move :),
}));
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
ob->set_temp("killed_killer",1);
        ::die();
        //destruct(this_object());
        return;
}

