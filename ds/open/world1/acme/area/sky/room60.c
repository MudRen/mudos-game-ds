// Room60.c

inherit ROOM;

void create()
{
        set("short","�i�k�۰�j");
        set("long", @LONG
�Ө�o�̧ϩ��m���H���P�ҡA�@���R���F���M���R��
���ɪ��i�H�ݨ�\�h�øV���~�b�o�̼^�x�b�A�F�䦳�ӯ�
�b�s�W���զ�H���b��ۤT��۹��I����G���b�⮩�ۤ�
��C
LONG
        );
        set("exits", ([
                "west": __DIR__"room25",
        ]));
        set("light",1);
        set("objects",([
                "/open/world1/npc/goldman2" : 1,
		__DIR__"item/goldman2" : 1,
        ]));
set("no_goto",1);
        setup();
}
