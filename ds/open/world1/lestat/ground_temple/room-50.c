#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "�o���q�|") ;
        set( "long", @LONG
�����@�a���u��A�᪺��B���O�U���A�o�̦��G�O�q�|�u�H�̥�
�����a��A���@�Ӧ��q�u�����b������ۻy�A�γ\�A�i�H�q�L�f��
ť�o�@�ǭ��n�������C
LONG
);
        set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-48",
                  "west" : __DIR__"room-49",
        ]));
        set("objects",([
                   __DIR__"../npc/old_worker" : 1,
                 ]) );
        set("light",0);
        set("item_desc", ([ /* sizeof() == 1 */
        "�u��" : "�u�㪺�᭱���G�õۤ���F��A�A�i�H�N�F�貾�}(move)�ݬݡC\n",
        ]) );
        set("no_clean_up", 0);
        setup();
}

void init()
{
      add_action("do_move","move");
}

int do_move(string arg)
{
       object me;
       me=this_player();
       if(arg != "�u��")
       return 0;
       else {
       	if(this_object()->query("havemove")) 
       	{
       		return notify_fail("�o�Ǥu��w�g�Q�����𨤤F�C\n");
       	}
        
        message_vision("$N�N�u�㲾��@�ǡA�s���W���q�D�]�����S�X�ӡC\n",me);
        set("exits", ([
             "north" : __DIR__"room-48",
             "west" : __DIR__"room-49",
             "south" : __DIR__"room-51",
         ]));
        set("item_desc", ([ /* sizeof() == 1 */
        "�u��" : "�u��Q�H��ê���b�𨤡C\n",
        ]) );
        this_object()->set("havemove",1);
         return 1;
        }
}

void reset()
{
	set("item_desc", ([ /* sizeof() == 1 */
        "�u��" : "�u�㪺�᭱���G�õۤ���F��A�A�i�H�N�F�貾�}(move)�ݬݡC\n",
        ]) );
	set("exits", ([ /* sizeof() == 2 */
                  "north" : __DIR__"room-48",
                  "west" : __DIR__"room-49",
        ]));
        this_object()->delete("havemove");
	::reset();
}
