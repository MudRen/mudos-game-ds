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
        set("title",HIW"�l�l"NOR);
      set("level", 15);
        set("evil", 99);
        set("combat_exp",180);
        set("chat_chance",5);  
        set("chat_msg", ({   
        "�l�lĬ�Ϋܩ_�Ǫ��������A\n",
        "�l�lĬ�ΤQ����è���ʧ@���F�A�@�U\n",
        "�l�lĬ��A�R�X�F�@�ǲ��Φ���������G\n",
        "�l�lĬ��è�������j���t�Aı���L�O���O�����D\n",
      (: random_move :),    
}) ); 
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({ 
        "�l�lĬ����: I am going to tell my mom!!!\n",
        (:command("cry"):),
        }) );
       setup(); 
}


