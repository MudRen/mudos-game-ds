// Room: /u/m/mulder/area/naboo/jungle/jungle.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"�˪L�p��"NOR);
	set("long", @LONG
�o�O��Naboo�̤j���˪L�A�ǻ��˪L���Y���ܦh�_�áC���O���ܦh�H�i
�J���̡A���G�����X�ӡC���O�o�̤S���t�@�ӻ��k�O�A���̦��@�Ǯ��Ȫ���
���N�i�J�����I�̱����C����˪L���æ�����F��O�H�{�b�]�S���H�i�H��
�w����A�C���B���@�ӧi��(sign)�C
LONG);
	set("exits", ([ /* sizeof() == 2 */
  "west" : "/u/m/mulder/area/naboo/gate3",
  "east" : __DIR__"jungle2",
]));
	set("world", "undefine");
	set("item_desc",([
	"sign":"�o�̥i�H�ѵ����aSAVE,�קK���a�b�˪L�g��!\n",
	]));
	set("outdoors","forest");
	set("valid_startroom", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
