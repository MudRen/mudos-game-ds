#include <room.h>
inherit ROOM;
void create()
{
 set("short","�O�L��");
 set("long",@LONG
�z! �A�@�}��L�ӳo�̴Nı�o�����Q�@�ѱ���������, �w��
�@��, ���e�ɬO�ǻ����T�����T, �����ꤣ���ꪺ�_�S�r�~, �A
�ݰ_�Ӥw�g�Q�e�̵����F....�i�O�e�̬ݰ_�ӨS���D�ʧ����A
���N��, �u�O�n�ۧA��, �����A���|�k�ʦӤw. �[��F�@�U�|�P
�a��, �Aı�o�A�Ө�F�@�B�p�g�c���F.
LONG
    );
 set("exits",([ "east":__DIR__"jungle18",
                "north":__DIR__"jungle15",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}