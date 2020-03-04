// Room: /u/s/suez/grave/kiosk.c

inherit ROOM;

void create()
{
	set("short", "���F");
	set("long", @LONG
�@���Q���{�����]�򪺳��F�A�X���\���Ƹ��b�a�W�A���j�L�ɵo�X
�F�F���n�T�A�����@�ӥۮ�A��W�\�F�ӴѽL�A�����ӥ۹��H�Φa�W��
�F�@�|�|���ѡA�F�W�W���ֵ��k�a�l�A�S���s����R�A�֤��G

�i  �����צp��  �M�C���p��  �鵧���C�B  ���O�M����  �j

LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "�ѽL" : "�ѽL�W�¥ը�l�����A�ݰ_�ӳ��p�@�T�s���A�ӫD�C�ީ��i�����ͤ��a�C
",
  "��" : "�ݤ@�ݳo�ǮѡA���G�Ѥl�ʮa�A�֮ѩ�§�˼˳����A�˼˳��ʡC
",
]));
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 1,
]));
    set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"path_1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
