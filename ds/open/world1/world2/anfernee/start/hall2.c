#include <path.h>

inherit ROOM;
//string look_sign(object me);
void create()
{
	set("short", "�ɪŨ��Y");
	set("long", @LONG
�o�̬O���]���������Y�C�F�䪺��W�����F�j�N�L�h���e���γ\�h�^
�i���ݪ��O���A������W�h���F�\�h�{�N����ުZ������Ų�C�A�ݨ�F��
�B����M�_�䪺���W���O��ۡi�j���کСj�B�i�����کСj�P�i�����ک�
�j�|�Ӥp�r�C
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
 "north" : __DIR__"hall3",
 "south" : __DIR__"hall",
 "east" : __DIR__"pastroom",
 "west" : __DIR__"nowroom",
	]) );
	set("item_desc", ([
//		"note": (: look_sign :),
//		"�i��": (: look_sign :),
	]) );
	set("light",1);
	set("no_fight",1);
	set("no_kill",1);
	setup();
}
/*
string look_sign(object me)
{
   if( file_size("/open/world2/anfernee/start/note.txt") > 0 )
   {
    me->start_more( read_file("/open/world2/anfernee/start/note.txt") );
    return "\n";
   } else return " SORRY. �����غc��. \n";
}
*/
