#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p��");
 set("long",@LONG
�A���_���Ө�F�o��, �o�̪����O�V�ӶV�}��, �P��
�C�쪺��s�n�]�w�R�F�U��, �A���_��@��, �ݨ�F�@��
�q�V���]���k��.

LONG
    );
 
 set("exits",(["north":__DIR__"bird1",
               "south":__DIR__"en44",
               ]));
 
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
