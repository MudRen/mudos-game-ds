#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ù"NOR, ({ "shiro" }) );
        set("long","�Y����ù�A�D��ù��T�j��ù���@�A���`�ή��A�C�C�����ʦa���q�C\n");
        set("level",40+random(2));
        set("age",150+random(50)); 
        set("title",HIR"�Y��"NOR);
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
    HIW"\n\t\t\t�Y����ù���b"+ob->name(1)+"����U�I�I\n\n"+NOR   
    HIW"\n\t\t\t�øѶ}�F"+HIR"����ù���ʦL�� \n\n"+NOR,users());
        ob->add("popularity",4);  
        new->(__DIR__"evil2") move->("/u/m/moon/area2/under/shiro10);
        write("�@�i�i�������A�ƴ��F�L�ӡE�E");
        ::die();
        return;
}

