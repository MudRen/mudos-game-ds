#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"������ձM�~�y�H"NOR , ({ "great hunter","hunter" }) );
        set("level", 35);
        set("con", 40);
        set("age",54);
        set("str", 50);
        set("dex",50);
        set("int",50);
        set("attitude","heroism");
        set_skill("parry", 60);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("dodge", 60);
        set("long","
���e�o�쨭�ۺ�˪��y�H�A�O������դ��������y��
�h�A�Ǫ��A�ѩ������۷��A�]���y�H�̧�O��������
���m�۳o�Ӧ�l�y�C���O�A�ߦ��̱M�~���y�H�~��ƥ���
¾�~��C\n");
        set("chat_chance", 20 );
        set("chat_msg",({HIC"�M�~�y�H���D:�h�A�Ǫ��A�A�b���̡H\n"NOR,
           (:command("tender"):),
           (:command("random_move"):),
           (:command("kill monster"):),
         }) );
        set("chat_chance_combat", 17);
        set("chat_msg_combat", ({HIR"�M�~�y�H�j�� : �u�i�c���å��T�����a�T�v\n"NOR,
           (:command("bite "+this_player()->query("id")):),
            }) );
     setup();
}      
