#include <room.h>
inherit ROOM;
void create()
{
 set("short","������");
 set("long",@LONG
�o��O���j���@���ж�, �A���q�F�|�P, �G�m���M�t�F�@�I, 
���L�o�j�o�h�F, �j���i�H�Υ|���ӤH�S���D. �A�ݨ�o��w�g
���T�ӪZ�L�H�h�b�o���. ����ӬO�p�^�������H, �t�@�ӫh
�O���M�������W�H�h. �p�G�A�n��, �̦n���M�L�̥����@�f.  
LONG
    );
 set("exits",([ "south":__DIR__"inroom27",]));
 set("no_clean_up", 0);
 set("light", 1);
 setup();
 replace_program(ROOM);
}
