#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "��W�e");
        set("long", @LONG
�o�̬O�@���e�s����� , �����٦����s�n , �]���M�ܪ�����
�n , ���O�H���Ѱ���� , ���O . .  �Ҧ����ʪ��������a����
������������[0;7;33m�[7m�[7m�[7mW[0m , �æ��ǲ� . . .�C
LONG
        );

        set("item_desc",([
    "��W":"�@���e���Q�׶ɱת����Y�W�l�A�W���٦��@��p�p���Ĥl�A���G������@�ΡC\n",
        "�Ĥl":"�@��p�p���Ĥl�A�W���٦��i���L������C\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "north" : "/open/world1/wilfred/meadow/room3",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_hold","hold");
}

int do_hold(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="ring on �Ĥl") return 0;
        if(!objectp(ring=present("willow ring",me) ) )
                return notify_fail("�A�S���F�i�H�j��Ĥl�� ? \n");
        message_vision(HIW"$N�N�h�٥ΤO�@��A�N��c�c���M����䪺�Ĥl�A��íí�����C\n",me);
     message_vision(HIW "�h�ٹ��O�ۤF�]�@�ˡA�N$N�u�W�L�a�����Ѫ� . .�I�I\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"�A�j�s�@�n���L�b���h�W���C\n");
        me->move(__DIR__"room");
     tell_room(environment(me),me->query("name")+"�L�b�n�n�����h�W���C\n",me);
        return;
}

