#include <ansi.h>
inherit NPC;
void create()
{
       set_name("�j�ѹ�",({"rat","rat"}));
        set("level",8);
        set("race", "���~");
        set("age", 8);
        set("long", "�o�O�@�����j���ѹ�, �A�i�H�q�L�����������ݥX\n"
                    "�L���Ⱦj, �H�ΥL�y���A������, ���`�u���@����\n"
                    "�L�̨ä����H����, ������...���|�a...\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("attitude", "aggressive");
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
