#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����p");

 set("long",@LONG
�o�̬O�����p���_��, �A�ݨ즳�@�ӼC�O�b�o��, �Q�ӬO��
�F�����J�|���ͥ�����, �ܻ��^��, �p�G�q�o�̦A���_����ƤQ
�V, �N�|�i�J�Q�U�j�s���̨��j���骺�ϸz�D�F.
LONG
    );
 set("exits",([	"north":__DIR__"ten21",
		"south":__DIR__"ten2",
    ]));
 set("item_desc",([
        "�C�O":"�A�ݨ�W���g��: �J�|, �~�|�T�ӳu, �@�ͦ�L�M�q, ���ĵL��.... �z! �U���ݤ��M���F....\n",
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}