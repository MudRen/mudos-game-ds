// updated 26.12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST�DChurch�ISt.Rolence"NOR);
	set("long", @LONG
�����ɴ���A�A�Ө�F�@���s���ж��C����������A���@�ؤ��w���Pı
�t�A���H�ӷX�A�ӧA�Sť��@�ǥs�n�q�n���ǨӡA�t�A��[�`�ȡC�o�ˤ���
���@�L[1;32m��v����[0m�A�����@�˪F��Q���_�ǡA���N�O��v�������k����F�X��
�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"church4",
"out" : __DIR__"church",
]));
set("light",1);
	set("item_desc", ([ /* sizeof() == 2 */
  "��v����" : "�A�ݨ�[1;33m��v��������[0m���F�X��, �A�i�H���ծ��N(touch)������C\n",
]));
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}
void init()
{
add_action("do_touch","touch");
}
int do_touch(string arg)
{
        object me;
        me=this_player();
        if (arg != "��v��������" && arg != "hand") 
                   return notify_fail("�o�̨S���o�ӪF��i�N�C\n");
        else {
                   message_vision("$N�N�F�@�U��v��������C\n��M�a�W��F�Ӥj�}�A$N���F�i�h�C\n\n" ,me);
                   me->move(__DIR__"church3");
                   tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�Cn",me);
           return 1;
                 }
}
