inherit ROOM;

void create()
{
	set("short","���뤧��");
	set("long", @LONG
�o�Ӧa�赹�A���Pı�A�P�s�H�c������L�a��۷��P�C�]���o
�̤����|�B�����T�T��⪺�H�򧤦b�@�_�A�Ʀ����Aı�o���I�����C
��Ӧ��B�D�O��ڱڤH�̥�ͪ��a��A�u���b�o�̱ڤH�̤~�|��U��
�`��ۧڪ��Y��n�D�ӱo�짹�������P�C�j�a�|�b�o�̱Ի��ۤv�b��
��W���Ҩ��һD�A�t�~�p�G���ڤH�b�樫����ɹJ��@�ǳ·Ф]�|�b
�o�����X�ӡA��L�H���|�ɥi�઺�Q��k���L�ѨM�C

LONG
	);
	set("exits",([
  "north" : __DIR__"room5.c",
  "west" : __DIR__"room3.c",
]));
    set("objects",([
         __DIR__"npc/shopman" : 1,
//__DIR__"box1" :1,
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
	call_other( "/obj/board/moon_room4_b", "???" );
}

