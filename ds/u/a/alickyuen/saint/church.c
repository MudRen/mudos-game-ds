//updated 26/12
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"ST�DChurch�ISt.Rolence"NOR);
	set("long", @LONG
�o�̴N�OSaint���ߤ@�@�����j�����j�а�A���M�o�̤v�g�}��ݯʡA
���O�b�t������g�X�F�@�D�۵M���C�ݨ�t���O�������e�A�O�A���ߥ��R
�F�\�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dst2",
]));
set("objects", ([
__DIR__"npc/father.c" :1,
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "�t����" : "�@�L�t�����A�A�i�H�V����ë�C\n",
]));
set("light",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
 add_action("do_pray","pray");
}
int do_pray(string arg)
{
        object me;
        me=this_player();
if( me->query_temp("readdi") )
{
        if (arg != "�t����") 
                   return 0;
        else {
                   message_vision(HIW"$N���b�a�W�A�ۤߦa�V�۸t������ë�A��M$N�Y�W�x�_�@�������A�����@�{�N�h��t�@�a��F�C\n\n"NOR ,me);
                   me->move(__DIR__"church2");
                   tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�C\n",me);
me->delete_temp("readdi");
me->set_temp("readdia");
           return 1;
                 }
}
}

