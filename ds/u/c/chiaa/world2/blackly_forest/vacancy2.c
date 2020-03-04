//u/c/chiaa/world2/blackly_forest/vacancy2.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�L���Ŧa");
        set("long", @LONG
�o�O�L�����@�p���Ŧa,��ꤣ�L�Ƥ�,��ǰ��F�C����,
���ɥi�ݨ����Ƥ������p���ΡA�]�iť�o���s�ζ�,�i�H���樫�b�˪L���H,
�b�o�̼Ȯɱo���!�b�A�F�䦳�@�j�����O,��A�����u�������B�ͤF,
�b�A�e�誺�@�L�����O,�����iť��ǷL���n��!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "southwest" : __DIR__"parting",  //���[��

        ]));
        set("item_desc",([
        "���O":"�@�L�C����O,�ᦳ���د�e�H��L�h�C\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors","blackly_forest");
        setup();
}

void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="���O") return 0;
        message_vision(
"$N��L�F�@�j�������O�C\n",
        me );
        me->move(__DIR__"nivi_entranceway");
        
        tell_room(
        environment(this_player() ),
        me->query("name")+"��L���O,���F�L�ӡC\n",me
);
        return 1;
}
