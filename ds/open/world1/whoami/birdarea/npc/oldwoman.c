#include <ansi.h>

inherit NPC;
void create()
{
        set_name("�ѱC�C",({ "old woman","woman" }) );
        set("long","�@�ө~��b�y�������ѱC�C�A�ݦo��W�]���۳Q���W�r�˪�����\n"
                   "�A�A�K�F�ѳo�y�������W���G�M���O�ըӪ��E\n");
        set("gender","�k��");
        set("race","human");
        set("title",HIR"�y����"NOR);
        set("age",50+random(30));
        set("level",35);
        set("attitude","friendly");
        set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                                (:command,"say �ڥi�O�ѷ�q���O�I�Q�ոլݶܡH":),
        }));
        set("chat_chance",20);
        set("chat_msg", ({
                          (:command("yawn") :),
                          (:command("zzz"):),
        }));

      
   setup();
   add_money("coin",400 + random(400));           
}

