#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�B��",({ "liu ui","liu","ui" }) );
        set("title",HIY "����" NOR);
        set("long",@LONG
�A���e�o�ӤH, �i�O���ӫ�, �˽�ʻ������B��, �ݥL�@���ضQ��
�繢, �K���D�L�i�O�Ӧ������ժ��H, �L���G�n�����дo.
LONG    
);

        set("race","�H��");
        set("age",50);
        set("level",15);
        set("attitude","friendly");
        set_skill("dodge",30);
        set_skill("unarmed",30);
        set_skill("parry",20);
         set("chat_chance", 10);
        set("chat_msg_combat", ({
                "�B�Ի��D�G�ӫ���I����I�֨������ڡI\n",
                (:command("sigh"):),
         }) );
set("talk_reply", @LONG
����...�ڪ��k�ण���F...
LONG );
set("inquiry/�k��", @LONG
�ڪ��k��s���Ѧt,�o���M���ܤF,�A�i�H���ڧ�o��??
LONG );
setup();
add_money("coin",2000);           
}

