inherit ROOM;

void create()
{
        set("short", "���ɤ���");
        set("long", @long
���e���@�y�q�J���]������ �w �ѯ���A�ǻ����j�H�e�̭����
�\�h���J�H�������F�P�c�]�C�Ӳ{�b�w���@�s�P���̬����񪺤H�ҩ~
��A�L�̦ۺ٬����ڡA�����M�w�g�䤣�쯫�]���ܸ�F�A��������
��~�����ɴ�����աC������f�A�K�i�H�ݨ�u�@�ѯ��𪺨�L�J��
 �w �̭{�ǻP����k�A���H�ݤF���T�ߥͷq�ȡC�{�����������O����
�W�s�����@�ѶդO�A���L�b�W��P��O�譱�A�w�g�W�V�\�h�����|�C

long);
        set("exits", ([
  "south" : __DIR__"ladder-1",
]));
	set("objects", ([ "/open/world1/npc/goldman.c" : 10 ]));
        set("god_club_out", 1);
        set("light", 1);
        setup();
        replace_program(ROOM);
}

