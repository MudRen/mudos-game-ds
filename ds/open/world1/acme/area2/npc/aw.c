#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�ƵL��",({"aw wu hui","hui"}) );
        set("long",
"�A���e�@�G�A���T�Q�o�쨭�ۥզ�A���զp�ɡA���׽������t�x�k�l\n"
"�ҧl�ަ�A���n���ݫe�e���C������A�t�����իC���|�u�����C��\n"
"���^��Q���A������M�A�@���K�o����Z�N�y�ڤ����C\n"
);
        set("age",33);
        set("race","�H��");
        set("level",25);
        set("attitude", "peaceful");
        set("title","�i�Ʊ����j�ĥ|�N�̤l");
        set("gender", "�k��" );
        set("Merits/wit",1);
        set("chat_chance",6);
        set("chat_msg",({
            "�ƵL�����D�G�A�N�ӻ{�a�A�O�A���L�ת��ä�F�C\n",
            "�ƵL�����D�G�I���A�A�쩳�N�������H�è���h�F�I���D�n�ڭ̧�A�a�ȤF�ܡH\n",
        }) );
        set_skill("unarmed",70);
        set_skill("sword",70);
        set_skill("force",80);
        setup();
        carry_object(__DIR__"wp/longsword2")->wield();
}
