//updated 26/12
//debug -By Tmr- 2000/2/20

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"ST�DChurch�IGod of moon"NOR);
        set("long", @long
�Ө�o�̡A�S�O�@�f�s�����H�A���̥��n���N�O�n���I���e���ĤH�a
�T�A�b���[�~���ݨ�o�̪������]���@�L��v�����A���o�L����o�S����
�X�ӡC�䦸�A�S�o�{�b�a�𪺦�m���@��÷���A�A���G�i�H�a�L�^��W��
�F�C
long
);
        set("item_desc", ([ /* sizeof() == 2 */
        "÷��" : "�@���ʲʪ�÷�A�A�i�H�Q�Υ��k���X�h�C\n",
        "��v����" : "�@�y�������۹�,���@�I���i��ĳ....\n",
        ]));
        set("objects", ([ /* sizeof() == 4 */
        __DIR__"npc/goda" : 1,
        ]));
        set("light",1);
        setup();
}

void init()
{
        add_action("do_climb","climb");
        add_action("do_search","search");
}
int do_climb(string arg)
{
        object me;
        me=this_player();
        if (!arg || arg != "÷��") 
                   return 0;
       message_vision(HIR"$N�j�O����÷���A�C�C�a���X�o�̡C\n"NOR ,me);
       me->move(__DIR__"church2");
       tell_room(environment(me),me->query("name")+"��M�X�{�b�A���e�C\n",me);
       return 1;
}

int do_search(string arg)
{
        object gun;
        object me;
        me=this_player();
        if( !arg || arg != "��v����")          return 0;
        if( !me->query_temp("killgoda") )       return 0;
        message_vision("$N�b��v���������_�̥J�ӥJ�Ӫ��j�M...\n"  ,me);
        if( query_temp("get_gun") )
                 return notify_fail("��F�S��A�רs�@�L����...\n");
        message_vision("$N���G�b���_�̧��F�@��j�H�I\n" ,me);
        gun=new(__DIR__"obj/wp/moongun.c");
        gun->move(me);
        me->delete_temp("killgoda");
        set_temp("get_gun",1);      

        return 1;  
}

void reset()
{
        if( query_temp("get_gun") )
                delete_temp("get_gun");
::reset();
}


