#include <room.h>
inherit ROOM;
void create()
{
        set("short", "MUSIC ROOM");
        set("long", @LONG
�o�̴N�O�j�a���ɰ���S�u�@�ɳ̱`�쪺�𮧤��B�A�ӳo�̻P�˪B�n
�͡B�ӤW�ӤU���n�F�~�A�j�a�ּּ֧֪����q�@���A�ǳƪﱵ���Ѫ��u�@
�C���䭼�D���j����ʤW���ۤ@���p�U�l( List )�n���O�n�O�q���s����
���A�I�۾��N�b����( ���O: singing �s�� )�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "up":__DIR__"sec5.c",
     
]));
        set("item_desc", ([
        "list" :"
====================[33m��[0m                    [33m��[0m======================== 
�@�B �ŬX
�G�B �W�ַP
�T�B Don't say you love me �O���p�R��
�|�B �A�R�ڶ�(�R�b�߸̽�����)
���B �w�o�w��
���B �ڷ|�Q�p
�C�B �O�A�ܤF�ܡH
�K�B �B��
�E�B �@���Y��
�Q�B �@�F�ʤF
�Q�@�B �O�ӵL�~
�Q�G�B I love you �L��
�Q�T�B �γ�
�Q�|�B �p�j �o�O�ڪ��W��
�Q���B �T�P�T��
�Q���B �d��
�Q�C�B �ܷR�ܷR�A
�Q�K�B FIRST Love
�Q�E�B LIGHT THE LIGHT (American Edition)
�G�Q�B ���w
�G�Q�@�B �沴�֤k��
�G�Q�G�B ����
�G�Q�T�B �f���}
�G�Q�|�B �R���N��
�G�Q���B �Q�R
�G�Q���B �֣{�A�ڸӫ���
�G�Q�C�B ���� 
�G�Q�K�B ���
�G�Q�E�B �O��
�T�Q�B �@�ӤH����m
�T�Q�@�B �ѤѶ}��

[36m(�I�q��singing �s�� [for �H])[0m
============================Update By Kkeenn@DS 2001/12/30==================
/n",
        ]));

        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/singer.c"   :1,
]));

        setup();
        replace_program(ROOM);

}
