#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"�x�ë�"NOR);
        set("long", @LONG
�o�N�O�o��L�W�����x�ëǡA�̭��\�]�۳\�h�L���A���o�ǧL���~�A
�n�������@�h�ݤ������O�@�h�A�u�n�A�@�hĲ�N�A�N�|�Q�ˮ`��ܨ��˦�
�C�t�~�A�e�観���d�l�A���Y�n����m�ۤ@�ӧL���A�����ӧL��������
�䥦���L�����P�A���@�����H�Q�h���ըϥγo�ӧL��������C
LONG
        );
        
        
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"room13",
]));  
  set("item_desc", ([
  "�K�O" : "�o�̦��@�Ӳ��W�䧮���K�O�A�A�i�H�ԩԬ�(pull)�ݦ�����F��C\n",
]));
   set("no_clean_up", 0);
        setup();
}     

void init()
{
        add_action("do_pull","pull");
}

int do_pull(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="�K�O" ) return 0;
        message_vision(HIW"�A �� �} �F �K �O �W �� �� �A �� �M �� �^ �F �U �h!! \n"NOR,me);
        me->move(__DIR__"q5-1");
          tell_room(environment(me),me->query("name")+HIW"���M�q�ѤW�^�F�U�ӡC\n"NOR,me );
return 1;
}

