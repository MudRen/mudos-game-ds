#include <path.h>
inherit MOBROOM;
void create()
{
	set("short", "���]�~��");
	set("long", @LONG

  �o�̬O���]���~���a, �����٪��F�@�Ǥp��M�@�Ǳq�ӨS���ݹL���p��
���J�C�����٦����p����, ���L�̭������X�G���F, �٦��@�Ƕ������M�콦
�U�C

LONG
	);
set("exits", ([ /* sizeof() == 3 */
  "east" : LOGIN_NOW,
  "north" : __DIR__"room5",
]));

//        set("light",1);
        set("outdoors","land");
	set("chance",50);	//�h�� 50% �����v�|�X�{�Ǫ�.
	set("mob_amount",3);	//�h�̦h�X�{�T�өǪ�.
	set("mob_object",({	//�]�w�Ǫ��ɦW.
	__DIR__"npc/bug",
	__DIR__"npc/mosquito",
	}) );
	setup();
	
	//�`�N, �~��MOBROOM�� �����i�H�� replace_program(ROOM);
}
