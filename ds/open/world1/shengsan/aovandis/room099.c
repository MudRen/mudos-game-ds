// ���Z�}��
// LV 1~50
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���Ю{§��"NOR);
	set("long", @LONG
�b�A���Y���W���γ��O�ѱm�⪺�����ҫ���Ӧ��A�ݤ����o�ǹϮש�
�N���t�N�C�b�e�観�@�ӻO�l(Estrade)�A �Ӯ���O��ƪ�����A��W
�o�S����m���󪺪��~�A�u���X�����륿�b�U�N�ۡC
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room092",
            ]));

	set("no_clean_up", 0);

	set("light", 1);

	set("item_desc", ([
		"estrade":"�o�ӻO�l�W��ۤ@���S����W���p��(Book)�C\n",
		"book":   "�W���g���F�K�K�³ª���r�A�ӳ����A���檺�O���Ǥ�r�n���ä��ӻ{�ѧA�C�C\n"
     ]) );

	setup();
}

void init()
{
	add_action("do_open","open");
}

int do_open(string arg)
{

	if(!arg) return 0;
	if( arg != "the book" )	return 0;
	write("Yes...��...��...�A���}�F�o����...�]��ۥ��}�F�A����d�G�h�W���H�ͤF...\n"
		"�A�P�즳�ز��W�������P���{��A�����W�F...\n");
	return 1;
}