#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ݶ���");
        set("long", @LONG
�A���b�@�B���ݶ���W�A�}�U�򪺬O�ιΥժ�᪺�����A�A�]���M��
�H���i�௸�b���W�A�o���T�O�Ӥ��Ѥ��g�C���ݶ��詹�W�i�H�q������
�s���A���U�O�B���x�A�i�H���^(jump down)��a���C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "up" : __DIR__"way4d",
]));
        set("no_clean_up", 0);
        set("outdoors", "land");
        set("current_light", 1);

        setup();
}

int do_jump(string arg)
{
    object me;
        me=this_player();
 
        if(me->is_busy() || me->is_fighting()) 
                return notify_fail("�A�����ۡC\n");
        if(!arg || arg!="down") 
                return 0;
        message_vision(HIW "$N���F�n��������A���W��������N���U���h�C\n"NOR,me);
        me->start_busy(2);
        me->move(__DIR__"up-room");
        return 1;        
}


void init()
{
        add_action("do_jump","jump");
}

