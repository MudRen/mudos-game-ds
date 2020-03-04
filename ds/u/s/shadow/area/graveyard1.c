/**
 * Shadow's area [��o���� - �q���J�f - graveyard1]
 */ 
#include <login.h>
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"�q���J�f"NOR);
	set("long",
"���ۨ��ۧA�~�M����F�@�ӵP�{�e�A���Y�@�ݡA��ФW�����i�H\n"
"�ݥX�D��"HIG"�u�I��q���v"NOR"�|�Ӥj�r�C�]�~�N�[�������Y�A��Ъ��|�P��\n"
"�w�鸨�A�i���R�����ý��]�����F��y�P�{�A��Y�㦹�q���������\n"
"�z�C���e��h�A�P�D�ҬO�@�y�S�@�y���X�ӡA���æa�w�m�b�o�����C\n"
"�C���C���W�A�b�H���O�a�W�������F�H����үd�U�Ӫ��e���I�ݨӳo\n"
"�����W���q���A���b�~�[���ץB�L�H�޲z�U�o��w�_���ø����F..\n"
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"south": __DIR__"oldway2",
		"north": __DIR__"graveyard2",
	]));
  
	setup();
	replace_program(ROOM);
}

