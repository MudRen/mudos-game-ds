#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�ĺ��Ĵ������O");
        set("long",@LONG
���������O�A�����D�b�h�[�H�e�N�Y���F�A�]�S�H���D�W���O�g�Ǥ�
��A�����ۤ���C�ǻ��o�Ӭ����O�b�ĺ��Ĵ����H���e�N�s�b�F�C�{�b�o
�̫h�O�ӤH�̩۶Ҥ��⪺�a��A�]���\�h�_�I�̦b���@�̫᪺�ˬd�C
LONG 
);
        set("exits",([
            "east":__DIR__"port_12",
            "west":__DIR__"port_08",
            //"south":__DIR__"port_05",
                ]));
        set("objects",([
            __DIR__"npc/ad_wm":1,
            __DIR__"npc/waterman":3,
            __DIR__"npc/ad_mn":1,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int valid_leave(object me, string dir)
{
       if( dir=="east" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}

