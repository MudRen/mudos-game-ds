inherit ROOM;

void create()
{
	set("short","�Ԥ뤧��");
	set("long", @LONG
�@�i�J���B�A�A���۸T���P��@�}���ġC�]���o��Ĳ�ةҤΪ���
�O�ǵ}�@���_�A�䤤�٦��\�h�O�A�s���X�W�r���C�o���h���_�����O
��ڪ��e���̦b�樫�j���n�_���ɡA�_�ۦU�ت��M�I�Ҩ��W�o�쪺�C
���F�y�֨�L���ڤH�̡A�L�̯S�O�N�_���d���|�|���a�^�s�H�c�ө�
�m�󦹡C�Ҧ����ڤH�b�ϥγo���_�����ɡA���Ӥ��h�P�¨åB�n�n��
���C

LONG
	);
	set("exits",([
  "south" : __DIR__"room5.c",
  "north" : __DIR__"room11.c",
]));
	set("objects",([
__DIR__"item/equip_box" :1,
]));
/*	set("item_desc",([
  "�B��":@DESC1

                              �H
                              ��
                              ��
                              ��
                              
                              ��
                              ��
                              ��
                       �P     �H
                       ��     
                       ��       
                              
DESC1
,
]));
*/
	set("light",1);
	set("no_kill",1);
set("no_goto",1);
	setup();
	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
}

