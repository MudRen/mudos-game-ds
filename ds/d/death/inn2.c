// This is a room made by roommaker.

inherit ROOM;

void create()
{
        set("short", "�©�");
        set("long", @LONG
�θ̬۷�N�M, �~�����@���٤��ɦa�q�b�}�۪����_�ƶi��,
�a���W���ۤ@�ǯ}�ª����~, ���L���q�~��w�g�L�k����X���O��
����F��F. ��W(wall)��ۤ@�Ǽ�󪺦r��, �𨤪��@���OŢ��
����a�o�X�@�}�}�L�z�����~, �]�l�o���Ǧr�ݨӮ�~���޲�.

LONG
	);
	set("exits", ([
	"west" : "/d/death/road1",
	]) );
	set("item_desc", ([
	"wall" : @WALL
�X��A�j�j����o�X�Ӫ��r:
�ڳQ�x�b�o�̤F.... �ڭn�^�a��!!!!!!!!!!!
                      ^^^^
                        �a�ۤv��...
����s�a�ۤv��?!?!? �o�̳s�Ӭ��H���S��...

�ݨ�A�ۤv�ɰݤ@�U�a... �ۤv�H���|������������.. 
                                    ^^^^
                                 �A... �T... �w?!?!
��.. 
WALL
	]) );
        setup();
        replace_program(ROOM);
}
