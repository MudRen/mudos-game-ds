#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ù"NOR, ({ "shiro" }) );
        set("long","��G��ù�A�D��ù��T�j��ù���@�A���`�ΩG�A�C�@�ʨC�@�y�������ܤơC\n");
        set("level",40+random(2));
        set("age",150+random(50)); 
        set("title",HIB"��G"NOR);
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
    HIW"\n\t\t\t��G��ù���b"+ob->name(1)+"����U�I�I\n\n"+NOR   
    HIW"\n\t\t\t�øѶ}�F"+HIB"����ù�ūʦL�� \n\n"+NOR,users());
        ob->add("popularity",4);   
        add->ob_temp("king",1); 
        x=new(__DIR__"beast");
        x->move(environment());
        ::die();
        return;
}

