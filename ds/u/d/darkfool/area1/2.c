// Room: /u/d/darkfool/area1/2.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�A�����b�s�մ������F��V�D�n�j��W�A��D�ⰼ�ɬO�@�ӭӪ�
�ݻs�Φ��U������Ϊ��A�Y�O�J�Ӥ@�I�[��A�A�|�o�{���̤W������
�ۤp�p��HANS�ӼСC�o�ǪF��OHANS���ΥX�~������޳t���ΡA�ݨ�
�o��̪��~���X�G�M�@�ⳣ�O�H�����a�A�γ\��HANS�t�d�o�̪��q�~
�o�i�����a�C�F�褣���B��������̨�L�ؿv�~�����p�Τl�A�����O
���ݩһs�A�ݨӹ��O�Τ��Y�ئ����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"1",
  "east" : __DIR__"3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
