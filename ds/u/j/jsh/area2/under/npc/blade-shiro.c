#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"��ù"NOR, ({ "shiro" }) );
        set("long","�[�b��ù�A�D��ù��T�j��ù���@�A���`�ΤM�A�C�@�A�C�@�ٳ��i�P�Ѩû��C\n");
        set("level",40+random(2));
        set("age",150+random(50)); 
        set("title",HIG"�[�b"NOR);
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
    HIW"\n\t\t\t�[�b��ù���b"+ob->name(1)+"����U�I�I\n\n"+NOR   
    HIW"\n\t\t\t�øѶ}�F"+HIG"����ù��ʦL�� \n\n"+NOR,users());
        ob->add("popularity",4);  
        ::die();
        return;
}

