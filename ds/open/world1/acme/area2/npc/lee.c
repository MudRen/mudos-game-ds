#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���妨",({"wen chen lee","lee"}) );
        set("long","�L�O�K�����@�k���@�A�q�L�y�W�i�ݱo�X���G���Ǥ��@�СC\n");
        set("age",33);
        set("race","�H��");
        set("level",25);
        set("title","�q�K�����r�@�k");
        set("gender", "�k��" );
        set("chat_chance",5);
        set("chat_msg",({
            "���妨���D�G�A�٬O���ӻ{�A�O�ǧڭ̤��Ȯ�F�I\n",
            "���妨���D�G�L�������I�کʤl�i���O�ܦn���I�A�������I\n",
        }) );
        set_skill("unarmed",50);
        set_skill("dodge",50);
        set_skill("parry",40);
        set_skill("bagi_fist",60);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
                  (:command("exert bagi_fist"):),
        }) );
        setup();
}
