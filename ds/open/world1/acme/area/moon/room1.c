#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", HIC"�s�H�c�j��"NOR);
        set("long",@LONG

�A�ݤF�ݥ|�P�A���F���e�o���o���۲H�H�C����~�����j���v���~�A
�O�@�M�s��L�䪺��D�@�ɡA���F��ۤ��~�O�L�����C�A���Y��V��
�šA�x�B�B�B���M���@�Ӥ񥭱`��G�j�F�n�X�����Ŧ��G���b�ѻ�
�A�o�쩳�O���^�ƩO�H��ۺ������ö��V�۪��v���h�A�A�~�o�{��
���v�W��B���--�s�H�c--�T�Ӥj�r�A��ӳo�N�O�Z�L�ǻ���������
����--��ڪ��ھڦa�C

LONG
        );
        //set("outdoors","land");
        set("light",1);
        set("exits",([
  "north" : __DIR__"room2.c",
]));
        set("item_desc",([
  "���v": "�o�������o�X�H�H���C����~�A�W���J�F�T�ӥj�r--�s�H�c�C\n",
]));
        set("moon_club_out",1); //������|�X�f
      set("no_goto",1);
        set("str_room",1); // add by whoami 2006.06.13
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" ) tell_object(me,"�A�榣�����}���v�¸��Y���h�C\n");
        return ::valid_leave(me, dir);
}

