#include <room.h>
inherit ROOM;
void create()
{
 set("short","���U����");
 set("long",@LONG
�o�N�O���U���������F! �o�䦳�@�Ǧ���H�h�b�o�䶼���ͤѤU,
�N�s�׭^��. ���L���e���X��A�n�����S���L, �j���u�O�b�j�N�j�N
�}�F�a. ���U�����������@�Ӥ�άW, �W�W���F�T��M�M�T��C, ��
�O����b�B�}���B�f��B���q�B�}���B�ݦ夻��ѤU���L, �����O�u
���٬O����, ���A�`ı�o�ݤ@�ݤ]�n��. ���@���ӱ詹�W��.
LONG
    );
 set("exits",(["north":__DIR__"inroom65",
                "west":__DIR__"inroom67",
                "east":__DIR__"inroom66",
               "south":__DIR__"inroom4",
                  "up":__DIR__"inroom8",]));
 set("item_desc",([
	"��b":"�o�O�W�N�M�ȡu���l�M�v�����ҥΪ����W�L��,
���{�b�Q�`�`�����b��W, ���ޤ]�ޤ��}�F.\n",
	"�}��":"�o��M�M������, ���M�W�o�Ѯt����, �Q�����
�@�w�۷��h! ���{�b�Q�`�`�����b��W, ���ޤ]�ޤ��}�F.\n",
	"�f��":"�A�@����h, �N�g�W�F�o��M, �����o�۲H�H��
���f����, �O�����H�Pı�ܯ��t���@��M, 
���{�b�Q�`�`�����b��W, ���ޤ]�ޤ��}�F.\n",
	"���q":"�o��C���C�b���k�s��, �p�P�{�q����!
���{�b�Q�`�`�����b��W, ���ޤ]�ޤ��}�F.\n",
	"�}��":"�ǻ����C�O��~�u�}���P�a�v�B�����}�����C,
���{�b�Q�`�`�����b��W, ���ޤ]�ޤ��}�F.\n",
	"�ݦ�":"�A�@�ݨ����C, ���W�Q�_��~�︹�ݦ�C�ȡy�ڵL�ġz
���u�f�L�ڡv, �b�Q�K�~�e�F�ʤ@��, �T�������C�����U�����⦺�˵L��!
���{�b�Q�`�`�����b��W, ���ޤ]�ޤ��}�F.\n",
]));
 set("no_clean_up", 0);
 set("light",1);
 setup();
 replace_program(ROOM);
}
