
#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���H", ({ "traveller","tr","���H" }) );
        set("level",1);
        set("long" ,"�@�ӥ��b���������H�A�L�]�������A�]���I�W���O��䪺�����C\n");
        set("age",20);
        set("chat_chance", 8);
        set("exp",10000000);
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
        {

        ob->add("popularity", 500); //�n��
 tell_object(ob,HIW"(�]���A�����F���H�A�ҥH�A�o��F 500 �I�n��C)\n"NOR);
}
        ::die();
        return;
}
