#include <ansi.h>
inherit NPC;
void create()
{
        set_name("������",({"in chen lee","lee"}) );
        set("long","�L�O�K�����@�k���@�A�q�L�y�W�i�ݥX�@�ƪZ�̮𮧡C\n");
        set("age",33);
        set("race","�H��");
        set("level",30);
        set("title","�q�K�����r�@�k");
        set("gender", "�k��" );
        set("chat_chance",5);
        set("chat_msg",({
            "���������D�G�ڤ@�w�n�Ĥ@�ӧ�쨺�ӤH�A�o�O�v�ŦѤH�a���h�J�I\n",
            "���������D�G�L�����Ӻ��I�쩳���ӤH�b���̡I\n",
            (: random_move :),
        }) );
        set_skill("unarmed",60);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("bagi_fist",70);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
        }) );
        set("inquiry/���ӤH","�N�O�ܤ[�H�e���������Ӱ���r�A�L���W�i�O�ܯ�����\n"NOR);
        set("talk_reply", "���������D�J�ַЦѤl�A�Ѥl�����ܡC");        
        setup();
}



