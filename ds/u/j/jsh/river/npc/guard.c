#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�����u��", ({ "guard" }) );


        set("level",25);
        set("age",35);
        set("gender", "�k��");
        set("long",
"�@�u�������u�áA���j�ªZ�C\n"
);
        set("chat_chance",5);
        set("chat_msg",({
                (:command("yawn"):),
                "�����u�ä��ɪ����U���@. . . .\n",       
        }) );
        setup();
        add_money("coin", 50);
        carry_object(__DIR__"wq/short-pike")->wield();
} 
void init()
{       
        object ob=this_player();

        ::init(); 
        if(ob->query_temp("sky-town-killer")==1) 
        {
        this_object()->kill_object(ob); 
        }
        return;
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
   HIW"�i�ѪŤ����j"+HIR""+ob->query("name")+"�Q�ؤU���H�ؤl�F�I\n"NOR,users()); 
   ob->add_temp("sky-town-killer",1);
   ::die();
   return;
}

