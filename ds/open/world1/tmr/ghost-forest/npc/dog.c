#include <ansi.h>
inherit NPC;

void create()
{
        set_name(CYN "��r" NOR ,({"random-bite dog","dog"}) );
        set("long",@LONG
��r���ѷ������c������Ҿ��E�Ӧ������~�A��ʴݴc���ɶݦ�A�A
���g�N�a�o�{��r���b�C�Z�ۤ@����O�O���׶��A�L�@�ӬݡA���M�o�{�O
�����֤֤k���Y�I
LONG    
        );
          set("race","���~");
        set("attitude", "aggressive");
        set("unit","��");
        set("title","���~");
        set("age",50);
        set("level",30);
        set("chat_chance",10);
        set("chat_msg",({
                  "��r���j�f�j�f�r�ۤ@���׶��A�d���{�䪺��ĥ|�q...\n",
                "��r�~�a�o�X�@�}�R�q�n....\n",
        }) );

        set("limbs", ({ "�Y��", "����","�ݳ�","����","�e�}" }) ); 
        set("verbs", ({ "bite" }) );
        set("addition_armor",50);
        add("apply/hit",60);
        setup();
    carry_object(__DIR__"eq/randombite-finger")->wear();
       set_living_name("ghost-forest-war-ghost");
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

         ob->add("ghost_forest_war",2);
         if(ob->query("ghost_forest_war") > 2 )
        {
                tell_object(ob,HIG"�A�o��@�I�n��C\n" NOR);
                ob->add("popularity",1); //�n��
                ob->set("ghost_forest_war",0);
        }
        ::die();
        return;
}

