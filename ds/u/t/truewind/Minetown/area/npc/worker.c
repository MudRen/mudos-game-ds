#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIG"��z"NOR"�q�u",({"weak worker","worker"}) );
	set("long", @LONG
    �@�ӥͯf���q�u�A�L�̤��_�����ۻy�A���������F���D�A�A��
�T�w�L�쩳�O�]�e�f�٬O����]���~�ܦ����ѳo�Ӽˤl�A�A��ı�٬O
�����ӤӾa��L�~�n...�C
LONG
);
	set("race", "�H��");
	set("age", 30);
	set("level", 15);
        set("attitude","killer");
        set("chat_chance", 5);
        set("chat_msg", ({
       (: command("say ��...���ڤ�...") :),
       (: command("say ����...���ڭ���...") :),
       (: command("say ����n�o...�n�o...") :),
}));
	setup();
	carry_object(__DIR__"eq/eq.c")->wear();
}
