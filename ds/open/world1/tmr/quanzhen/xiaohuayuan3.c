// xiaohuayuan3.c �p���
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�p���");
        set("long", @LONG
�o�̬O�����[�̪��p���A�شӵۤ@�ǥs���X�W�r�Ӫ����A
�騤��ۤ@�y���s�A���s�U�O�@��p�p���������A�����M�������A
�A�ݨ����Ʊ����⪺�����b�̭��y�v�C�v�a�C�ӹC�h�C�X�ӹD����
�b�o�̼^���ۡC
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "west" : __DIR__"xiaohuayuan2",
        ]));

        set("objects", ([
                __DIR__"npc/daotong" : random(2),
        ]));

	set("coor/x", -2710);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}