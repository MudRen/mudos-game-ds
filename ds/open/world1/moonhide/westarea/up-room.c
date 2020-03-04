#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "��W�e");
        set("long", @LONG
�o�̬O�@���e�s�����A�����٦����s�n�A�]���M�ܪ�����
�n�A���O�H���Ѱ�����A���O�Ҧ����ʪ��������a���쥿����
�����ڡu��W�v�A�a�W�٦��X���_�����h�١A�ᬰ�ǲ��C
LONG
        );

        set("item_desc",([
                "��W":"�@���e���Q�׶ɱת����Y�W�l�A�W���٦��@��p�p���Ĥl�A���G������@�ΡC\n",
                 "�Ĥl":"�@��p�p���Ĥl�A�W���٦��i���L������A�A�i�H�ոծM�b�ۤw�W(hold �Ĥl)�C\n",
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
    object me;
        me=this_player();
 
        if(me->is_busy() || me->is_fighting()) 
                return notify_fail("�A�����ۡC\n");
        if(!arg || arg!="�Ĥl") return notify_fail("�A�Q�n�M����H\n");
        message_vision(HIW "$N�N�c�c���M����䪺�Ĥl�A��íí�����C\n",me);
        message_vision(HIY "��W���M�F�_�@�ѱۭ��A�N$N�u�W�L�a�����ѻڡI�I�I\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{
        tell_object(me,"�A�j�s�@�n���L�b���h�W���C\n");
          me->move(__DIR__"way4");
        tell_room(environment(me),me->query("name")+"�L�b�n�n�����h�W���C\n",me);
        return;
}

