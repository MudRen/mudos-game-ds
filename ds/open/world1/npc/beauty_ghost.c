#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�p��", ({ "beauty ghost","ghost" }) );
        set("race","human");
        set("level",28);
        set("age",18);
        set("evil",-20);
        set("long",@LONG
�b�A���e�������զ�k�l�a�a�g�g�A����ܼҽk�A�����i�H
�ݨ�o���R�����e�A�]����������s��ҫ��C�ӳQ�`���C
LONG
);
        set("chat_chance",30); 
        set("chat_msg",({
                (:command("sigh"):),
                "�p�źG�H���y�W�A�������G�Q��F�ƻ�A�����S�X�L���A���ӹĮ��C\n",
                "�p�Ũn�ۧA�@�A�A�ϩ�ť��o�b���ۡC\n",
                "�p�Ż����a�I��ۡG�u���ڡ��A�b���̡��v\n",
        }) );
        set_skill("unarmed",30);
        set_skill("dodge", 40);
        set_skill("parry", 10);
        setup(); 
        carry_object(__DIR__"../eq/moon_skirt")->wear();
}
