#include <ansi.h>
inherit ROOM;
void create()
{
       set("short",HIY"�W���H���C��"NOR);
        set("long",@LONG
�W���H���C��O�ĺ��Ĵ��̨��w�諸�s�]�A�ר�O����A�]���b���
��ť��W���H���D���n�O�ݩ�N�Q���ơA�ǻ��u�nť��A�N�N��Ҧ��̹B
���|�����A�Ҧ����B���|��ӡA���L�p�G�����J�W�W���H�A�����藍�O��
��ȱo�������ơC���w�ܰs�پx�����u�O����A�o�̦P�˻E���F���֫_�I
�̡A�D���U���U�˪��Ǩ��B�_�I�A�H�Τk�Ĥl���ơC
LONG 
);
        set("exits",([
            "west":__DIR__"port_07",
                ]));
        set("objects",([
            __DIR__"npc/doctor_su":1,
            __DIR__"npc/owner":1,
            __DIR__"npc/waterman":2,
            __DIR__"npc/ad_mn":1,
                ]));

        set("world","world1");
        set("light",1);
        set("valid_startroom", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_clear_up", 1);
        set("map","hotel");
        setup();
        replace_program(ROOM);

}
