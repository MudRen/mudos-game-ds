#include <ansi.h>
inherit NPC;
void create()
{
 set_name("�ѱ��̤l",({"apprentice",}));
 set("long","                 �A�s�y�ݤF�@�ݳo�Ӧ��G�u���Q���j���̤l, �Q�ӥL�@�w
                 �O��L�ѱ��̤l���a��, ���L�a���k�a��, �ݥL�⤤�P�����Ӵ��h
                 �ˤ]�ᦳ���k, ��M�ä��n�ۭt."
     );
 set("attitude","peaceful"); 
 set("age",12);
 set("gender","�k��");
 set("level",10);
 set_skill("unarmed",20);
 set_skill("dagger",20);
set_skill("sky-dagger",10);
 set("chat_chance",5);
 set("chat_msg", ({"�ѱ��̤l��۪Ť����T�P! \n",
                    "�ѱ��̤l���ʤP��, �f����������...\n"

}));
 set("chat_chance_combat",200);
                         (:command,"say�n��! �ӹL���":),
 setup(); carry_object(__DIR__"eq/cloth")->wear();
carry_object(__DIR__"eq/dagger")->wield();}
