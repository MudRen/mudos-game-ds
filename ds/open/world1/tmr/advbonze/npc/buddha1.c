// �|����ù�~���@

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("���ʪ���" ,({"bu dong jingang","bu","dong","jingang"}) );
        set("long",@LONG
���ʪ���
LONG
);
        set("age",200);
        set("race","�H��");
        set("title","�@�k�L��");
        set("level",40);
        set("attitude", "aggressive");
        set("gender", "�k��" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("staff",100);
          set_skill("jingang-finger",100);
        map_skill("unarmed","jingang-finger");
              set("str",60);
              set("con",60);
        setup();
        set_living_name("buddha-war-jingang");
                  set("combat_exp",500000);
                carry_object(__DIR__"eq/armor")->wear();
                carry_object(__DIR__"eq/cloth")->wear();
                carry_object(__DIR__"eq/helmet")->wear();
                carry_object(__DIR__"eq/boots")->wear();
                carry_object(__DIR__"eq/hands")->wear();
    if(random(10)>8 )
        carry_object(__DIR__"wp/fist3")->wield();
    else if(random(10)>8 )
        carry_object(__DIR__"wp/fist2")->wield();
    else
        carry_object(__DIR__"wp/fist")->wield();


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
        tell_object(ob,HIG"\t�A�o��@�I�n��C\n"NOR);
        ob->add("popularity",1); //�n��

        ::die();
        return;
}
