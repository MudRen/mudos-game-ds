#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "�����e");
        set("long", @LONG
test .. 
LONG
        );

        set("item_desc",([
    "����":"�@�I�����Ať�o�઺�H���A���I���U�h . . . �i��|�o�ͩ_�Ǫ��ơA�u�O�S�H�����}�F�C\n",
        ]) );
        set("exits", ([ /* sizeof() == 4 */
          "east" : __DIR__"room_7", 
          "west" : __DIR__"room_5", 
          "north" : __DIR__"room_16",
          "south" : __DIR__"room_17",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="coin in ����") return 0;
        if(!objectp(ring=present("coin",me) ) )
                return notify_fail("�A�S������ ? \n");
        message_vision(HIY"$N��F�@�I�j��������̡A�������j�� : @#$%^&*$%^&*#$&*@#(�����D�b������)�C\n",me);
     message_vision(HIW "�������M�z�X�ե��A�N$N�ιγ�� . . . �����F�I�I\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"�A�^��Y�s���F �C\n");
        me->move(__DIR__"room25");
     tell_room(environment(me),me->query("name")+"���M�X�{�b�o�̡C\n",me);
        return;
}

