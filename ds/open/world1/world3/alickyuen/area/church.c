//updated 2000/2/20

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
          "�t����" : "�@�L�j�z���J��Ӧ����t�����A�`�Q�H�̥ΨӬ�ë�D�֡C\n",
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
        if (arg != "�t����")  return 0;
        if(!objectp(present("electric note book",me) ) )
                        return 0;
        message_vision("$N���b�a�W�A�ۤߦa�V�۸t������ë�C\n",me);
        tell_room(environment(me),me->query("name")+"���M���������F�C\n",me);
        tell_object(me,"�A�����e���M�X�{�@�D�����A���G�A��F�t�@�Ӧa��C\n");
        me->move(__DIR__"church2");
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�C\n",me);
        return 1;
}


