#include <ansi.h>
inherit NPC;
void create()
{
 int x;
      x = random(10);
        set_name( "���~", ({ "ghost" }) );
        set("level",30);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("sword",100);
        set("long" ,"�o�O���h�l�H�_�ٹP�J�·t���ĤG�寫�~���@,�ѩ�@�����~���ɤ�ӵu,�b���~�����q�٬���C\n");
        set("age",50);
        set("title",HIG"�������"NOR);
        set("chat_chance", 50);
        set("gender","����");
        set("chat_msg", ({
           (: random_move :),
       (:command("kill meo"):),
        (:command("kill guard"):),
        (:command("kill taoist"):),
        }) );
        setup();
if (x == 1 || x == 2)
        {
carry_object(__DIR__"eq/ghost_whip")->wield();
        }
    if (x == 3)
        {
carry_object(__DIR__"eq/ghost_blade")->wield();
        }
 if (x == 4)
        {
carry_object(__DIR__"eq/ghost_staff")->wield();
        }
 if (x == 5)
        {
carry_object(__DIR__"eq/ghost_fist")->wield();
        }
}
void init()
{
        object ob;
        ::init();
        if(!this_object()->visible(this_player())) return;
        if(this_player()->query("level") > 9 && userp(this_player()) )
        {
          this_object()->kill_ob(this_player());
        }
}
void die()
{
        int i;
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        i = random(23);
        ob->set_temp("skycitywar",i+1);
        if(i > 15) 
        {
          ob->add("popularity",1); //�n��
          tell_object(ob,CYN"\n�A�����F���~�A�o��F 1 �I�n��C\n"NOR);
        }
        ::die();
        return;
}
