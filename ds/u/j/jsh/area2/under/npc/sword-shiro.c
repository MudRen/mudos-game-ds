#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"修羅"NOR, ({ "shiro" }) );
        set("long","文咒修羅，乃修羅域三大修羅之一，善常用咒，每一動每一語都有其變化。\n");
        set("level",40+random(2));
        set("age",150+random(50)); 
        set("title",HIB"文咒"NOR);
        setup();
        carry_object(__DIR__"obj/shiro-sword")->wield(); 
} 
void die() 
{
    object ob,x; 
    if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);

    if( !ob )
  
    if(ob->query_temp("king",3)
    {
        ::die();
        return;
    } 
        message("world:world1:vision", 
    HIW"\n\t\t\t文咒修羅死在"+ob->name(1)+"的手下！！\n\n"+NOR   
    HIW"\n\t\t\t並解開了"+HIB"※修羅藍封印※ \n\n"+NOR,users());
        ob->add("popularity",4);   
        add->ob_temp("king",1); 
        x=new(__DIR__"beast");
        x->move(environment());
        ::die();
        return;
}

