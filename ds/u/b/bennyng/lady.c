// Modified from ES 2 drooler.c
// By Annihilator@Celestial.Empire (09/15/95)
// Last modified by Spock @ FF  97.Oct.30.
#include <ansi.h>
inherit NPC;
string *rnd_say = ({
        "HI !�A�n",
        "hello very body",
});
varargs void drool(string msg, string who);
void create()
{
        set_name( "�ʷP�p�߿�", ({ "SexyCat" }));
        set("level",100);
        set("title","�i�������ѡj");
        set("race", "�H��");
        set("gender","�k��");
        set("age", 20);
        set("long",
@LONG
�o�O�������M�ί��ѡA�@���]�������O�A�����߰ʡD
LONG
        );
        set("attitude", "friendly");
        set("welcome_msg", "�ʷP�p�߿߻��D: �w��Ө� �������Ωа��[�C\n" );
        set("chat_chance", 4 );
        set("chat_msg", ({
"�ʷP�p�߿ߦ����Ť@���A�ܥX�|�Ţ�Ѣ�, �}�l��s�_�ӡC\n",
"�ʷP�p�߿߸��W�ɤW�A���ߴڴڦa�ݵۧA�C\n",
"�ʷP�p�߿߮��ۦo���ʷP����A�b�A�����e�̨Ӯ̥h�C\n",
"�ʷP�p�߿ߦ����Ť@���A�ܥX�@�ӳU�U, �}�l�]���_�ӡC\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }));
        setup();
}
