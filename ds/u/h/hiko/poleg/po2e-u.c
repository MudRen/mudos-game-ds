#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
�o�̮������������@�ӱM�����H�ۻs�Ʋz���p�СA�~�����ɤ@�ǽ�
�ܪ��n���A�o�̭��ٺⰮ�b�A�ܤ֤��|�L���ż�A�e�誺���l�ݰ_�ӤQ
���S��A�]���H�Pı���I���ġA�i�H�ۤv�ʤ�@�Ʋz�F�A���L���G���I
�e���A�ݨӤ��l�ū׷����A�Q�����O�Z�~�C
LONG
        );
set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"po2e",
]));
        set("objects",([
  __DIR__"npc/item/fire-furnace":1,
]));
        set("item_desc",([
  "���" : "�@��Q�����U�N�۪�����A�ټA�A�԰Ԫ��b�T�C\n",
]));
        set("light", 1);
        set("no_clean_up", 0);
        set("no_recall","�Y���ӫҤj�A���]�L�k��....");        
        setup();
}

int valid_leave(object me, string dir)
{
        if( dir!="down" )return ::valid_leave(me, dir);

        if( dir=="down" && me->query_temp("cook") >= 1)
         me->add_temp("cook",-1);
        return ::valid_leave(me, dir);
}



