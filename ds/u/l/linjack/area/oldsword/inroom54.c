#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s�i�ͽå𮧫�");
 set("long",@LONG
�o��O�V����s�i�ͽê��𮧫�, �o�Ǩͽó��O���D
��L��, ���O�٬O�񤣤W�w�g�b�V����ݤW��T�~���Ѩ�
��, ���X�W�ͽå��b���V��, �䤤���@�W�O����`�b�V
�m�H��.
LONG
    );
 set("exits",([ "north":__DIR__"inroom52",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
