#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��L�j�s", ({ "bandit" }) );
        set("level", 9);
        set("race","�H��");
        set("gender","�k��");
        set("age",32);
        set_skill("blade", 30);
        set_skill("parry", 20);
        set_skill("dodge", 20);
set("nokill",1);
        set("long","�@�Ӿ�ܽݥغ��y�ˬͪ���L�j�s�C\n");
        setup();
        carry_object(__DIR__"wp/blade.c")->wield();
}
void init()
{
        object ob;
        ::init();
if(this_player()->query("nokill") < 1)
{
        this_object()->kill_ob(this_player());
}
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->set_temp("killbandit",1);
        ::die();
        //destruct(this_object());
        return;

}
