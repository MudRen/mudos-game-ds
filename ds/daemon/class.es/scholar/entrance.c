// Room: /daemon/class/scholar/entrance.c

inherit ROOM;

void create()
{
	set("short", "�ҳ��x");
	set("long", @LONG
�o�̬O�B�������䪺�ҳ��x�M�]�O�쳱��������H���Ȯɱ`�E����
�׸֤媺�a��M�x�e���Q�V�M����O�s���쳱�������A�h�����M�q�A�h
�򤤪������ν����s�s�����a�q�����䪺�s���M�_��M�n��U���ƤQ��
�٬W�M�`���\�h���ݪ��h�H�N�L�̪��@�~�K�b�o�̧Ʊ�o��Q�H���ѡM
���F�O�@�����L�M�K�ѮɩM�A�h��`���h��۽��M�M�����쳱������
�@�����C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/choyin/bridge5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
