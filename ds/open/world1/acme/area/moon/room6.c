inherit ROOM;

void create()
{
	set("short","�a�뤧��");
	set("long", @LONG
��A�i�J�o�@���Ъ��ɭԡA�A�o�{��ж��|��������観�\�h��
�Z�\�ۦ��P�U�������\�ߪk�A�o�̷Q���N�O��ڱڤH����m�ۤv�Z�\
���a��F�C����A�b�ݸԵ���W�Ҩ�e���Z�\���ɡA��M���@�ѴH��
�q�A������j�L�C�A�^�Y�@�ݡA�b�A���|�P�X�{�F�ܦh���H�M�F�]�C
�b�ƭӰ��H�����A���@�ӥk�ⴤ�ۤ���C�A����뤧�Z���B���q�Ѧ�
���C�A����n�_���V�B���a�L�h�A�Q�n���J���ݭӥJ�ӡC

LONG
	);
	set("exits",([
  "north" : __DIR__"room7.c",
  "east" : __DIR__"room3.c",
]));
  set("objects",([
     "open/world1/npc/goldman" : 10,
//__DIR__"box1" :1,
]));
	set("item_desc",([
  "�B��":@ICE

�b�A���e�O�@�L�Ѥd�~�H�B��ű���������J��(KenwayStatue)�C
�L�O���ڤ��̳ǥX���Ԥh�A�~�֮ɴ����P�ڪ��|�B�����C�]���L
�b�ڤ��ߥ\�L�ơA�ڪ��S�O�ʥL��-�s��X-���X�D�A�ì��L�b��
�سy�@�L�J���C�O�b�o�ؽm�\���ڤH�A�C���ݨ�o�L�J�����ɭ�
�A�i��K�|�o�M�ӥ͡C
                              
ICE
,
  "���":@WALL
 
�o�ب�F�ܦh�������Z�\�ۦ��Τ��\�ߪk�]�A

�e������---  �����C�k(sorgi_sword) �g�ۤC�B�Z(fogseven) �ݤ�ߪk(moon_force)
�K������---  �j�j�Z(da-fork)       �K�����k(bagi_fist)  �K���ϰ�(horse-steps)
���Z�Ъ�---  ���Z�C�Z(godsword)    �P���g�ܨB(mirage-steps)
�ⶳ�x��---  �L�Ч��k(wuchen-staff)  

WALL
,
]));

	set("light",1);
set("no_goto",1);
	setup();
        call_other( "/obj/board/moon_room6_b", "???" );
//	set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
}

