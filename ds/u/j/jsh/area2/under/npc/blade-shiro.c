#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"修羅"NOR, ({ "shiro" }) );
        set("long","俎刃修羅，乃修羅域三大修羅之一，善常用刀，每一劈每一斬都可與天並齊。\n");
        set("level",40+random(2));
        set("age",150+random(50)); 
        set("title",HIG"俎刃"NOR);
        setup();
        carry_object(__DIR__"obj/shiro-blade")->wield(); 
} 
void die() 
{
    object ob; 
    if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);

    if( !ob ) { 
        ::die();
        return;
    } 
        message("world:world1:vision", 
    HIW"\n\t\t\t俎刃修羅死在"+ob->name(1)+"的手下！！\n\n"+NOR   
    HIW"\n\t\t\t並解開了"+HIG"※修羅綠封印※ \n\n"+NOR,users());
        ob->add("popularity",4);  
        ::die();
        return;
}

