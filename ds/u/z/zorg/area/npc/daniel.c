#include <ansi.h>
inherit NPC;

void create()
{
        set_name("Ĭ�|��", ({"Daniel Su","su","daniel","daniel su","Su","Daniel"}) );
     set("long", "�L���������ɪ����ۧA�A�B�յۭn���A�@���A�ϧA�U�@�L���U���A
��̫ᳺ�M�ͥX�@�ѱ������ӫ�֪��Pı�C\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 15);
        set("attitude", "friendly");
        set("level", 2);
        set("level", 2);
        set("evil", 999);
        set("combat_exp",180);
        set("title",HIW"�i"HIG"�j"HIR"�l"HIC"�l"HIW"�j"NOR);
        set("chat_chance",5);  
        set("chat_msg", ({   
        "�l�lĬ�Ϋܩ_�Ǫ��������A\n",
        "�l�lĬ�ΤQ����è���ʧ@���F�A�@�U\n",
        "�l�lĬ��A�R�X�F�@�ǲ��Φ���������G\n",
        "�l�lĬ��è�������j���t�Aı���L�O���O�����D\n",
        (:command("get all"):),
        (: this_object(), "random_move" :),     //�|�ۤv���� 
}) ); 
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({ 
        "�l�lĬ����: I am going to tell my mom!!!\n",
        (:command("cry"):),
        }) );
       setup(); 
}


