#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"修羅"NOR, ({ "shiro" }) );
        set("long","崩拳修羅，乃修羅域三大修羅之一，善常用拳，每每都有動地之量。\n");
        set("level",40+random(2));
        set("age",150+random(50)); 
        set("title",HIR"崩拳"NOR);
        setup();
        carry_object(__DIR__"obj/shiro-claw")->wield(); 
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
    HIW"\n\t\t\t崩拳修羅死在"+ob->name(1)+"的手下！！\n\n"+NOR   
    HIW"\n\t\t\t並解開了"+HIR"※修羅紅封印※ \n\n"+NOR,users());
        ob->add("popularity",4);  
        new->(__DIR__"evil2") move->("/u/m/moon/area2/under/shiro10);
        write("一波波的煙霧，飄散了過來••");
        ::die();
        return;
}

