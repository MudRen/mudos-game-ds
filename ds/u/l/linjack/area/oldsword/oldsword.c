#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","�j�C�F");
 set("long",@LONG
�o�̴N�O�ǻ������j�C�F, �Y�S���@�w���l�O�Ӥ��F��. �̭�����
�F�ѤU�W�C, �Y�O�b�v�����Ӫ��ɨ�, ���a�K�����{�{, �Y�q�C�B����, 
�K�|ı�o���B���o�ۤ@�D���t�L�񪺲H�����~, �ӤZ�H�S���i���k����
��, ��M�|�N���a�ǻ����@�B�P��. �Y�O����, �h���~�|�ƥh����, ��
�L���j�C�F���H�Ϧ�ı�o�|�B���K�Ȥϥ�, ���o�H�H����.
LONG
    );
 set("exits",([
               "east":__DIR__"mount1",]));
 set("light",1);
 set("objects",([
		__DIR__"npc/shura":1,
 ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

