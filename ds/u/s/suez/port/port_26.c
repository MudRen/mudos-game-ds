#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�����ӷ|");
        set("long",@LONG
�����O�ۤF�W���򳣽椰�򳣦����ӤH�A���O�L���O���F�����A���
�u�O��ƪ��R���n�_�Ӥw�A�p�G���L�����餣�O�����z�A�L�@�w�|����
�_�I�a�Ӥ��O�ӤH�C�̪�L���e���F��j���i��@�v�T���A�ҥH�b���̨�
����L�A�o��ӶR�F�誺�k�ʬO�n�ơA�]���o�˴N�i�H���촶�����f�f�F
�C���L��k���U�ȴN���Ӧn�F....
LONG 
);
        set("exits",([
            "west":__DIR__"port_25",
                ]));
        set("objects",([
            __DIR__"npc/cecily":1,
                ]));


        set("world","world1");
        set("light",1);
        setup();
        replace_program(ROOM);

}
