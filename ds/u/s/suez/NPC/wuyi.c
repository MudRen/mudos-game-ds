#include <ansi.h>
inherit NPC;

void create()
{
       set_name("�d�@",({"wu yi","wu"}));
       set("long",@LONG
    �L�O���Z�y�L�Ϊ��o�N�̤l�A������ۮv���F����]���A�i�O�L�ۤv
�߸̷Q�۳o�@�����O�ȱo���A�٦��@�I�o�ӧ̤l�D�`�n�ǡA�i�O���Z�к�
�ּƪ���Z�������H�C
LONG);
       set("gender","�k��");
       set("age", 30);
       set("level", 35);
       set("nickname",HIW"´������"NOR);
       create_family( HIC "�i���Z�Уi" NOR ,3,"�̤l");


        set_spell("god-fire",70);
        set_spell("god-benison",50);
        set_skill("godsword",80);
        set_skill("mirage-steps",90);


       set("chat_chance", 10);
       set("chat_msg", ({
            (:command("hmm"):),
                  (:command("exert godsword"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
        
             }));


        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
                  (:command("exert godsword"):),
                  (:command("cast god-benison"):),
                  (:command("cast god-fire"):),
                  (:command("exert mirage-steps"):),
                  (:command("cast god-benison"):),
                  (:command("cast god-fire"):),
        }) );

    
        setup(); 
       carry_object("/open/world1/acme/area/npc/wp/sword2")->wield();
       carry_object("/open/world1/acme/area/npc/eq/surcoat.c")->wear();
        carry_object("/open/world1/acme/area/npc/eq/wrists")->wear();         

}
