// Room50.c

inherit ROOM;

void create()
{
        set("short","�i������j");
        set("long", @LONG
�A�@��o�̴N�Q�a�W�_�Ǫ��F��̭ˡA���Y�@�ݭ�ӬO
�U�ؽm�߻��\������A�k�観�ӮѬ[�W���\���F�U���U����
���\�Z�ǥ���A�ݪ��M�`���ɭԡA���ǫo�X�{�F�d�U���¼v
�]��ۧA�A��A��ı�o�_��ɥL�o�{���i�D�A�G�i�A�����\
�٤���a�A���L�g�L�ڪ�����|���A��F�`��!!�C��H�ܱo
�N�a �f�c �f�X �f�X �f�X ����a���F�_�� :O�j
LONG
        );
        set("exits", ([
                "east": __DIR__"room25",
        ]));
        set("objects",([
                "/open/world1/npc/goldman3" : 1,
		__DIR__"item/goldman1" : 1,
        ]));
        set("light",1);
set("no_goto",1);
        setup();
}
