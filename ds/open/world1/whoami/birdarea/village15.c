#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�_����"NOR);
 set("long",@LONG
�A�~�򩹥_��, �o�̨S���b���u��, �N�N�M�M��, ��W�٦�
�X�ӦѤ���, �ѱC�C�b���a, �b�A�����, �O�@��Ѥ~´���֤k
���a, �b�A���F��N�O�Q�U�j�s�����V, �b�A���_���ۤ@��
�j��H�a.
LONG);
 set("exits",(["west":__DIR__"village16",
               "east":__DIR__"village18",
               "south":__DIR__"village13",
               "north":__DIR__"rich1",
              ])); 
 set("item_desc",([
        "�F��γ�":"�A�ªF�誺�γ��ݤF�L�h�A�oı�W���n�����ӤH�H�I\n",
             
    ]));
 set("objects",([__DIR__"npc/oldman" : 1,
                 __DIR__"npc/oldwoman" : 2,
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

void init()
{
   add_action("do_jump","jump");
} 
int do_jump(string arg)
{        
          object me;
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n���W����H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "�F��γ�" && arg != "�γ�") return 0;
        if ( me->query_skill("dodge") >= 60){
        message_vision(WHT"�u��$N�I�i�W�m�\\�[�����\\�A�V�W�@�D�K�������L�v�L�ܤF..\n"NOR ,me);
        me->move(__DIR__"village17.c");
        me->start_busy(2);
        tell_room(environment(me),me->query("name")+"��M�X�{�b�A�����e..\n",me);
        return 1;
        }
        message_vision(HIW"$N�b������è�@�˪����Ӹ��h�A�ݨӬO�\\�O�����A�L�k���W�o�ӫγ��E\n"NOR ,me);
        me->start_busy(1+random(2));
        return 1;
}          


