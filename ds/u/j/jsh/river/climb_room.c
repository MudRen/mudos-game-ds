#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�����۶�");
        set("long", @LONG
�������L���۶��A���������A�ݦ��õL���Y�A�s���O����@�ӥ@�ɪ�
�q�D�H�P�L���Ů�ɤl���M���Ȩ�ݪ����I��ӳo�Ӭݦ��۶����F��A�N�O
�]���P�D���Ů𿱵ȩҾɭP�A�S�Q�@�ѵL�Ϊ��O�q�Ҳo�ޡA�y�N�F�o�ӥO�H
�ɹɺ٩_�����[�C���W�۶�(climb)�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"street5",
]));
set("light",1);

        set("outdoors","land");

        setup();
}
int init()
{
    add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object me=this_player(),ball;
    if(!me) return 0;
    if(me->query_temp("be_inflation") != 1)
    {message_vision(HIW"$N�Q��W�۶��A�S�Q��o���F�ӪšI\n"NOR,me); return 1; me->start_budy(2);}
    else{message_vision(HIW"$N�C�C��W�F�۶��A�@�B�B���V�W���E�E\n"NOR,me); call_out("goup",1,me); return 1;}
}
void goup()
{ 
     object me=this_player();
     tell_object(me,"�A�V�O���C�C���W���E�E�Pı��Ů�U�ӷU�}���E�E\n");
     me->move(__DIR__"room1"); 
     me->delete_temp("be_inflation",1);
     tell_room(environment(me),me->query("name")+"�q�۶����F�W�ӡC\n",me);
     return;
}
