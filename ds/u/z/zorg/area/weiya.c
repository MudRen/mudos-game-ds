#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({"Wei Ya","ya","wei" }) );
        set("long", "
�@�Ӧ~���k�l�A���L�ת������A�������q�v�A�Ϧ��������b�p
�����ի�A���G�������A�q�R���s�s���ܤ�A�ŬX�����B�A���R���w�m
�b�ú٪��Z�J�y�W�C����L�զ�T��A���@�ɤW�̬��n���K���C�@�@�@
�A�}�l�V�o���h�A�����ѰO�h�`�N�o�ڥ��S���Ӷ�����I\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 18);
        set("attitude", "friendly");
        set("level", 3);
        set("evil", -999);
        set("combat_exp",2000);
        set_skill("unarmed", 4);
        set_skill("dodge", 10);
        set_skill("parry", 7);  
        set("env/wimpy", 30);        
        set("chat_chance",4); 
        set("chat_msg", ({   
        "������_�Y�R�R��ۤѪ�\n",
        "������L�Y�ӦV�A��F��S��^�Ѫ�\n",
        (:command(""):),
        (:command(""):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        "�����y�s�D:�������������",
        (:command(""):),
        }) );
        setup(); 
}





