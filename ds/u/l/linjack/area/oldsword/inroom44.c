#include <room.h>
inherit ROOM;
void create()
{
 set("short","�G�ְ�D���");
 set("long",@LONG
�o�ж����\�]�M�j�ְ�D����ǯu�O�����[���O, ���ز��`,
���׵L��. ��W���O�j���j�שM�W�n���s, �A���M���I�Q�Q���j
��, ���L�٬O���q����U��. ���ӤH��۵��R���b��Ѱs�a, ��
�ۨ����T�W�ͤk���Ǻƨ��ƻy.
LONG
    );
 set("exits",([ "south":__DIR__"inroom43",]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
