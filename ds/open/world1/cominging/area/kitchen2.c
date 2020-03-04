#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "�p�Ф��ܮw");
	set("long", @LONG
�f�d�f��..�A���}�F���I��������A�i�F�ӡA�o�����M���`�֦��H
�X�J�A�o�]�S���p�����ǹСA�a�W�\�ۤ@�U�U���̳U�A�b�̳U�W�٦��@
�ǯ}�}�A�j���O�Q�ѹ��ҫr���A�b���Ǧ��@�i��l�A�W�����۫ܦh����
����G�i�H���ʡC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"kitchen.c",
]));
	set("light", 1);
	set("no_clean_up", 0);
	create_door("out","���","enter",DOOR_CLOSED);
	set("item_desc",([
  "����" : "�`�����@������A�b���멳�ݦ��Ǫ��ݪ��C��A���G�i�H���ʡC\n",
  "�̳U" : "�̳U�W���@��諸���ΡA�O�H�ݤF�Ԥ���Q�n�c���@�n�R�_�ӡA�A�`�N��̳U���٦��@�i��l�C\n",
  "��l" : "��l�W�����@�⥻���O���A�i�H�y�L�ݤ@�U�C\n",
  "���O��": HIY" ���C��:
���D�桯  �N�ϱ� , 
�����I��  �����}���J�| ,
"NOR,
  "�N�ϱ�" : HIC+@MENU_ONE

���D��

�N�ϱ�
�Ψ�H����F�R�N���L�����\�A���@�D�����Ʋz�e���L�]�o�^�I
���ơG
�]�|���������^�ϱ�1��

�ը��ơG
���D���B���V�o�U1�j�� ��}1�p�� ������10��

�L�ơG
�վL1�j��

1.�N�c���w��10�����A�M��N�ϱƬ~�b�����A�H180�J�N��30�������X�C
2.�������~�b�A��J�G�ľ����A�A�J�վL�B���D���B���V�o�B��}�A
  �@�_�H�G�ľ����áA�Y��������C 
3.�N�ϱƤ��}�A�O�W������Y�i���ΡC

MENU_ONE
+NOR,
  "�����}���J�|" : HIC+@MENU_TWO

�����I

�����}���J�|
�N��R����������ä�Ħb�f�̡A���L�]�o�^�k�ڪ�����......

���ơG
�����J�|2���]��1�����p�^���ꪴ����]�j�����^15��
����1/2�M               �N�Q�B��2���]4g�^
�ե��J�O100g            �����}��2�j�� �A���o2 1/2�M

�@�k�R
1.�ǳƤ@��6�T���߫��Ҥl�A�Q�@�h�O�A���A�ƥΡC 
2.������h���A�N��ä�鴲��A����C���A�v���d2�j�͡A
  ��l���h��J���}�����A�w�X�����A�M��A�o�h��ä�C
3.�ե��J�O���H�A��J���������A�H�p�����N�ơA�����C
4.�N�Q�B�����H�ֳ\�N���w�n��A�J�@�k3���դáA�Ϩ�ĤơA�A��J�}���ͩէ��áC
5.�A���o�����éʵo�w�]�Y���_���J����A���o���y���|���U���F
  �Y���o�Ӥ[�A���J���W�����o�|���������A�h�����ʵo�w�^��A
  ���⦸�դJ�@�k4���A�A��J�w�d����ä�A���դ@�U�A�M��N�@�b���q�ˤJ�Ҥl���A
  �\�W�@����Ҥl�p�������J�|�A�A�N�Ѿl���q�����ˤJ�A
  �̫�A�Q�@�h�P�Ҥl�P�j�p�������J�|�A�åH�O�A���]�n�C
6 �N�@�k5���J�N��w���A�ݦB�w����X�A�M��ηż����������e����t�A
  �Ϩ�ѭ�A�A�˦���L�l�W�A���i�H�S�@�ǥե��J�O�A�μ��Ǫ�����ä�˹��C

MENU_TWO
+NOR,
  "�����}���J�|���ּ֤p����" : HIG+@MENU_THREE
  
�ּ֤p����G
�����}�ߥi�b�⦳�������@�ة����R��C�i�ϥΪw���������ꪴ����A
���L�Y�ĥεL�A�Ī��s�A���������ӻs�@���t��A�f�P�|��ΡF
���ߤH�h��������ت����A���챡�H�`�ɡA�A�ˤⰵ���߷R���H�Y�A���e�ʤ��ʳ�I

MENU_THREE
+NOR,

]));
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me,kitchenb1,*obs;
	me = this_player();
	kitchenb1 = load_object(__DIR__"kitchenb1.c");
	if( arg !="����" ) return notify_fail("�A���F�i�H��������~���G�S����i�H�F�D�D\n");
	message_vision("$N���ʤF�@�U����A��M���A�}�U�@�_�A���M�X�{�@�Ӷ}�f�A�j�a�����F�U�h�F�C\n",me);
	obs = all_inventory(environment(me));
	for(int x=0; x<sizeof(obs);x++) {
		if( !living(obs[x]) )continue;
		obs[x]->move(kitchenb1);
	}
	return 1;
}
