#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIM"���N"NOR, ({ "love bird","bird" }) );
        set("long", 
                "�ǻ����b�C�~�����P´�k�b�C�i���H�`���ѡA���O�s����H���������١A\n"
                "���̪����W���a���@�ǨǪ��߮�A���I�쪺�H�i��b�@�~�����|�ǳߨơA�O�ܦN�Ԫ��@�ذʪ��C\n");
        set("unit","��");

        set("race", "���~");
        set("limbs", ({ "�Y��", "����", "�ͻH", "��}","�e�}"}));
        set("verbs", ({ "claw","crash"}));
        set("age", random(5000));
        set("level",100);
        set("chat_chance",11);
        set("chat_msg",({
  (: command,"say ���H�`�ּ֧r�I" :),
  (: command,"say �Ʊ椵�Ѥ����ਣ��´�k��(o�so)" :),
}));
        setup();
}

void init()
{
        if( present("match-maker",environment(this_object())) )
        {
                command("follower match-maker");
                command("say �Ѥj�r, �٦b�V�r, ���I��������!");
        }
}
