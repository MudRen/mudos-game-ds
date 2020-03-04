// Room: /u/s/suez/tsing-yu/map_8_6.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
    �ѳo�̩��n�A�@���j�󪽪��q���n�䪺�l�ȪL�A���M�l�ȪL���۳\�h
�޲����ǻ��A���O�ѩ�_��g�ꪺ�X�{�A�\�h�H�K��ܤF�ѫn�䪺�l�ȪL
¶���q���ʫ��C�H�e���R���n�j��]�]�����x�F���֡C�۱q�����j�Ԥ���
�A�Ҧ��~���K�H�s���H�n�����I�ӹ�ܥ_��ӨӪ��ĤH�A�[�Ӥ[���A�o��
�H�n�N�ܦ��r�ɥj���~���ҩ~���a�A�ݵ۳o�̦w�M�֧Q���ͬ��A���p��
�᷽��¾몺�����A���H���T�]�Q�b���w�~�A�L�ۥ��Z���O�ּ֪��ͬ��C


LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "north" : __DIR__"map_7_6",
  "east" : __DIR__"map_8_7",
  "northwest" : __DIR__"map_7_5",
  "west" : __DIR__"map_8_5",
  "northeast" : __DIR__"map_7_7",
  "south" : __DIR__"map_9_6",
]));

	setup();
	replace_program(ROOM);
}
