/**
 * Shadow's area [��o���� - �q�� - graveyard2]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short",HIG"�q��"NOR);
	set("long",@LONG
�I��q�����M�w�g�~�N�[���F�A���O�q�X�Ӫ��ƶq�B���a���s�H
�η����J�褧�઺�ӸO�A���i�ݥX��W�Ҥ��𬣡A�Q���b��ɩw�O�j
��H�a���ͦw�m���B�A�u�O���H�Ǵe���O�s���O���]�o�쥻�H�B��
�����I�a���|�S���A�i�Өϳo�I��q���_�����ø��^�H�ݵۥ|�P�}
�¤������X�ӻP���ͪ������ý��A�`ı�o���ز��W�����ߡC
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("no_clean_up", 0);
	set("exits",([
		"east": __DIR__"graveyard3",
		"west": __DIR__"graveyard4",
		"south": __DIR__"graveyard1",
		"north": __DIR__"graveyard21",
	]));
  
	setup();
	create_door("south","�q���j��","north", DOOR_OPENED, "nokey");
	
}

int valid_leave(object me, string dir)
{
	if( dir=="south" && !userp(me) )
		return notify_fail("���̥u�����a�~��q��C\n");
	return ::valid_leave(me, dir);
}
