#include <ansi.h>
inherit NPC;

void create()
{
        set_name(WHT"���^��"NOR,({"weasel king", "king" }) );
        set("long",@LONG
    �����F����ìV���ܺت��j���ͪ��A�w�g�ݤ��X�e�쥻�O�����
���A�u���D�L�{�b�ݰ_�ӴN�O�@���Τj���^���Ӥw�I�e���w��B�r�F
��^�ӱ_�ޤ���ۡA�ݨe�}�U�n�����ۤ���H�H

LONG
);
        set("title","��S");
        set("race", "���~");
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "���", "�y��", "����", "�y��","����",
        }) );
        set("age",100+random(19));
        set("level",15);
        set("int",20);
        set("gender","����");
        set("attitude","killer");
        set("verbs", ({ "bite","claw" }) );    
        setup();
        carry_object(__DIR__"obj/obj2");
}
